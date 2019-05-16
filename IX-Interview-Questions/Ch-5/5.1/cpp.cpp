#include <iostream>
#include <climits>


using namespace std;

int insert(const int n, const int m, const int i, const int j) {
    /*
     * Alt mask implementation
     *
    int mask = -1;
    mask <<= j;
    mask = ~mask;
    mask <<= i;
    */
    int mask = INT_MAX;
    mask >>= (31 - j);
    mask <<= i;
    return (n & ~mask) | ((n << i) & mask);
}

int main() {
    cout << insert(1024, 19, 2, 6) << endl;
}

