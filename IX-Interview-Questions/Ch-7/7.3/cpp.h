#include <vector>


class Song {
    private:
        int id;

    public:
        int get_id();
};

class Jukebox {
    public:
        class Page {
            private:
                std::vector<Song> songs;

            public:
                const std::vector<Song> view_songs();
        };

    private:
        std::vector<Page> pages;
        int page_index;

    public:
        void play(int id);

        const Page& view_page();
        const Page& view_next_page();
};

