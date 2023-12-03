#include <string.h>
#include <malloc.h>

unsigned mul_row_column(unsigned *const row, unsigned *const column, unsigned col, unsigned m) {
    unsigned result = 0;

    for (unsigned i = 0; i < N; i++) {
        result += (row[i] * column[i * N + col]) % m;
    }
    return result % m;
}

void powNxN(unsigned (*A)[N], unsigned k, unsigned m) {
    unsigned *B = (unsigned*)calloc(N * N, sizeof(unsigned));
    unsigned *C = (unsigned*)calloc(N * N, sizeof(unsigned));
    memcpy(B, A, N * N * sizeof(unsigned));
    for (unsigned i = 0; i < k - 1; i++) {
        memcpy(C, A, N * N * sizeof(unsigned));

        for (unsigned x = 0; x < N; x++) {
            for (unsigned y = 0; y < N; y++) {
                A[x][y] = mul_row_column(B + x * N, C, y, m);
            }
        }
    }
}
