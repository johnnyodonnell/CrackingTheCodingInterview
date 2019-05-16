#include <iostream>
#include <vector>


using namespace std;

void draw_line(vector<char>& screen, int width, int x1, int x2, int y) {
    while (x1 <= x2) {
        int screen_i = ((width / 8) * y) + (x1 / 8);
        char& c = screen.at(screen_i);

        int char_i = (x1 % 8);
        unsigned char setter = (1 << (7 - char_i));
        c |= setter;

        x1++;
    }
}

int main() {
    int width = 128;
    int height = (width / 4);

    vector<char> screen {};

    for (int i = 0; i < height; i++) {
        for (int i = 0; i < (width / 8); i++) {
            screen.push_back('\0');
        }
    }

    draw_line(screen, width, 5, 110, 17);

    for (int i = 0; i < screen.size(); i++) {
        char c = screen.at(i);
        for (unsigned char i  = (1 << 7); i != 0; i >>= 1) {
            if (c & i) {
                cout << '1';
            } else {
                cout << '0';
            }
        }

        if (((i + 1) % (width / 8)) == 0) {
            cout << endl;
        }

    }
}

