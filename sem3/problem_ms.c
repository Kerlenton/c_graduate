#include <string.h>
#include <stdlib.h>

void merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *left = malloc(sizeof(int) * n1);
    int *right = malloc(sizeof(int) * n2);

    int i = 0;
    int j = 0;
    int k = l;

    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = arr[m + 1 + j];
    }


    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}
