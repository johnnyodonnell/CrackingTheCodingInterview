#include <iostream>

/*
 *
 * This function is checking to see if `n` is a power of 2
 *
 */

using namespace std;

bool mystery(int n) {
    return (n & (n - 1)) == 0;
}

int main() {
    for (int i = -10; i < 11; i++) {
        cout << i << " : " << mystery(i) << endl;
    }
}

