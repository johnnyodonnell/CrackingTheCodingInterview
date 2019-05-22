#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

/*
 * `track` runs O(n) and `get_rank_of_number` runs O(1)
 *
 * instead `track` could run O(1) and  `get_rank_of_number` could run O(n)
 *
 * The book provides a solution where `track` runs in O(log(n))
 * and `get_rank_of_number` runs in O(log(n))
 *
 * This solution isn't necessarily more optimal than my suggestions, but
 * it should have been noted as an option
 *
 */

using namespace std;

class RankState {
    private:
        unordered_map<int, int> count {};
        unordered_map<int, int> acc_count {};

    public:
        void track(int n) {
            ++count[n];

            acc_count[n] = count[n];

            for (auto pr = count.begin(); pr != count.end(); ++pr) {
                if (n < pr->first) {
                    ++acc_count[pr->first];
                } else if (n > pr->first) {
                    acc_count[n] += pr->second;
                }
            }
        }

        int get_rank_of_number(int n) {
            return acc_count[n] - 1;
        }
};

void rank_from_stream(const vector<int>& stream) {
    RankState state {};

    for (auto i : stream) {
        state.track(i);
        cout << "Rank of (" << i << "):\t"
            << state.get_rank_of_number(i) << endl;
    }
    cout << endl;

    for (auto i : stream) {
        cout << "Rank of (" << i << "):\t"
            << state.get_rank_of_number(i) << endl;
    }
}

int main() {
    // rank_from_stream({1, 3, 1});
    rank_from_stream({5, 1, 4, 4, 5, 9, 7, 13, 3});
}

