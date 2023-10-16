#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    int *arr;

    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);    
    }

    scanf("%d", &k);
    arr[(k / 8)] ^= 1u << (k % 8);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);    
    }

    return 0;
}
