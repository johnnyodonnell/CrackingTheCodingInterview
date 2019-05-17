#include <iostream>


using namespace std;

int main() {
    int families = 100000;

    int girls = 0;
    int boys = 0;

    for (int i = 0; i < families; i++) {
        int gender = rand() % 100;
        while (gender < 50) {
            boys++;
            gender = rand() % 100;
        }
        girls++;
    }

    cout << "girls : boys = " << ((double) girls * 100 / (boys + girls))
        << " : " << ((double) boys * 100 / (boys + girls)) << endl;
}

