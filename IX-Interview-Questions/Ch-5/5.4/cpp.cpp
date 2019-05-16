#include <iostream>
#include <climits>


using namespace std;

/*
 * Does not handle overflow or underflow. See the last two cases
 *
 * Could handle this by generating the overflow and underflow cases
 * upfront and checking to see if the input matches.
 * Ex:
 * 01111111111111111111111111111111
 * 01111111111111111111111111111110
 * 01111111111111111111111111111100
 * 01111111111111111111111111111000
 * ...
 *
 * and
 *
 * 10000000000000000000000000000000
 * 10000000000000000000000000000001
 * 10000000000000000000000000000011
 * 10000000000000000000000000000111
 * 10000000000000000000000000001111
 * ...
 *
 */
pair<int, int> next_number(int n) {
    if ((n == INT_MAX) || (n == INT_MIN)) {
        throw "Can't compute next min or max for this value";
    }

    if ((n == 0) || (n == -1)) {
        throw "No other numbers have the same number of 1s as this value";
    }

    int next_smaller = 0;
    int next_larger = 0;

    int last_zero_index = -1;
    int last_one_index = -1;

    for (int index = 0; index < 32; index++) {
        unsigned int i = (1 << index);

        if (n & i) {
            if (!next_smaller && (last_zero_index >= 0)) {
                next_smaller = (n - i) + (1 << last_zero_index);
            }

            last_one_index = index;
        } else {
            if (!next_larger && (last_one_index >= 0)) {
                next_larger = (n + i) - (1 << last_one_index);
            }

            last_zero_index = index;
        }
    }

    if (!next_smaller) {
        next_smaller = n << (last_zero_index - last_one_index);
    }

    if (!next_larger) {
        next_larger = (n ^ (1 << 31)) >> last_zero_index;
    }

    return {next_smaller, next_larger};
}

void run_next_number(int n) {
    auto result = next_number(n);
    cout << "Value: " << n << endl;
    cout << "Next smaller: " << result.first << endl;
    cout << "Next larger: " << result.second << endl;
    cout << endl;
}

int main() {
    run_next_number(8);
    run_next_number(5);
    run_next_number(3);
    run_next_number(2);
    run_next_number(1);
    run_next_number(-2);
    run_next_number(-3);
    run_next_number(-4);
    run_next_number(INT_MAX - 1);
    run_next_number(INT_MIN + 1);
}

