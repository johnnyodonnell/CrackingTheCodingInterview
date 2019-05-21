#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>


using namespace std;

struct Box {
    int id;
    int height;
    int length;
    int width;
};

int random_dimension() {
    return ((rand() % 100) + 1);
}

pair<stack<Box>, int>
highest_stack(queue<Box> boxes, stack<Box> current_stack, int stack_height) {
    if (boxes.empty()) {
        return {current_stack, stack_height};
    }

    int max_stack_height = stack_height;
    stack<Box> max_stack = current_stack;

    auto first_id = boxes.front().id;
    do {
        auto box = boxes.front();
        boxes.pop();

        auto boxes_copy = boxes;
        auto current_stack_copy = current_stack;

        auto& top_box = current_stack_copy.top();
        if (current_stack_copy.empty()
                || ((box.width < top_box.width)
                    && (box.length< top_box.length))) {
            current_stack_copy.push(box);
            auto result = highest_stack(
                    boxes_copy, current_stack_copy, stack_height + box.height);

            if (result.second > max_stack_height) {
                max_stack_height = result.second;
                max_stack = result.first;
            }
        }

        boxes.push(box);
    } while (boxes.front().id != first_id);

    return {max_stack, max_stack_height};
}

pair<stack<Box>, int>
highest_stack(queue<Box> boxes) {
    return highest_stack(boxes, {}, 0);
}

void print_boxes(const queue<Box>& boxes) {
    auto boxes_copy = boxes;

    while (!boxes_copy.empty()) {
        auto& box = boxes_copy.front();
        cout << "{id: " << box.id
            << ", l: " << box.length
            << ", w: " << box.width
            << ", h: " << box.height << "}, ";
        boxes_copy.pop();
    }
    cout << endl;
}

void print_boxes(const stack<Box>& boxes) {
    auto boxes_copy = boxes;

    while (!boxes_copy.empty()) {
        auto& box = boxes_copy.top();
        cout << "{id: " << box.id
            << ", l: " << box.length
            << ", w: " << box.width
            << ", h: " << box.height << "}, ";
        boxes_copy.pop();
    }
    cout << endl;
}

int main() {
    queue<Box> boxes {};
    for (int n = 0; n < 25; n++) {
        boxes.push({
                n + 1,
                random_dimension(),
                random_dimension(),
                random_dimension()});
    }

    print_boxes(boxes);
    cout << endl;

    auto result = highest_stack(boxes);
    cout << "Max height: " << result.second << endl;
    print_boxes(result.first);
}

