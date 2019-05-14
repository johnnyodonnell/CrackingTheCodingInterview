#include <iostream>
#include <unordered_set>


using namespace std;

class SimpleNode {
    private:
        int value;
        SimpleNode* next = nullptr;

    public:
        SimpleNode(int c_value) :value{c_value} {}

        void append(SimpleNode* node) {
            if (next == nullptr) {
                next = node;
                return;
            }

            auto tail = next;
            while (tail->next != nullptr) {
                tail = tail->next;
            }

            tail->next = node;
        }

        SimpleNode* get_next() {
            return next;
        }

        int get_value() {
            return value;
        }
};

SimpleNode* get_next_if_has_next(SimpleNode* node) {
    if (node) {
        return node->get_next();
    } else {
        return nullptr;
    }
}

/*
 * Runs O(n)
 * Space O(2n)
 *
 */
SimpleNode* find_loop_fast(SimpleNode* head) {
    unordered_set<SimpleNode*> nodes_seen {head};

    head = head->get_next();
    while (head != nullptr) {
        if (nodes_seen.count(head)) {
            return head;
        } else {
            nodes_seen.insert(head);
            head = head->get_next();
        }
    }

    return nullptr;
}

/*
 * Runs O(2n)
 * Space O(n)
 *
 */
SimpleNode* find_loop(SimpleNode* head) {
    auto runner_1 = get_next_if_has_next(head);
    auto runner_2 = get_next_if_has_next(get_next_if_has_next(head));

    if (!(runner_1 && runner_2)) {
        return nullptr;
    }

    // Runners will meet at k nodes away from loop head
    while (runner_1 != runner_2) {
        runner_1 = get_next_if_has_next(runner_1);
        runner_2 = get_next_if_has_next(get_next_if_has_next(runner_2));
    }

    // Move k nodes forward to loop head
    runner_1 = head;
    while (runner_1 != runner_2) {
        runner_1 = get_next_if_has_next(runner_1);
        runner_2 = get_next_if_has_next(runner_2);
    }

    return runner_1;
}

int main() {
    auto head = new SimpleNode(4);
    head->append(new SimpleNode(6));
    head->append(new SimpleNode(9));
    head->append(new SimpleNode(10));
    head->append(new SimpleNode(11));
    auto loop = new SimpleNode(27);
    head->append(loop);
    head->append(new SimpleNode(31));
    head->append(new SimpleNode(32));
    head->append(loop);

    auto loop_guess = find_loop(head);
    cout << "Loop guess correct? " << (loop_guess == loop) << endl;
}

