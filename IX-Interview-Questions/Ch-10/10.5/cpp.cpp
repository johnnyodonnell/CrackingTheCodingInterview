#include <iostream>
#include <vector>


using namespace std;

int binary_search(const vector<string>& vec, string val, int start, int end) {
    if (start <= end) {
        int mid = start + ((end - start) / 2);
        if (val == vec.at(mid)) {
            return mid;
        } else if (vec.at(mid) == "") {
            int i = mid + 1;
            while (vec.at(i) == "") {
                i++;

                if (i > end) {
                    return binary_search(vec, val, start, mid - 1);
                }
            }

            if (val == vec.at(i)) {
                return i;
            } else if (val < vec.at(i)) {
                return binary_search(vec, val, start, i - 1);
            } else {
                return binary_search(vec, val, i + 1, end);
            }
        } else if (val < vec.at(mid)) {
            return binary_search(vec, val, start, mid - 1);
        } else {
            return binary_search(vec, val, mid + 1, end);
        }
    }

    cout << "Value not found" << endl;
    throw "Value not found";
}

int find(const vector<string>& vec, string val) {
    return binary_search(vec, val, 0, vec.size() - 1);
}

int main() {
    cout << find(
            {"at", "", "", "ball", "car"},
            "ball") << endl;
    cout << find(
            {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""},
            "ball") << endl;
}

