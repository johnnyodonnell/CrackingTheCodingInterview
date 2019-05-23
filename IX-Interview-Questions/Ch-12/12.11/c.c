#include <stdio.h>
#include <stdlib.h>

void* my2DAlloc(size_t size_type, int r, int c) {
    void** result = malloc(r * sizeof(void*));

    for (int i = 0; i < r; i++) {
        result[i] = malloc(c * size_type);
    }

    return result;
}

int main() {
    char** arr = my2DAlloc(sizeof(int), 10, 10);

    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            printf("(r: %d, c: %d)\n", r, c);
            arr[r][c] = r + c;
        }
    }
    printf("\n");

    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            printf("%d, ", arr[r][c]);
        }
        printf("\n");
    }
}

