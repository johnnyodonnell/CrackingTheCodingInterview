#include <iostream>
#include <vector>
#include <list>
#include <queue>


using namespace std;

class ToPlace {
    private:
        int val;
        int tries = 0;

    public:
        ToPlace(int c_val) :val{c_val} {}

        int get_val() { return val; }
        int get_tries() { return tries; }

        void operator++() { ++tries; }
};

template <typename T>
bool less_than_both(const T& target, const T& first, const T& second) {
    return (target < first) && (target < second);
}

template <typename T>
bool greater_than_both(const T& target, const T& first, const T& second) {
    return (target > first) && (target > second);
}

template <typename I>
bool is_peak_to_next(I itr, const I end) {
    auto next = itr;
    next++;

    return (itr == end) || ((next != end) && (*itr > *next));
}

template <typename I>
bool is_valley_to_next(I itr, const I end) {
    auto next = itr;
    next++;

    return (itr == end) || ((next != end) && (*itr < *next));
}

template <typename I>
bool can_append(I itr, int val) {
    auto second_itr = itr;
    second_itr++;

    return (less_than_both(*itr, *second_itr, val))
        || (greater_than_both(*itr, *second_itr, val));
}

template <typename I>
bool can_insert(I itr, const I end, int val) {
    auto second_itr = itr;
    second_itr++;

    return (less_than_both(val, *itr, *second_itr)
                    && is_peak_to_next(second_itr, end))
                || (greater_than_both(val, *itr, *second_itr)
                    && is_valley_to_next(second_itr, end));
}

list<int> peaks_and_valleys(const vector<int>& vec) {
    queue<ToPlace> to_place_q {};
    for (auto i : vec) {
        to_place_q.push({i});
    }

    list<int> result {};

    while (!to_place_q.empty() && (to_place_q.front().get_tries() <= 0)) {
        auto to_place = to_place_q.front();
        auto val = to_place.get_val();
        to_place_q.pop();

        if (result.empty()) {
            result.push_back(val);
        } else if (result.size() == 1) {
            if (val == result.front()) {
                ++to_place;
                to_place_q.push(to_place);
            } else {
                result.push_back(val);
            }
        } else if (can_append(result.begin(), val)) {
            result.push_front(val);
        } else if (can_insert(result.begin(), result.end(), val)) {
            result.insert(++result.begin(), val);
        } else if (can_append(result.rbegin(), val)) {
            result.push_back(val);
        } else if (can_insert(result.rbegin(), result.rend(), val)) {
            result.insert(--result.end(), val);
        } else {
            ++to_place;
            to_place_q.push(to_place);
        }
    }

    if (!to_place_q.empty()) {
        throw "Unable to make sequence";
    }

    return result;
}

void run_peaks_and_valleys(const vector<int>& vec) {
    try {
        auto result = peaks_and_valleys(vec);
        for (auto i : result) {
            cout << i << ", ";
        }
        cout << endl;
    } catch (const char* err) {
        cout << err << endl;
    }
}

int main() {
    run_peaks_and_valleys({5, 3, 1, 2, 3});
}

