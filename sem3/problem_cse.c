#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp_t)(void const * lhs, void const * rhs);

int cmpInt(void const *lhs, void const *rhs) {
    if (*((int*)lhs) < *((int*)rhs))
        return 1;
    return 0;
}

void swap(void **x, void **y) {
    void *tmp = *x;
    *x = *y;
    *y = tmp;
}

int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
    int tmp = nsorted;
    void *a = (char*)parr + nsorted * eltsize;
    void *b;
    void *t = malloc(nsorted * eltsize);
    for (int i = tmp; i < numelts; i++) {
        if (cmp((char*)parr + i * eltsize, (char*)parr + tmp * eltsize)) {
            tmp = i;
        }
    }
    //swap((char*)parr + nsorted * eltsize, (char*)parr + tmp * eltsize);

    b = (char*)parr + tmp * eltsize;
    memcpy(t, a, eltsize);
    memcpy(a, b, eltsize);
    memcpy(b, t, eltsize);
    free(t);

    return 0;
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
    
    selstep(arr, sizeof(int), size, last, cmpInt);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
