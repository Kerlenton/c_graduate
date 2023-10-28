#include <stdio.h>

int moveright(int *arr, int key, int last) {
    int pos = 0;

    for (int i = last - 1; i >= 0; i--) {
        if (key >= arr[i]) {
            pos = i + 1;
            break;
        }
    }

    for (int i = last - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    return pos;
}

void inssort(int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        int key, pos;
        key = arr[i];
        pos = moveright(arr, key, i);
        arr[pos] = key;
    }
}

int main() {
    int arr[] = {5};
    inssort(arr, 1);

    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
