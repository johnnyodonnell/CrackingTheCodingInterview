#include <iostream>
#include <unordered_map>


using namespace std;

/*
 * Runs O(s + t)
 *
 */
bool check_permutation(const string source, const string target) {
    if (source.length() != target.length()) {
        return false;
    }

    size_t chars_needed = target.length();
    unordered_map<char, pair<int, int>> char_count {};

    for (auto ch : target) {
        char_count[ch].first++;
    }

    for (auto ch : source) {
        auto p = char_count.find(ch);
        if (p != char_count.end()) {
            if (p->second.second < p->second.first) {
                chars_needed--;
            }
            p->second.second++;
        }
    }

    return chars_needed == 0;
}

void run_check_permutation(const string source, const string target) {
    cout << "Is '" << source << "' a permutation of '" << target << "'? "
        << check_permutation(source, target) << endl;
}

int main() {
    run_check_permutation("abcd", "cdab");
    run_check_permutation("abcd", "cdba");
    run_check_permutation("abcd", "abcd");
    run_check_permutation("abcd", "abba");
    run_check_permutation("abcd", "abcdd");
}

