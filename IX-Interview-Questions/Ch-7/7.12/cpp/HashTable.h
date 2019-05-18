#include <vector>
#include <forward_list>


template <typename Key, typename Value, typename Hash = std::hash<Key>>
class HashTable {
    private:
        std::vector<std::forward_list<std::pair<Key, Value>>> vec;
        Hash hash_function {};

    public:
        HashTable(const int size);

        void insert(const Key&, Value&&);
        Value& find(const Key&);
};

#include "HashTable.cpp"

