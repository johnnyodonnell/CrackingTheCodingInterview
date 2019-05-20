#include <iostream>


using namespace std;

int mult(int n, int m) {
    if (m < 0) {
        return -mult(n, -m);
    } else if (m == 0) {
        return 0;
    } else if (m == 1) {
        return n;
    } else {
        return n + mult(n, m - 1);
    }
}

int main() {
    cout << mult(4, 2) << endl;
    cout << mult(4, 0) << endl;
    cout << mult(4, -4) << endl;
    cout << mult(-5, -4) << endl;
    cout << mult(-5, 10) << endl;
}

