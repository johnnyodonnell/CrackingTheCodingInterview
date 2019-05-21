#include <iostream>
#include <vector>


using namespace std;

bool char_to_bool(char c) {
    return (c != '0');
}

bool bool_and(bool left, bool right) {
    return left & right;
}

bool bool_or(bool left, bool right) {
    return left | right;
}

bool bool_xor(bool left, bool right) {
    return left ^ right;
}

vector<bool> eval(string str) {
    if ((str.length() % 2) == 0) {
        cout << str.length() << endl;
        throw "string length should never be even";
    }

    if (str.length() == 1) {
        return {char_to_bool(str.at(0))};
    } else {
        vector<bool> result {};

        for (int i = 1; i < str.length(); i += 2) {
            char oper = str.at(i);

            auto left = eval(str.substr(0,i));
            auto right = eval(str.substr(i + 1));

            bool (*pred)(bool, bool);
            switch(oper) {
                case '&':
                    pred = bool_and;
                    break;
                case '|':
                    pred = bool_or;
                    break;
                case '^':
                    pred = bool_xor;
                    break;
                default:
                    cout << oper << endl;
                    throw "Operation not supported";
            }

            for (auto left_value : left) {
                for (auto right_value : right) {
                    result.push_back(pred(left_value, right_value));
                }
            }
        }

        return result;
    }
}

int count_eval(string str, bool desired_result) {
    int count = 0;

    auto results = eval(str);
    for (auto result : results) {
        if (result == desired_result) {
            ++count;
        }
    }

    return count;
}

int main() {
    cout << count_eval("1&1", true) << endl;
    cout << count_eval("1&0", true) << endl;
    cout << count_eval("1^0|1", true) << endl;
    cout << count_eval("1^0|0|1", false) << endl;
    cout << count_eval("0&0&0&1^1|0", true) << endl;
}

