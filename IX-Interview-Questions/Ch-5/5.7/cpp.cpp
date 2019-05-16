#include <iostream>


using namespace std;

unsigned int odd_bits = 0;
unsigned int even_bits = 0;

void init() {
    for (int i = 0; i < 32; i++) {
        if ((i % 2) == 0) {
            even_bits |= (1 << i);
        } else {
            odd_bits |= (1 << i);
        }
    }
}

int pairwise_swap(int n) {
    return ((n & odd_bits) >> 1) | ((n & even_bits) << 1);
}

int main() {
    init();

    cout << pairwise_swap(-1) << endl;
    cout << pairwise_swap(0) << endl;
    cout << pairwise_swap(1) << endl;
    cout << pairwise_swap(2) << endl;
    cout << pairwise_swap(-2) << endl;
    cout << pairwise_swap(-3) << endl;
}

