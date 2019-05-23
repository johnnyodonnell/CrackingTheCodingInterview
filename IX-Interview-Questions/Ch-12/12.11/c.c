#include <stdio.h>
#include <stdlib.h>


void* my2DAlloc(size_t size_type, int r, int c) {
    size_t rows_size = r * sizeof(void*);
    size_t cols_size = r * c * size_type;

    void* mem = malloc(rows_size + cols_size);
    void** rows = mem;
    void* cols = (rows + r);

    for (int i = 0; i < r; i++) {
        // The reason this worked earlier without size_type is because
        // we were using char instead of int
        rows[i] = cols + (i * c * size_type);
    }

    return mem;
}

int main() {
    int rows = 10;
    int cols = 10;

    int** arr = my2DAlloc(sizeof(int), rows, cols);

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            printf("(r: %d, c: %d)\n", r, c);
            arr[r][c] = (r * c) + c;
        }
    }
    printf("\n");

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            printf("%d, ", arr[r][c]);
        }
        printf("\n");
    }
}

