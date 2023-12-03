#include <stdio.h>
#include <stdlib.h>

int digit(int n, int dis) {
    int res = n;
    for (int i = 0; i < dis; i++) {
        res = res / 10;
    }
    return res % 10;
}

int main(void) {
    int len;
    int *arr, *buc, *res, *pos;
    int dis = 0;
    scanf("%d", &len);
    arr = (int*)calloc(len, sizeof(int));
    res = (int*)calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &dis);
    buc = (int*)calloc(10, sizeof(int));
    pos = (int*)calloc(10, sizeof(int));
    for (int i = 0; i < len; i++) {
        ++buc[digit(arr[i], dis)];
    }
    for (int i = 1; i < 10; i++) {
        pos[i] = pos[i - 1] + buc[i - 1];
    }
    for (int i = 0; i < len; i++) {
        int temp = digit(arr[i], dis);
        res[pos[temp]] = arr[i];
        pos[temp]++;
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", res[i]);
    }
    free(arr);
    free(buc);
    free(res);
    free(pos);
    return 0;
}
