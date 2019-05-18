#include <vector>


enum class Suit { Spade, Club, Diamond, Heart, Joker };

enum class Rank {
    Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack, Queen, King,
};

class Card {
    private:
        Suit suit;

    public:
        Suit get_suit();
};

class Standard : public Card {
    private:
        Rank rank;

    public:
        Rank get_rank();
};

class Joker : public Card {
};

class Deck {
    private:
        std::vector<Card*> cards;

    public:
        Deck();

        void shuffle();
        const Card& draw();
        void remove(const Card&);
};

