#include <iostream>
#include <unordered_map>


using namespace std;

/*
 * Runs O(n)
 */
bool is_one_insertion(const string& shorter, const string& longer) {
    bool insertion_found = false;

    for (int shorter_index = 0, longer_index = 0;
            longer_index < longer.length();
            shorter_index++, longer_index++) {
        if (shorter[shorter_index] != longer[longer_index]) {
            if (!insertion_found) {
                insertion_found = true;
                shorter_index--;
            } else {
                return false;
            }
        }
    }

    return insertion_found;
}

/*
 * Runs O(n)
 */
bool is_one_way(const string& original, const string& edited) {
    int original_length = original.length();
    int edited_length = edited.length();
    if (abs(original_length - edited_length) > 1) {
        return false;
    }

    if (original_length == edited_length) {
        bool difference_found = false;

        for (int i = 0; i < original.length(); i++) {
            if (original[i] != edited[i]) {
                if (!difference_found) {
                    difference_found = true;
                } else {
                    return false;
                }
            }
        }

        return difference_found;
    } else if (original.length() > edited.length()) {
        return is_one_insertion(edited, original);
    } else {
        return is_one_insertion(original, edited);
    }
}

void run_is_one_way(const string& original, const string& edited) {
    cout << "Is '" << original << "' one edit away from '" << edited
        << "'? " << is_one_way(original, edited) << endl;
}

int main() {
    run_is_one_way("pale", "ple");
    run_is_one_way("pales", "pale");
    run_is_one_way("pale", "bale");
    run_is_one_way("pale", "bake");
    run_is_one_way("pale", "lape");
    run_is_one_way("Johnny", "johnny");
    run_is_one_way("Johnny", "Johnnyy");
    run_is_one_way("Johnny", "Johnnyyy");
    run_is_one_way("Johnnn", "Johnyy");
    run_is_one_way("Johnny", "Johnny");
}

