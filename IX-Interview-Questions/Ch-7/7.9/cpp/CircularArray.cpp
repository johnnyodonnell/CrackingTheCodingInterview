#include <iostream>

template <typename T>
CircularArray<T>::CircularArray() :start{vec.begin()}  {}

template <typename T>
void CircularArray<T>::push_back(const T& value) {
    if (start == vec.begin()) {
        vec.push_back(value);
        // In case vec needs to be resized
        start = vec.begin();
    } else {
        vec.insert(start, value);
    }
}

template <typename T>
void CircularArray<T>::rotate(int n) {
    start = vec.begin() + (((start - vec.begin()) + n) % vec.size());
}

template <typename T>
typename CircularArray<T>::Iterator CircularArray<T>::begin() {
    return CircularArray<T>::Iterator {vec.begin(), vec, start - vec.begin()};
}

template <typename T>
typename CircularArray<T>::Iterator CircularArray<T>::end() {
    return CircularArray<T>::Iterator {vec.end(), vec, start - vec.begin()};
}

template <typename T>
CircularArray<T>::Iterator::Iterator(
        typename std::vector<T>::iterator c_curr,
        const std::vector<T>& c_vec,
        const long c_offset)
    :curr{c_curr}, vec{c_vec}, offset{c_offset} {
}

template <typename T>
const T& CircularArray<T>::Iterator::operator*() {
    auto itr =  vec.begin() + (((curr - vec.begin()) + offset) % vec.size());
    return *itr;
}

template <typename T>
const typename CircularArray<T>::Iterator& CircularArray<T>::Iterator::operator++() {
    curr++;
    return *this;
}

template <typename T>
bool CircularArray<T>::Iterator::operator!=(
        const CircularArray<T>::Iterator& it) {
    return curr != it.curr;
}

