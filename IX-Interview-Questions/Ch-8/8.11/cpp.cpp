#include <iostream>


using namespace std;

int coin_combos(int n_cents, int highest_allowable_coin) {
    if (n_cents < 5) {
        return 1;
    } else {
        int result = 1;
        for (auto coin : {25, 10, 5}) {
            if ((coin <= n_cents) && (coin <= highest_allowable_coin)) {
                result += coin_combos(n_cents - coin, coin);
            }
        }
        return result;
    }
}

int coin_combos(int n) {
    coin_combos(n, n);
}

void run_coin_combos(int n) {
    cout << n << " cents has " << coin_combos(n)
        << " representations." << endl;
}

int main() {
    run_coin_combos(1);
    run_coin_combos(4);
    run_coin_combos(5);
    run_coin_combos(9);
    run_coin_combos(10);
    run_coin_combos(14);
    run_coin_combos(15);
    run_coin_combos(19);
    run_coin_combos(20);
    run_coin_combos(24);
    run_coin_combos(25);
    run_coin_combos(26);
    run_coin_combos(100);
    run_coin_combos(1000);
}

/*
n: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
r: 1, 1, 1, 1, 2, 2, 2, 2, 2, 4,  4,  4,  4,  4,  6,  6,  6,  6,  6,  9

n: 25,
r: 

*/

