#include <vector>


template <typename T>
class CircularArray {
    public:
        class Iterator {
            private:
                int start;
                int finish;
                typename std::vector<T>::iterator beg;

            public:
                T& operator*();
                void operator+(int);
                void operator-(int);
                void operator++();
                void operator++(int);
                void operator--();
                void operator--(int);
        };

    private:
        std::vector<T> vec;
        int start;
        int finish;

    public:
        /*
         * Insert may not be that effecient if the array has been rotated
         */
        void insert(const T&);
        void rotate(int);
        Iterator begin();
        Iterator end();
};

