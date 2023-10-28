#include <stdio.h>

int majority_element(const int *parr, int len) {
    int cnt  = 0;
    int cndt = 0;

    for (int i = 0; i < len; i++) {
        if (parr[i] == cndt) {
            ++cnt;
        } else if (cnt == 0) {
            cndt = parr[i];
            ++cnt;
        } else {
            --cnt;
        }
    }

    cnt = 0;
    for (int i = 0; i < len; i++) {
        if (parr[i] == cndt) {
            ++cnt;
        }
    }

    if (2 * cnt > len) {
        return cndt;
    } else {
        return -1;
    }
}

int main() {
    int arr[] = {2, 3, 1, 2, 2};
    printf("%d", majority_element(arr, 5));
    return 0;
}
