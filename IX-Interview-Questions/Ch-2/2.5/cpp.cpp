#include <iostream>
#include <forward_list>


using namespace std;

/*
 * Runs in O(n) time, but also takes O(n)
 * This could pretty easily be converted into a loop to saved on space
 *
 * Assumes list1 and list2 are same length
 *
 */
int sum_reverse(
        forward_list<int>::const_iterator current1,
        const forward_list<int>::const_iterator& end1,
        forward_list<int>::const_iterator current2) {
    if (current1 == end1) {
        return 0;
    } else {
        return (*current1 + *current2)
            + (10 * sum_reverse(++current1, end1, ++current2));
    }
}

/*
 * Runs O(n)
 *
 * Assumes list1 and list2 are same length
 *
 */
int sum(
        forward_list<int>::const_iterator current1,
        const forward_list<int>::const_iterator& end1,
        forward_list<int>::const_iterator current2) {
    int sum = 0;
    while (current1 != end1) {
        sum = (10 * sum) + (*current1 + *current2);
        current1++;
        current2++;
    }
    return sum;
}

void run_sum_lists(
        const forward_list<int>& num1, const forward_list<int>& num2) {
    cout << "Sum: "
        << sum(num1.begin(), num1.end(), num2.begin())
        << "\n";
    cout << "Sum reverse: "
        << sum_reverse(num1.begin(), num1.end(), num2.begin())
        << "\n";
    cout << endl;
}

int main() {
    run_sum_lists({7, 1, 6}, {5, 9, 2});
    run_sum_lists({6, 1, 7}, {2, 9, 5});
}

