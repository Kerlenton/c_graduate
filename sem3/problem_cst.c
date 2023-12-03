#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int len;
    int *arr, *buc;
    int max = 0;
    scanf("%d", &len);
    arr = (int*)calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    for (int i = 1; i < len; i++) {
        max = (arr[i] > max) ? arr[i] : max;
    }
    buc = (int*)calloc(max + 1, sizeof(int));
    for (int i = 0; i < len; i++) {
        ++buc[arr[i]];
    }
    for (int i = 0; i <= max; i++) {
        printf("%d ", buc[i]);
    }
    free(arr);
    free(buc);
    return 0;
}
