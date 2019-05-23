#include <stdio.h>


void reverse(char* str) {
    int len = 0;
    while (str[len]) {
        len++;
    }


    for (int i = 0; i < (len / 2); i++) {
        char tmp = str[i];
        str[i] = str[(len - 1) - i];
        str[(len - 1) - i] = tmp;
    }
}

void run_reverse(char* str) {
    printf("%s\n", str);
    reverse(str);
    printf("%s\n\n", str);
}

int main() {
    char str1[] = "johnny";
    char str2[] = "str";

    run_reverse(str1);
    run_reverse(str2);

    // Segmentation fault
    // https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-string-initialized-with-cha
    run_reverse("johnny");
}

