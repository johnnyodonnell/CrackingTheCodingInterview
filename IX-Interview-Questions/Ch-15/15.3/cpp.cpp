#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <cstring>

/*
 * Interesting thoughts on std::lock and how it's implemented:
 * https://stackoverflow.com/a/18521611/5832619
 *
 */

using namespace std;

class Chopstick : public mutex {};

void print(const string& str) {
    static mutex m {};
    m.lock();
    cout << str << endl;
    m.unlock();
}

class Philosopher {
    private:
        string id;
        Chopstick& left_chopstick;
        Chopstick& right_chopstick;

    public:
        Philosopher(
                int c_id,
                Chopstick& c_left_chopstick, Chopstick& c_right_chopstick)
            :id{to_string(c_id)},
            left_chopstick{c_left_chopstick},
            right_chopstick{c_right_chopstick} {}

        Philosopher(const Philosopher&) = delete;
        Philosopher& operator=(const Philosopher&) = delete;

        Philosopher(Philosopher&& p)
            :id{p.id},
            left_chopstick{p.left_chopstick},
            right_chopstick{p.right_chopstick} {}

        Philosopher& operator=(Philosopher&& p) = delete;

        void eat_smart() {
            auto unique_left =
                unique_lock<Chopstick>(left_chopstick, defer_lock);
            auto unique_right =
                unique_lock<Chopstick>(right_chopstick, defer_lock);

            lock(unique_left, unique_right);
            print(string{"Philosopher "} + id + string{" left and right"});

            print(string{"Philosopher "} + id);
            unique_left.unlock();
            unique_right.unlock();

            eat_smart();
        }

        void eat() {
            left_chopstick.lock();
            print(string{"Philosopher "} + id + string{" left"});

            right_chopstick.lock();
            print(string{"Philosopher "} + id + string{" left and right"});

            print(string{"Philosopher "} + id);
            left_chopstick.unlock();
            right_chopstick.unlock();

            eat();
        }
};

int main(int argc, char** argv) {
    int num_of_philosophers = atoi(argv[1]);
    string eat_type = "default";
    if (argc >= 3) {
        eat_type = argv[2];
    }

    vector<Philosopher> philosophers {};

    auto first_chopstick = new Chopstick{};
    auto current_chopstick = new Chopstick{};
    Chopstick* previous_chopstick;

    philosophers.push_back({1, *first_chopstick, *current_chopstick});

    for (int i = 2; i < num_of_philosophers; i++) {
        previous_chopstick = current_chopstick;
        current_chopstick = new Chopstick{};

        philosophers.push_back(
                {i, *previous_chopstick, *current_chopstick});
    }

    philosophers.push_back(
            {num_of_philosophers, *current_chopstick, *first_chopstick});

    vector<thread> thrds {};
    for (auto& philosopher : philosophers) {
        thread thr {[&philosopher, eat_type]() {
            if (eat_type == "smart") {
                philosopher.eat_smart();
            } else {
                philosopher.eat();
            }
        }};
        thrds.push_back(move(thr));
    }

    for (auto& thr : thrds) {
        thr.join();
    }
}

