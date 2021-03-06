#include <iostream>
#include <climits>


using namespace std;

// https://stackoverflow.com/questions/589575/what-does-the-c-standard-state-the-size-of-int-long-type-to-be
int main() {
    cout << "Bits in a byte: " << CHAR_BIT << endl;
    cout << "Bytes in an int: " << sizeof(int) << endl;

    // https://stackoverflow.com/questions/16501091/detect-ones-or-twos-complement-architecture-in-c
    if (-1 == ~0) {
        cout << "Using two's complement" << endl;
    } else {
        // ~0 will become something like -0
        cout << "Using one's complement" << endl;
    }

    if ((-4 >> 1) == (-4 / 2)) {
        cout << "Using arithmetic shift" << endl;
    } else {
        cout << "Using logical shift" << endl;
    }

    cout << endl;

    // https://stackoverflow.com/questions/7622/are-the-shift-operators-arithmetic-or-logical-in-c
    // For my current implementation (HP laptop) it looks like left shift
    // always does a logical shift, but right shift does arithmetic shift
    cout << (1 << 30) << endl;
    cout << (1 << 31) << endl;
    cout << ((1 << 31) >> 1) << endl;
}

