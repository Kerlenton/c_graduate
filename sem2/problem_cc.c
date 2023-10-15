#include <stdio.h>
#include <limits.h>

char is_prime(long long x) {
    if (x < 2)
        return 0;

    for (long long i = 2; i * i <= x; i++) {
        if ((x % i) == 0)
            return 0;
    }

    return 1;
}

char is_circular_prime(long long x) {
    char digits[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    char cnt = 0;

    while (x > 0) {
        digits[cnt++] = x % 10;
        x /= 10;
    }

    for (char i = 0; i < cnt; i++) {
        long long num = 0;
        long long deg = 1;

        for (char j = i; j < i + cnt; j++) {
            num += deg * digits[j % cnt];
            deg *= 10;
        }

        if (!is_prime(num)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    long long N, x = 0, y = LLONG_MAX;
    scanf("%lld", &N);
    
    for (long long i = N - 1; i >= 0; i--) {
        if (is_circular_prime(i)) {
            x = i;
            break;
        }
    }

    for (long long i = N + 1; i <= N + (N - x); i++) {
        if (is_circular_prime(i)) {
            y = i;
            break;
        }
    }

    if ((x == 0) || ((N - x) > (y - N))) {
        printf("%lld", y);
    } else {
        printf("%lld", x);
    }

    return 0;
}
