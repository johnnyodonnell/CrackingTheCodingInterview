#include <iostream>


using namespace std;

int flip_bit_to_win(int n) {
    int max_len = 0;
    int zero_found = 0;

    int left_len = 0;
    int right_len = 0;

    for (unsigned int i = (1 << 31); i != 0; i >>= 1) {
        if (n & i) {
            right_len++;
        } else {
            zero_found = 1;

            if ((left_len + right_len) > max_len) {
                max_len = left_len + right_len;
            }

            left_len = right_len;
            right_len = 0;
        }
    }

    if ((left_len + right_len) > max_len) {
        max_len = left_len + right_len;
    }

    return max_len + zero_found;
}

int main() {
    cout << flip_bit_to_win(1775) << endl;
    cout << flip_bit_to_win(5) << endl;
    cout << flip_bit_to_win(-1) << endl;
    cout << flip_bit_to_win(-256) << endl;
    cout << flip_bit_to_win(19) << endl;
}

