#include <stdio.h>
#include <stdlib.h>


void* my2DAlloc(size_t size_type, int r, int c) {
    void** rows = malloc(r * sizeof(void*));
    void* cols = malloc(r * c * size_type);

    for (int i = 0; i < r; i++) {
        rows[i] = cols + (i * c);
    }

    return rows;
}

int main() {
    int rows = 3;
    int cols = 4;

    char** arr = my2DAlloc(sizeof(int), rows, cols);

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

