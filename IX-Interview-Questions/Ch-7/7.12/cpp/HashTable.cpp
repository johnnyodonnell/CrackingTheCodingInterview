#include <iostream>
using namespace std;

template <typename Key, typename Value, typename Hash>
HashTable<Key, Value, Hash>::HashTable(const int size) :vec(size) {}

template <typename Key, typename Value, typename Hash>
void HashTable<Key, Value, Hash>::insert(const Key& key, Value&& value) {
    const size_t i = hash_function(key) % vec.size();
    auto& flist = vec.at(i);

    auto itr = flist.begin();
    while (itr != flist.end()) {
        if (itr->first == key) {
            itr->second = value;
            return;
        }

        itr++;
    }

    flist.push_front({key, value});
}

template <typename Key, typename Value, typename Hash>
Value& HashTable<Key, Value, Hash>::find(const Key& key) {
    const size_t i = hash_function(key) % vec.size();
    auto& flist = vec.at(i);

    auto itr = flist.begin();
    while (itr != flist.end()) {
        if (itr->first == key) {
            return itr->second;
        }

        itr++;
    }

    throw "Value not found";
}

