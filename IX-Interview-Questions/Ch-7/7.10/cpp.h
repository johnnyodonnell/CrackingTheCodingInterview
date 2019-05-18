#include <vector>


class Cell {
    public:
        // Bool indicates if click was safe
        virtual bool click();
        virtual char print();
        virtual ~Cell();
};

class Bomb : public Cell {};

class Number : public Cell {};

class Minesweeper {
    private:
        std::vector<std::vector<Cell*>> cells;

    public:
        std::vector<std::vector<Cell*>> get_cells();
        void click_cell(int r, int c);
};

