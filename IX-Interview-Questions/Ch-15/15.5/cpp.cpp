#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>


using namespace std;

class Foo {
    private:
        bool first_called = false;
        bool second_called = false;

    public:
        void first() {
            cout << "First called" << endl;
            first_called = true;
        }

        bool has_first_been_called() {
            return first_called;
        }

        void second() {
            cout << "Second called" << endl;
            second_called = true;
        }

        bool has_second_been_called() {
            return second_called;
        }

        void third() {
            cout << "Third called" << endl;
        }
};

int main() {
    Foo foo {};

    thread t3 {[&foo]() {
        while(!foo.has_second_been_called()) {}
        foo.third();
    }};

    thread t2 {[&foo]() {
        while(!foo.has_first_been_called()) {}
        foo.second();
    }};

    thread t1 {[&foo]() {
        foo.first();
    }};

    t3.join();
    t2.join();
    t1.join();
}

