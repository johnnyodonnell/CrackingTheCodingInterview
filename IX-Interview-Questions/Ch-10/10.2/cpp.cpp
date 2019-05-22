#include <iostream>
#include <vector>
#include <algorithm>

/*
 * The book provides faster solutions for this
 *
 * The strings don't need to be sorted, they could just use an
 * unordered_map to check if two strings are anagrams
 *
 * The array doesn't need to be sorted. The anagrams just need to be
 * grouped together.
 *
 * I think we could get to a solution of O(n * s)
 * where n is the number of strings and s is the length
 * of the longest string
 *
 */

using namespace std;

class SortedString {
    private:
        string orig;
        string sorted;

    public:
        SortedString(string& c_orig) :orig{c_orig}, sorted{c_orig} {
            sort(sorted.begin(), sorted.end());
        };

        string& get_original() {
            return orig;
        }

        string& get_sorted() {
            return sorted;
        }

        bool operator<(const SortedString& ss) {
            return sorted < ss.sorted;
        }
};

void group_anagrams(vector<string>& vec) {
    vector<SortedString> ss_vec {};
    for (auto& str : vec) {
        ss_vec.push_back({str});
    }

    sort(ss_vec.begin(), ss_vec.end());

    for (int i  = 0; i < ss_vec.size(); i++) {
        vec.at(i) = ss_vec[i].get_original();
    }
}

void run_group_anagrams(vector<string> vec) {
    group_anagrams(vec);
    for (auto& str : vec) {
        cout << str << ", ";
    }
    cout << "\n" << endl;
}

int main() {
    run_group_anagrams({"dog", "cat", "act", "bird", "god", "zebra"});
}

