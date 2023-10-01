#include <stdio.h>
#include <assert.h>

unsigned is_prime(unsigned n) {
    if (n < 2) return 0;

    for (int j = 2; j * j <= n; j++) {
        if ((n % j) == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    unsigned num, res;
    unsigned cnt = 0;
    unsigned cur = 2;

    res = scanf("%u", &num);
    assert(res == 1);

    while (cnt != num) {
        if (is_prime(cur)) {
            cnt += 1;
        }

        cur += 1;
    }

    printf("%u", cur - 1u);

    return 0;
}
