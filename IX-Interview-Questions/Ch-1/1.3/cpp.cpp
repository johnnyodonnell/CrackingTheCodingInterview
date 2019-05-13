#include <iostream>


using namespace std;

/*
 * Runs O(n)
 *
 */
void urlify(string& str) {
    int copy_index = str.length() - 1;
    int read_index = str.length() - 1;

    while (str[read_index] == ' ') {
        read_index--;
    }

    for ( ; read_index >= 0; read_index--) {
        if (str[read_index] == ' ') {
            str.at(copy_index--) = '0';
            str.at(copy_index--) = '2';
            str.at(copy_index--) = '%';
        } else {
            str.at(copy_index--) = str[read_index];
        }
    }
}

void run_urlify(string str) {
    cout << "Given '" << str << "': ";
    urlify(str);
    cout << str << endl;
}

int main() {
    run_urlify("Mr John Smith    ");
    run_urlify("Johnny O  ");
}

