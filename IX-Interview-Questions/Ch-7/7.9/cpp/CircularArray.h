#include <vector>


template <typename T>
class CircularArray {
    public:
        class Iterator {
            private:
                typename std::vector<T>::iterator curr;
                const std::vector<T>& vec;
                long offset;

            public:
                Iterator(typename std::vector<T>::iterator curr,
                        const std::vector<T>& vec,
                        const long offset);

                const T& operator*();
                const typename CircularArray<T>::Iterator& operator++();
                bool operator!=(const Iterator&);
        };

    private:
        std::vector<T> vec;
        typename std::vector<T>::iterator start;

    public:
        CircularArray();

        /*
         * Insert may not be that effecient if the array has been rotated
         */
        void push_back(const T&);
        void rotate(int);
        Iterator begin();
        Iterator end();
};

#include "CircularArray.cpp"

