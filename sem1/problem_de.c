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

void diofantine(long long x, long long y, long long z) {
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

    if (z % x != 0) {
        printf("NONE");
    } else {
        long long coeff = z / x;
        printf("%lli %lli", ax * coeff, bx * coeff);
    }
    
}

int main() {
    long long a, b, c;
    int res;

    res = scanf("%lli%lli%lli", &a, &b, &c);
    assert(res == 3);

    diofantine(a, b, c);
    return 0;
}
