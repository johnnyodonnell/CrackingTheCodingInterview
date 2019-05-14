#include <iostream>
#include <forward_list>

/*
 * NOTE: This solution fails to imagine the possibility that the heads
 * of two linked lists merge into single linked list. This isn't possible
 * with forward_lists, but is possible with a more basic linked list.
 *
 */

using namespace std;

/*
 * Runs O(n)
 *
 */
bool intersect(
        forward_list<int>::const_iterator node1,
        const forward_list<int>::const_iterator end1,
        forward_list<int>::const_iterator node2,
        const forward_list<int>::const_iterator end2) {
    auto node1_copy = node1;
    while (node1_copy != end1) {
        if (node1_copy == node2) {
            return true;
        }
        node1_copy++;
    }

    auto node2_copy = node2;
    while (node2_copy != end2) {
        if (node1 == node2_copy) {
            return true;
        }
        node2_copy++;
    }

    return false;
}

int main() {
    forward_list<int> list1 {1, 2, 3, 4};
    forward_list<int> list2 {1, 2, 3, 4};

    cout << "Test 1: "
        << intersect(list1.begin(), list1.end(), list1.begin(), list1.end())
        << endl;
    cout << "Test 2: "
        << intersect(list1.begin(), list1.end(), list2.begin(), list2.end())
        << endl;
    cout << "Test 3: "
        << intersect(
                list1.begin(), list1.end(),
                next(list1.begin(), 2), list1.end())
        << endl;
    cout << "Test 3: "
        << intersect(
                next(list1.begin(), 1), list1.end(),
                next(list1.begin(), 2), list1.end())
        << endl;
}

