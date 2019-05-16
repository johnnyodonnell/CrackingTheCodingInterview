#include <iostream>
#include <climits>


using namespace std;

// https://stackoverflow.com/questions/589575/what-does-the-c-standard-state-the-size-of-int-long-type-to-be
int main() {
    cout << "Bits in a byte: " << CHAR_BIT << endl;
    cout << "Bytes in an int: " << sizeof(int) << endl;
}

