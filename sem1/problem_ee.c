#include <stdio.h>
#include <assert.h>

long long math_mod(long long x, long long y) {
    long long tmp = x % y;
    return (tmp < 0 ? tmp + y : tmp);
}

void swap(long long *x, long long *y) {
    long long tmp = *x;
    *x = *y;
    *y = tmp;
}

void extended_gcd(long long x, long long y) {
    long long ax = 1, bx = 0;
    long long ay = 0, by = 1;

    if (x < 0) {
        x = -x;
        ax = -ax;
    }

    if (y < 0) {
        y = -y;
        by = -by;
    }

    if (x < y) {
        swap(&x, &y);
        swap(&ax, &ay);
        swap(&bx, &by);
    }

    while (y != 0) {
        long long tmp = x / y;
        x -= tmp * y;
        ax -= tmp * ay;
        bx -= tmp * by;

        swap(&x, &y);
        swap(&ax, &ay);
        swap(&bx, &by);
    }


    printf("%lli %lli %lli", ax, bx, x);
}

int main() {
    long long x, y;
    int res;

    res = scanf("%lli%lli", &x, &y);
    assert(res == 2);

    extended_gcd(x, y);
    return 0;
}
