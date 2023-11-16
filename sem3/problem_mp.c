#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 100

int main() {
    int len1, len2;
    int *pol1, *pol2, *result;
    int tmp;
    // Считываем длины полиномов
    scanf("%d %d", &len1, &len2);
    pol1 = malloc(sizeof(int) * len1);
    pol2 = malloc(sizeof(int) * len2);
    tmp = len1 + len2 - 2;
    result = malloc(sizeof(int) * (len1 + len2));
    for (int i = 0; i < len1; i++) {
        scanf("%d", &pol1[i]);
    }

    for (int i = 0; i < len2; i++) {
        scanf("%d", &pol2[i]);
    }
    
    for (int i = 0; i < len1 + len2 - 1; i++) {
        result[i] = 0;
    }

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            result[i + j] += pol1[i] * pol2[j];
        }
    }

    while (result[tmp] == 0) {
        tmp -= 1;
    }

    for (int i = 0; i <= tmp; i++) {
        printf("%d ", result[i]);
    }

    free(pol1);
    free(pol2);
    free(result);

    return 0;
}
