#include <unordered_map>


class File {};

class FileSystem {
    private:
        std::unordered_map<std::string, File> files;

    public:
        File& create(std::string);
        File& edit(std::string);
        const File& view(std::string);
        void destroy(std::string);
};

