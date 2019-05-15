#include <iostream>


using namespace std;

/*
 * Runs O(n)
 *
 */
bool is_rotation(const string& base, const string& rotated) {
    if (base.length() != rotated.length()) {
        return false;
    }

    int rotated_starting_index = -1;
    for (int i = 0; i < rotated.length(); i++) {
        int base_i = 0;
        int rotated_i = i;

        while(rotated_i < rotated.length()) {
            if (rotated[rotated_i] != base[base_i]) {
                goto outer;
            }

            rotated_i++;
            base_i++;
        }

        rotated_starting_index = i;

        outer:;
    }

    if (rotated_starting_index < 0) {
        return false;
    }

    auto found =
        rotated.find(
                base.substr(
                    base.length() - rotated_starting_index,
                    rotated_starting_index));

    return found != string::npos;
}

void run_is_rotation(const string& base, const string& rotated) {
    cout << "Is '" << rotated << "' a rotation of '" << base << "'? "
        << is_rotation(base, rotated) << endl;
}

int main() {
    run_is_rotation("waterworks", "erworkswat");
    run_is_rotation("waterworks", "rkswaterwo");
    run_is_rotation("waterbottle", "erbottlewat");
    run_is_rotation("waterbottle", "erbottlewxx");
    run_is_rotation("waterbottle", "erbottlexxx");
    run_is_rotation("waterbottle", "erbottle");
    run_is_rotation("waterbottle", "xxxxxxxxwat");
    run_is_rotation("johnny", "hnnyjo");
    run_is_rotation("johnny", "ohnnyj");
}

