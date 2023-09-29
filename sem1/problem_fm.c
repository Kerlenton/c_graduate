#include <stdio.h>
#include <assert.h>

unsigned fib(unsigned x, unsigned m) {
    unsigned first = 0u;
    unsigned second = 1u;

    if (x == 0)
        return 0ull;

    for (unsigned i = 2; i <= x; i++) {
        unsigned tmp = second;
        second = (first + second) % m;
        first = tmp;
    }

    return second;
}

int main() {
    unsigned x, m, res;

    res = scanf("%u%u", &x, &m);
    assert(res == 2);

    printf("%u", fib(x, m));

    return 0;
}
