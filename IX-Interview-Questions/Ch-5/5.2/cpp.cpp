#include <iostream>

/*
 * Not sure why the number should be passed as a double, when a double
 * is often stored as 64 bits and we're supposed to return
 * a string with at most 32 chars
 *
 */

using namespace std;

// https://stackoverflow.com/questions/474007/floating-point-to-binary-valuec
string float_to_binary_str_hack(float flt) {
    string result {};

    union {
        float in;
        unsigned int out;
    } data;

    data.in = flt;

    for (unsigned int i = (1 << 31); i > 0; i >>= 1) {
        if (i & data.out) {
            result.push_back('1');
        } else {
            result.push_back('0');
        }
    }

    return result;
}

// IEEE 754 conversion
// http://class.ece.iastate.edu/arun/Cpre305/ieee754/ie4.html
// https://www.h-schmidt.net/FloatConverter/IEEE754.html
string float_to_binary_str(float flt) {
    string result {};

    if (flt < 0) {
        result.push_back('1');
    } else {
        result.push_back('0');
    }

    int exp = 127;
    while ((flt < 1) || (flt >= 2)) {
        if (flt < 1) {
            flt *= 2;
            exp--;
        } else {
            flt /= 2;
            exp++;
        }
    }

    // exponent takes 8 bits of precision
    for (int i = (1 << 7); i > 0; i >>= 1) {
        if (i & exp) {
            result.push_back('1');
        } else {
            result.push_back('0');
        }
    }

    // add mantissa
    flt -= 1.0;

    for (int i = 0; i < 23; i++) {
        flt *= 2;
        if (flt >= 1.0) {
            flt -= 1.0;
            result.push_back('1');
        } else {
            result.push_back('0');
        }
    }

    return result;
}

void print(float flt) {
    cout << float_to_binary_str_hack(flt) << endl;
    cout << float_to_binary_str(flt) << endl;
    cout << endl;
}

int main() {
    print(0.72);
    print(10.4);
    print(0.085);
}

