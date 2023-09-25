#include <stdio.h>
#include <assert.h>

unsigned pow_mod(unsigned a, unsigned b, unsigned n) {
    unsigned mult = a % n;
    unsigned prod = 1;

    while (b > 0) {
        if ((b % 2) == 1) {
            prod = (prod * mult) % n;
            b = b - 1;;
        }
        mult = (mult * mult) % n;
        b = b / 2;
    }

    return prod;
}

void spow_mod(unsigned a, unsigned b, unsigned n) {
    unsigned ans = a;
    
    while (b > 1) {
        ans = pow_mod(ans, a, n);
        b -= 1;
    }

    printf("%u", ans);
}

int main() {
    unsigned a, b, n, res;

    res = scanf("%u%u%u", &a, &b, &n);
    assert(res == 3);

    spow_mod(a, b, n);

    return 0;
}
