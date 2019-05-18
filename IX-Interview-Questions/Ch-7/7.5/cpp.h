#include <map>


class Book {
    private:
        int id;

    public:
        int get_id();
};

class OnlineBookReader {
    private:
        std::map<int, Book> books;

    public:
        void view_book(int id);
};

