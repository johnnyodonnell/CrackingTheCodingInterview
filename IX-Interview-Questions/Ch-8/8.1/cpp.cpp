#include <iostream>


using namespace std;

/*
 * Runs in O(3^n)
 *
 * Lots of ways to optimize this
 *
 * Suffers from overflow at around n = 37
 *
 */
int ways_up(int staircase_size) {
    if (staircase_size <= 3) {
        return staircase_size;
    } else {
        return ways_up(staircase_size - 1) + ways_up(staircase_size - 2)
            + ways_up(staircase_size - 3);
    }
}

int main() {
    for (int i = 0; i < 20; i++) {
        cout << "Staircase size: " << i << " has " << ways_up(i)
            << " ways up." << endl;
    }
}

