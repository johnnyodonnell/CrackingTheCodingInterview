#include <iostream>
#include <list>


using namespace std;

struct Animal {
    virtual void talk() = 0;
};

struct Dog : Animal {
    void talk() {
        cout << "Bark!" << endl;
    }
};

struct Cat : Animal {
    void talk() {
        cout << "Meow!" << endl;
    }
};

class Shelter {
    private:
        list<Animal*> q {};

        template <typename T>
        T* dequeue() {
            auto p = q.begin();
            while (p != q.end()) {
                T* result = dynamic_cast<T*>(*p);

                if (result) {
                    q.erase(p);
                    return result;
                }

                p++;
            }
        }

    public:
        void enqueue(Animal* a) {
            q.push_back(a);
        }

        Animal* dequeueAny() {
            Animal* front = q.front();
            q.pop_front();
            return front;
        }

        Dog* dequeueDog() {
            return dequeue<Dog>();
        }

        Cat* dequeueCat() {
            return dequeue<Cat>();
        }

        bool empty() {
            return q.empty();
        }
};

int main() {
    Shelter shelter {};
    shelter.enqueue(new Dog());
    shelter.enqueue(new Dog());
    shelter.enqueue(new Cat());
    shelter.enqueue(new Cat());
    shelter.enqueue(new Cat());
    shelter.enqueue(new Dog());
    shelter.enqueue(new Cat());
    shelter.enqueue(new Cat());
    shelter.enqueue(new Dog());

    shelter.dequeueCat()->talk();
    shelter.dequeueDog()->talk();
    cout << endl;

    while (!shelter.empty()) {
        Animal* a = shelter.dequeueAny();
        a->talk();
    }
}

