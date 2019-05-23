#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

void* align_malloc(const size_t size, const int multiple) {
    vector<void*> delete_queue {};
    int tries = 1;

    void* p = malloc(size);
    while ((((long) p) % multiple) != 0) {

        p = malloc(size);
        tries++;
    }

    cout << "Tries: " << tries << endl;

    for (auto p : delete_queue) {
        free(p);
    }

    return p;
}

void run_align_malloc(const size_t size, const int multiple) {
    auto p = align_malloc(size, multiple);
    cout << p << "\n" << endl;
}

int main() {
    run_align_malloc(1000, 2);
    run_align_malloc(1000, 16);
    run_align_malloc(1000, 32);
    run_align_malloc(1000, 64);
    run_align_malloc(1000, 128);
    run_align_malloc(1000, 256);
    run_align_malloc(1000, 512);
}

