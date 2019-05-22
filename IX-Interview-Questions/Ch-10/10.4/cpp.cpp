#include <iostream>
#include <vector>

/*
 * As usual, the book has a much more clever solution for this
 *
 */

using namespace std;

class Listy {
    private:
        vector<int> vec {};

    public:
        Listy(const initializer_list<int> c_init) :vec{c_init} {}

        void push_back(int val) {
            if (val > -1) {
                vec.push_back(val);
            } else {
                throw "Invalid value";
            }
        }

        int at(int i) const {
            if (i < vec.size()) {
                return vec[i];
            } else {
                return -1;
            }
        }
};

// This number requires knowledge about what the average size of a Listy is
const int default_mid = 10;

int binary_search(const Listy& listy, int val, int start, int end) {
    if (start <= end) {
        int mid = start + ((end - start) / 2);
        auto result = listy.at(mid);
        if ((result < 0) || (val < result)) {
            return binary_search(listy, val, start, mid - 1);
        } else if (result == val) {
            return mid;
        } else {
            return binary_search(listy, val, mid + 1, end);
        }
    }

    cout << "Value not found" << endl;
    throw "Value not found";
}

int binary_search(const Listy& listy, int val, int start) {
    int mid = start + default_mid;
    auto result = listy.at(mid);
    if ((result < 0) || (val < result)) {
        return binary_search(listy, val, start, mid - 1);
    } else if (result == val) {
        return mid;
    } else {
        return binary_search(listy, val, mid + 1);
    }
}

int find(const Listy& listy, int val) {
    auto result  = listy.at(default_mid);
    if ((result < 0) || (val < result)) {
        return binary_search(listy, val, 0, default_mid - 1);
    } else if (result == val) {
        return default_mid;
    } else {
        return binary_search(listy, val, default_mid + 1);
    }
}

int main() {
    cout << find({1, 2, 3, 4, 5, 6, 7, 8}, 3) << endl;
    cout << find(
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
            11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
            21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
            3) << endl;
    cout << find(
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
            11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
            21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
            23) << endl;
}

