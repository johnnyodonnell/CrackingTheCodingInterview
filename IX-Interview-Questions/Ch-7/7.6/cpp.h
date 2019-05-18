#include <vector>


class PuzzlePiece {
};

class Jigsaw {
    private:
        std::vector<std::vector<PuzzlePiece>> solution;
        std::vector<PuzzlePiece> pieces;

    public:
        bool try_place(const PuzzlePiece&, int row, int col);
        std::vector<PuzzlePiece> get_pieces();
};

