#include <iostream>


using namespace std;

void reverse(char* str) {
    int len = 0;
    while (str[len]) {
        len++;
    }

    for (int i = 0; i < (len / 2); i++) {
        swap(str[i], str[(len - 1) - i]);
    }
}

void run_reverse(char* str) {
    cout << str << endl;
    reverse(str);
    cout << str << "\n" << endl;
}

int main() {
    char str1[] = "johnny";
    char str2[] = "str";

    run_reverse(str1);
    run_reverse(str2);

    // Compiler warns against this in C++, but not C
    // Will cause segmentation fault
    // https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-string-initialized-with-cha
    run_reverse("Johnny");
}

