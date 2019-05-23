#include <iostream>
#include <chrono>
#include <future>

/*
 * Must be compiled with -pthread option
 * http://www.cplusplus.com/forum/beginner/218875/
 *
 */

using namespace std;
using namespace chrono;

microseconds run_task() {
    auto start = high_resolution_clock::now();
    cout << "Printing from within run function" << endl;
    auto stop = high_resolution_clock::now();
    return duration_cast<microseconds>(stop - start);
}

int main() {
    // Package task
    packaged_task<microseconds()> thr {run_task};
    auto ftr = thr.get_future();

    // Run thread
    auto start = high_resolution_clock::now();

    thr();
    auto sub_thread_duration = ftr.get();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Print results
    cout << "Main thread duration: " << duration.count() << endl;
    cout << "Sub thread duration: " << sub_thread_duration.count() << endl;
}

