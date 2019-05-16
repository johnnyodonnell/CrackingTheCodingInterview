#include <iostream>


using namespace std;

int bits_away(int a, int b) {
    int diff = a ^ b;

    int result = 0;

    for (unsigned int i = 1; i != 0; i <<= 1) {
        if (diff & i) {
            result++;
        }
    }

    return result;
}

int main() {
    cout << bits_away(29, 15) << endl;
    cout << bits_away(4, 3) << endl;
    cout << bits_away(5, 3) << endl;
    cout << bits_away(-1, 0) << endl;
    cout << bits_away(-1, -2) << endl;
    cout << bits_away(-1, 1) << endl;
}

