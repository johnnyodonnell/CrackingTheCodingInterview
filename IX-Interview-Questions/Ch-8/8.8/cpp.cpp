#include <iostream>
#include <algorithm>


using namespace std;

void print_permutations(const string& str, const string& new_str) {
    if (str.empty()) {
        cout << new_str << endl;
    } else {
        char prev_chr = 0;
        for (int i = 0; i < str.length(); i++) {
            if (prev_chr && (prev_chr == str[i])) {
                continue;
            }

            auto str_copy = str;
            str_copy.erase(i, 1);

            auto new_str_copy = new_str;
            new_str_copy.push_back(str[i]);

            print_permutations(str_copy, new_str_copy);

            prev_chr = str[i];
        }
    }
}

void print_permutations(const string& str) {
    auto str_copy = str;
    sort(str_copy.begin(), str_copy.end());
    print_permutations(str_copy, {});
}

int main() {
    print_permutations("abc");
    cout << endl;
    print_permutations("abcdef");
    cout << endl;
    // Permutations contain duplicates
    print_permutations("johnny");
}

