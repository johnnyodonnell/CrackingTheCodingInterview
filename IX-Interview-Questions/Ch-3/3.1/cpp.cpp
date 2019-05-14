#include <iostream>
#include <vector>


using namespace std;

template <typename T>
class MultiStack {
    private:
        struct StackData {
            int stack_num;
            T data;
            bool safe_to_delete = false;
        };

        int num_of_stacks;
        vector<StackData> data {};
        vector<int> tops_index;

    public:
        MultiStack(const int c_num_of_stacks)
            :num_of_stacks{c_num_of_stacks},
            tops_index(c_num_of_stacks, -1) {}

        void push(const T elem, const int stack_num) {
            int top = tops_index.at(stack_num);

            int new_top = top + 1;
            while ((new_top < data.size())
                    && (!data[new_top].safe_to_delete)) {
                new_top++;
            }

            if (new_top >= data.size()) {
                data.push_back({stack_num, elem});
            } else {
                data[new_top] = {stack_num, elem};
            }

            tops_index.at(stack_num) = new_top;
        }

        void pop(const int stack_num) {
            int top = tops_index.at(stack_num);
            data.at(top).safe_to_delete = true;

            int new_top = top - 1;
            while ((new_top > -1)
                    && (data[new_top].stack_num != stack_num)) {
                new_top--;
            }

            tops_index.at(stack_num) = new_top;
        }

        T& peek(const int stack_num) {
            int top = tops_index.at(stack_num);
            return data.at(top).data;
        }

        bool isEmpty(const int stack_num) {
            return (tops_index.at(stack_num) < 0);
        }
};

int main() {
    MultiStack<int> multiStack {3};
    cout << "First stack empty? " << multiStack.isEmpty(0) << endl;
    for (auto i : {1, 2, 3}) {
        multiStack.push(i, 0);
    }
    cout << "First stack empty? " << multiStack.isEmpty(0) << endl;
    while (!multiStack.isEmpty(0)) {
        cout << multiStack.peek(0) << ", ";
        multiStack.pop(0);
    }
    cout << "\n";
    cout << "First stack empty? " << multiStack.isEmpty(0) << endl;

    for (auto i : {1, 2, 3}) {
        multiStack.push(i, 0);
    }

    for (auto i : {4, 5, 6, 7, 8, 9, 10}) {
        multiStack.push(i, 0);
        multiStack.push(i, 1);
    }

    for (auto i : {11, 12, 13, 14}) {
        multiStack.push(i, 0);
        multiStack.push(i, 1);
        multiStack.push(i, 2);
    }

    while (!multiStack.isEmpty(0)) {
        cout << multiStack.peek(0) << ", ";
        multiStack.pop(0);
    }
    cout << endl;

    while (!multiStack.isEmpty(1)) {
        cout << multiStack.peek(1) << ", ";
        multiStack.pop(1);
    }
    cout << endl;

    for (auto i : {15, 16, 17}) {
        multiStack.push(i, 2);
    }

    while (!multiStack.isEmpty(2)) {
        cout << multiStack.peek(2) << ", ";
        multiStack.pop(2);
    }
    cout << endl;
}

