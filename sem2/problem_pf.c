#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

    if (x == 1ull) {
        return 0;   
    }

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

unsigned long long max_fib(unsigned long long k, unsigned long long n) {
    unsigned long long max_prime = 0;
    unsigned long long f0 = 0;
    unsigned long long f1 = 1;
    unsigned long long tmp = 0;

    while (f1 < (unsigned long long)pow(2ull, 60ull)) {
        if (ft(f1)) {
            max_prime = f1;
        }

        tmp = f1;
        f1 = k * f1 + n * f0;
        f0 = tmp;
    }

    return max_prime;
}

int
main() {
    unsigned long long k, n;
    scanf("%llu %llu", &k, &n);
    printf("%llu", max_fib(k, n));

    return 0;
}
