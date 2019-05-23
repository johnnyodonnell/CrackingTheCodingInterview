#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>


using namespace std;

class Foo {
    private:
        bool first_called = false;
        bool second_called = false;
        mutex m {};
        condition_variable cv {};

    public:
        void first() {
            cout << "First called" << endl;
            first_called = true;
            cv.notify_all();
        }

        bool has_first_been_called() {
            return first_called;
        }

        void second() {
            cout << "Second called" << endl;
            second_called = true;
            cv.notify_all();
        }

        bool has_second_been_called() {
            return second_called;
        }

        void third() {
            cout << "Third called" << endl;
        }

        template <typename P>
        void wait(P pred) {
            unique_lock<mutex> lck {m};
            cv.wait(lck, pred);
        }
};

int main() {
    Foo foo {};

    thread t3 {[&foo]() {
        foo.wait([&foo]() {
                return foo.has_second_been_called();
                });
        foo.third();
    }};

    thread t2 {[&foo]() {
        foo.wait([&foo]() {
                return foo.has_first_been_called();
                });
        foo.second();
    }};

    thread t1 {[&foo]() {
        foo.first();
    }};

    t3.join();
    t2.join();
    t1.join();
}

