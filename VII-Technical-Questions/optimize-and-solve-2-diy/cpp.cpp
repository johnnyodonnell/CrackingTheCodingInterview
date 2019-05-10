#include <iostream>
#include <unordered_map>
#include <list>

/*
 * From p. 70
 *
 * O(b + s)
 *
 */

using namespace std;

void print_permutations(const string small, const string big) {
    unordered_map<char, pair<int, int>> small_char_map {};

    for (char c : small) {
        small_char_map[c].first++;
    }

    size_t chars_left = small.length();

    for (int i = 0; i < big.length(); i++) {
        const int k = i - small.length();

        if (k > 0) {
            auto p = small_char_map.find(big[k]);
            if (p != small_char_map.end()) {
                if (p->second.second <= p->second.first) {
                    chars_left++;
                }
                p->second.second--;
            }
        }

        auto p = small_char_map.find(big[i]);
        if (p != small_char_map.end()) {
            if (p->second.second < p->second.first) {
                chars_left--;
            }
            p->second.second++;
        }

        if (chars_left <= 0) {
            cout << (k + 1) << endl;
        }
    }
}

/*
 * O(b * s)
 *
void print_permutations_slow(const string small, const string big) {
    unordered_map<char,int> small_char_map {};
    for (char c : small) {
        small_char_map[c]++;
    }

    for (int i = 0; i < big.length() - small.length() + 1; i++) {
        unordered_map<char,int> current_char_map {small_char_map};

        for (int j = i; j < i + small.length(); j++) {
            auto p = current_char_map.find(big[j]);
            if (p != current_char_map.end()) {
                p->second--;
            }
        }

        for (auto& pair : current_char_map) {
            if (pair.second > 0) {
                goto outer;
            }
        }

        cout << i << endl;

        outer:;
    }
}
*/

int main() {
    print_permutations(
            "abbc",
            "cbabadcbbabbcbabaabccbabc");
}

