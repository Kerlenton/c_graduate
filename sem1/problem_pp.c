#include <stdio.h>
#include <assert.h>

unsigned get_pisano_period(unsigned m) {
    unsigned period = 0u;
    unsigned first = 0u;
    unsigned second = 1u;

    while (second != 0 || ((first + second) != 1)) {
        unsigned tmp = second;
        second = (first + second) % m;
        first = tmp;
        period += 1;
    }

    return period + 1;
}

unsigned fib_mod(unsigned long long x, unsigned m) {
    unsigned first = 0u;
    unsigned second = 1u;
    
    x = x % get_pisano_period(m);

    if (x == 0)
        return 0u;

    for (unsigned i = 2; i <= x; i++) {
        unsigned tmp = second;
        second = (first + second) % m;
        first = tmp;
    }

 
    return second;
}

int main() {
    unsigned long long x;
    unsigned m, period, res;

    res = scanf("%llu%u", &x, &m);
    assert(res == 2);

    period = get_pisano_period(m);
    printf("%u %u", fib_mod(x % period, m), period);

    return 0;
}
