#include <iostream>
#include <fstream>
#include <queue>


using namespace std;

int print_last_lines(ifstream& file, int k) {
    queue<string> lines {};

    while (!file.eof()) {
        const int buf_size = 256;
        char buf[buf_size];
        file.getline(buf, buf_size);
        lines.push({buf});

        if (lines.size() > k) {
            lines.pop();
        }
    }

    while(!lines.empty()) {
        cout << lines.front() << endl;
        lines.pop();
    }
}

int main(int argc, char** argv) {
    int k = atoi(argv[1]);
    char* filename = argv[2];

    ifstream file {};
    file.open(filename);

    print_last_lines(file, k);
}

