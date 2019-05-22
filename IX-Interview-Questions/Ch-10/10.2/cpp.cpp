#include <iostream>
#include <vector>
#include <algorithm>


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

