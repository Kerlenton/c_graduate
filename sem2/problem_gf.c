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

int main() {
    long long N, mx_a = 1, mx_b = 1;
    long long mx = 0;

    scanf("%lld", &N);

    for (long long a = -N + 1; a < N; a++) {
        for (long long b = -N + 1; b < N; b++) {
            long long cnt = 0;

            while (is_prime(cnt * cnt + a * cnt + b)) {
                cnt += 1;
            }

            if (cnt >= mx) {
                mx = cnt;
                mx_a = a;
                mx_b = b;
            }
        }
    }

    printf("%lld %lld %lld", mx_a, mx_b, mx);

    return 0;
}
