
#include "config.hpp"

#include <string>
#include <cstdint>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>

int bit_count(uint8_t x) {
	int c = 0;
	while (x) { c++; x &= (x - 1); }
	return c;
}

int distance(const std::string& a, const std::string& b) {
	size_t n = std::min(a.size(), b.size());
	int dist = 0;
	for (size_t i = 0; i < n; ++i) {
		uint8_t xa = static_cast<uint8_t>(a[i]);
		uint8_t xb = static_cast<uint8_t>(b[i]);
		dist += bit_count(xa ^ xb);
	}

	for (size_t i = n; i < a.size(); ++i) dist += bit_count(static_cast<uint8_t>(a[i]));
	for (size_t i = n; i < b.size(); ++i) dist += bit_count(static_cast<uint8_t>(b[i]));
	return dist;

}

static const std::string B64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::vector<uint8_t> base64_decode(const std::string& in) {
    std::vector<uint8_t> out;
    int val = 0, bits = -8;
    for (unsigned char c : in) {
        size_t pos = B64.find(c);
        if (pos == std::string::npos) continue; // skip newlines / padding
        val = (val << 6) + (int)pos;
        bits += 6;
        if (bits >= 0) {
            out.push_back((val >> bits) & 0xFF);
            bits -= 8;
        }
    }
    return out;
}

// ── single-byte XOR scorer (English letter frequency) ────────────────────────
double score_english(const std::vector<uint8_t>& bytes) {
    // Simple frequency score: reward printable ASCII, reward common letters
    static const std::string common = "etaoin shrdlu";
    double score = 0;
    for (uint8_t b : bytes) {
        char c = tolower((char)b);
        if (common.find(c) != std::string::npos) score += 2.0;
        else if (isprint(b))                      score += 0.5;
        else if (b == '\n' || b == '\r')          score += 0.1;
        else                                      score -= 2.0; // penalise non-printable
    }
    return score;
}

uint8_t best_single_xor(const std::vector<uint8_t>& block) {
    uint8_t best_key = 0;
    double  best_score = -1e18;
    for (int k = 0; k < 256; ++k) {
        std::vector<uint8_t> attempt(block.size());
        for (size_t i = 0; i < block.size(); ++i)
            attempt[i] = block[i] ^ (uint8_t)k;
        double s = score_english(attempt);
        if (s > best_score) { best_score = s; best_key = (uint8_t)k; }
    }
    return best_key;
}

// ── main challenge function ───────────────────────────────────────────────────
int crypt::break_repeating_keyxor() {

    // ── verify Hamming distance ───────────────────────────────────────────────
    {
        std::string t1 = "this is a test";
        std::string t2 = "wokka wokka!!!";
        std::cout << "Hamming distance check: " << distance(t1, t2)
            << "  (expected 37)\n";
    }

    // ── 1. read + base64-decode the ciphertext ────────────────────────────────
    std::string raw_b64;
    {
        std::ifstream f("6challange.txt");          // adjust filename as needed
        if (!f) { std::cerr << "Cannot open 6.txt\n"; return 1; }
        std::string line;
        while (std::getline(f, line)) raw_b64 += line;
    }
    std::vector<uint8_t> cipher = base64_decode(raw_b64);
    std::cout << "Ciphertext bytes: " << cipher.size() << "\n";

    // ── 2. find the best KEYSIZE (2..40) ─────────────────────────────────────
    //    Average normalised Hamming distance over 4 block pairs for reliability
    int    best_ks = 2;
    double best_dist = 1e18;

    for (int ks = 2; ks <= 40; ++ks) {
        if ((size_t)(ks * 8) > cipher.size()) break;

        double avg = 0;
        int    pairs = 0;
        for (int p = 0; p + 1 < 8; p += 2) {         // 4 non-overlapping pairs
            std::string a(cipher.begin() + p * ks, cipher.begin() + (p + 1) * ks);
            std::string b(cipher.begin() + (p + 1) * ks, cipher.begin() + (p + 2) * ks);
            avg += (double)distance(a, b) / ks;
            ++pairs;
        }
        avg /= pairs;
        if (avg < best_dist) { best_dist = avg; best_ks = ks; }
    }
    std::cout << "Best KEYSIZE: " << best_ks
        << "  (normalised dist = " << best_dist << ")\n";

    // ── 3. transpose blocks ───────────────────────────────────────────────────
    std::vector<std::vector<uint8_t>> transposed(best_ks);
    for (size_t i = 0; i < cipher.size(); ++i)
        transposed[i % best_ks].push_back(cipher[i]);

    // ── 4. solve each transposed block as single-char XOR ────────────────────
    std::vector<uint8_t> key(best_ks);
    for (int i = 0; i < best_ks; ++i)
        key[i] = best_single_xor(transposed[i]);

    // ── 5. print the key ──────────────────────────────────────────────────────
    std::cout << "Key: ";
    for (uint8_t b : key) std::cout << (char)b;
    std::cout << "\n";

    // ── 6. decrypt and print the plaintext ───────────────────────────────────
    std::cout << "\n--- Plaintext ---\n";
    for (size_t i = 0; i < cipher.size(); ++i)
        std::cout << (char)(cipher[i] ^ key[i % best_ks]);
    std::cout << "\n";

    return 0;
}