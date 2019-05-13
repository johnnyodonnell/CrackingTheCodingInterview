#include <iostream>
#include <unordered_map>
#include <algorithm>


using namespace std;

/*
 * Runs O(n * log2(n))
 *
 */
bool is_unique_no_extra_space(const string& str) {
    string str_copy {str};
    sort(str_copy.begin(), str_copy.end());
    for (int i = 1; i < str_copy.length(); i++) {
        if (str_copy.at(i) == str_copy.at(i - 1)) {
            return false;
        }
    }
    return true;
}

/*
 * Runs O(n)
 *
 */
bool is_unique(const string& str) {
    unordered_map<char, bool> char_exists {};
    for (auto ch : str) {
        if (char_exists.find(ch) != char_exists.end()) {
            return false;
        } else {
            char_exists[ch] = true;
        }
    }
    return true;
}

void run_is_unique(const string& str) {
    cout << "Is '" << str << "' unique? " << is_unique_no_extra_space(str) << endl;
}

int main() {
    run_is_unique("");
    run_is_unique("Johnny is cool");
    run_is_unique("unique");
    run_is_unique("abcdefg");
    run_is_unique("Jay Z");
}

