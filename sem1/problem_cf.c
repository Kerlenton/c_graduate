#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void frac(long long x, long long y) {
    if (x < 0)
        x = -x;

    if (y < 0)
        y = -y;

    while (y != 0) {
        unsigned long long tmp = x;
        printf("%lli ", x / y);
        x = y;
        y = tmp % x;
    }
}

int main() {
    long long x = 0, y = 0;
    int res;

    res = scanf("%lli %lli", &x, &y);
    assert(res == 2);

    frac(x, y);
    return 0;
}
