#include <iostream>
#include <vector>


using namespace std;

void print_permutations(const string& str, const string& new_str = {}) {
    if (str.empty()) {
        cout << new_str << endl;
    } else {
        for (int i = 0; i < str.length(); i++) {
            auto str_copy = str;
            str_copy.erase(i, 1);

            auto new_str_copy = new_str;
            new_str_copy.push_back(str[i]);

            print_permutations(str_copy, new_str_copy);
        }
    }
}

int main() {
    print_permutations("abc");
    cout << endl;
    print_permutations("abcdef");
    cout << endl;
    // Permutations contain duplicates
    print_permutations("johnny");
}

