#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int myrand() {
    static unsigned long int seed = 1;
    seed = seed * 1103515245 + 12345;
    return (unsigned int)(seed / 65536) % 32768;
}

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int size;
    int *arr;

    scanf("%d", &size);
    if (size == 0) {
        printf("%d", 0);
        return 0;
    }

    arr = (int*)malloc(sizeof(int) * size);
    
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    for (int i = size - 1; i >= 0; i--) {
        int index = myrand() % (i + 1);
        swap(arr + index, arr + i);
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
