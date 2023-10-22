#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long
pow_mul(unsigned long long a, unsigned long long b, unsigned long long n) {
    unsigned long long add = a % n;
    unsigned long long mul = 0ull;

    while (b > 0ull) {
        if ((b % 2ull) == 1ull) {
            mul = (mul + add) % n;
            b = b - 1ull;
        }

        add = (add + add) % n;
        b = b / 2ull;
    }

    return mul;
}


unsigned long long
pow_mod(unsigned long long a, unsigned long long b, unsigned long long n) {
    unsigned long long mult = a % n;
    unsigned long long prod = 1ull;

    while (b  > 0ull) {
        if ((b % 2ull) == 1ull) {
            prod = pow_mul(prod, mult,  n);
            b = b - 1ull;
        }

        mult = pow_mul(mult, mult, n);
        b = b / 2ull;
    }

    return prod;
}

unsigned long long gcd(unsigned long long x, unsigned long long y) {
    if (y == 0ull) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}

int
ft(unsigned long long x) {
    unsigned long long a = 1ull;
    unsigned long long ans = 0ull;

    srand(time(NULL));
    
    for (int i = 0; i < 10; i++) {
        a = (((unsigned long long)rand()) % (x - 1ull)) + 1ull;
        while (gcd(a, x) != 1) {
            a = (((unsigned long long)rand()) % (x - 1ull)) + 1ull;
        }

        ans = pow_mod(a, x - 1ull, x);

        if (ans != 1ull) {
            return 0;
        }
    }

    return 1;
}

int
main() {
    unsigned long long x;
    scanf("%llu", &x);

    printf("%d", ft(x));
    return 0;
}
