#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;

int main(int argc, char** argv) {
    int n = atoi(argv[1]);
    int current = 1;

    mutex m {};
    condition_variable cv {};

    thread t1 {[&current, n, &m, &cv]() {
        while (current <= n) {
            unique_lock<mutex> lck {m};
            cv.wait(lck, [&current, n]() {
                    return ((((current % 3) == 0) && ((current % 5) != 0))
                            || (current > n));
                    });
            if (current <= n) {
                cout << "Fizz" << endl;
                current++;
                cv.notify_all();
            }
        }
    }};

    thread t2 {[&current, n, &m, &cv]() {
        while (current <= n) {
            unique_lock<mutex> lck {m};
            cv.wait(lck, [&current, n]() {
                    return ((((current % 5) == 0) && ((current % 3) != 0))
                            || (current > n));
                    });

            if (current <= n) {
                cout << "Buzz" << endl;
                current++;
                cv.notify_all();
            }
        }
    }};

    thread t3 {[&current, n, &m, &cv]() {
        while (current <= n) {
            unique_lock<mutex> lck {m};
            cv.wait(lck, [&current, n]() {
                    return ((((current % 3) == 0) && ((current % 5) == 0))
                            || (current > n));
                    });
            if (current <= n) {
                cout << "FizzBuzz" << endl;
                current++;
                cv.notify_all();
            }
        }
    }};

    thread t4 {[&current, n, &m, &cv]() {
        while (current <= n) {
            unique_lock<mutex> lck {m};
            cv.wait(lck, [&current, n]() {
                    return ((((current % 3) != 0) && ((current % 5) != 0))
                            || (current > n));
                    });
            if (current <= n) {
                cout << current << endl;
                current++;
                cv.notify_all();
            }
        }
    }};

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

