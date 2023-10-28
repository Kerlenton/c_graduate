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
    int last;
    int tmp;

    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    scanf("%d", &last);
    tmp = last;

    for (int i = last + 1; i < size; i++) {
        if (arr[i] < arr[tmp]) {
            tmp = i;
        }
    }

    if (arr[last] != arr[tmp])
        swap(arr + last, arr + tmp);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
