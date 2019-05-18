#include <vector>


class Player {
    private:
        int id;

    public:
        int get_id();
};

class Othello {
    public:
        class Piece {
            public:
                enum class Color { White, Black };

            private:
                Color color;
                const Player& player;

            public:
                void flip();
                Color get_color();
                const Player& owner();
        }

    private:
        std::vector<std::vector<Piece>> pieces;

    public:
        Piece& get_piece_at(int r, int c);
        void place_piece_at(Piece&, int r, int c);
};

