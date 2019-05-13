#include <iostream>


using namespace std;

string string_compress(const string& str) {
    string compressed {};

    char current_char {str.at(0)};
    int current_char_count = 1;

    for (auto ch : str) {
        if (ch == current_char) {
            current_char_count++;
        } else {
            compressed.push_back(current_char);
            compressed.append(to_string(current_char_count));
            current_char = ch;
            current_char_count = 1;
        }
    }

    compressed.push_back(current_char);
    compressed.append(to_string(current_char_count));

    if (compressed.length() < str.length()) {
        return compressed;
    } else {
        return str;
    }
}

void run_string_compress(const string& str) {
    cout << str << ": " << string_compress(str) << endl;
}

int main() {
    run_string_compress("aabcccccaaa");
    run_string_compress("Johnny");
    run_string_compress("Johnnnnnny");
    run_string_compress("Johnnnnnnny");
    run_string_compress("John");
    run_string_compress("aabcccccaaahhhhhhhhhhhhhh");
}

