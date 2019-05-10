#include <iostream>
#include <unordered_map>
#include <list>

/*
 * From p. 70
 *
 */

using namespace std;

class Permutations {
    private:
        struct Node {
            char c;
            int index;
        };

        size_t chars_left;
        size_t max_size;
        list<Node> nodes {};
        unordered_map<char, pair<int, int>> small_char_map {};

    public:
        Permutations(const string small)
            :chars_left{small.length()}, max_size{small.length()} {
                for (char c : small) {
                    small_char_map[c].first++;
                }
            }

        void add_char(char c, int index) {
            if (nodes.size() >= max_size) {
                Node& front = nodes.front();
                nodes.pop_front();
                auto p = small_char_map.find(front.c);
                if (p != small_char_map.end()) {
                    if (p->second.second <= p->second.first) {
                        chars_left++;
                    }
                    p->second.second--;
                }
            }

            nodes.push_back({c, index});
            auto p = small_char_map.find(c);
            if (p != small_char_map.end()) {
                if (p->second.second < p->second.first) {
                    chars_left--;
                }
                p->second.second++;
            }

            if (chars_left <= 0) {
                cout << nodes.front().index << endl;
            }
        }
};

void print_permutations(const string small, const string big) {
    Permutations obj {small};
    for (int i = 0; i < big.length(); i++) {
        obj.add_char(big[i], i);
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

