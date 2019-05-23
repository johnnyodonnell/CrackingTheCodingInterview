#include <iostream>

/*
 * Basically the same thing as a shared_ptr from the standard library
 *
 */

using namespace std;

template <typename T>
class SmartPointer {
    private:
        T* ptr;
        int* count;

        void check_count() {
            if (*count == 1) {
                cout << "Destroying everything" << endl;
                delete ptr;
                delete count;
            } else {
                cout << "Decrementing counter" << endl;
                --*count;
            }

        }

    public:
        SmartPointer(T* c_ptr) :ptr{c_ptr}, count{new int{1}} {}

        SmartPointer(const SmartPointer& sp) :ptr{sp.ptr}, count{sp.count} {
            ++*count;
        }

        SmartPointer& operator=(const SmartPointer& sp) {
            check_count();

            ptr = sp.ptr;
            count = sp.count;
            ++*count;
            return *this;
        }

        ~SmartPointer() {
            check_count();
        }
};

template <typename T>
void do_nothing(SmartPointer<T> sp) {
    cout << "Doing nothing" << endl;
    cout << &sp << endl;
}

int main() {
    SmartPointer<int> sp {new int{4}};
    do_nothing(sp);
    cout << endl;

    {
        SmartPointer<int> sp2 {new int{5}};
        sp2 = sp;
    }
    cout << endl;

    cout << &sp << endl;
}

