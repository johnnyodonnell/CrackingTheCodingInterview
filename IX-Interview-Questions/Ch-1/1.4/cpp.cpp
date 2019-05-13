#include <iostream>
#include <unordered_map>


using namespace std;

/*
 * Runs O(n)
 *
 */
bool is_palindrome_permutation(const string& str) {
    unordered_map<char, int> char_count {};
    int unmatched_chars {};

    for (auto ch : str) {
        if (ch != ' ') {
            char_count[tolower(ch)]++;
        }
    }

    for (auto char_pair : char_count) {
        if ((char_pair.second % 2) != 0) {
            unmatched_chars++;
        }
    }

    return unmatched_chars <= 1;
}

void run_is_palindrome_permutation(const string& str) {
    cout << "Is '" << str << "' a permutation of a palindrome? "
        << is_palindrome_permutation(str) << endl;
}

int main() {
    run_is_palindrome_permutation("Tact Coa");
    run_is_palindrome_permutation("Race Car");
    run_is_palindrome_permutation("Race Coa");
    run_is_palindrome_permutation("Johnny");
}

