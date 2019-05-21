#include <iostream>
#include <unordered_set>


using namespace std;

/*
 * Hasing isn't free, so there might be a better solution for this
 *
 */
void print_parens(int n) {
    if (n <= 0) {
        cout << "Nothing to print" << endl;
    } else {
        unordered_set<string> combos {"()"};

        for (int i = 1; i < n; i++) {
            unordered_set<string> new_combos {};
            for (auto& combo : combos) {
                new_combos.insert("(" + combo + ")");
                new_combos.insert("()" + combo);
                new_combos.insert(combo + "()");
            }
            combos = new_combos;
        }

        for (auto& combo : combos) {
            cout << combo << endl;
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        print_parens(i);
        cout << endl;
    }
};
