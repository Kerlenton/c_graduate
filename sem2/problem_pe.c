#include <stdlib.h>
#include <stdio.h>

struct sieve_t {
  int n;
  unsigned char *s;
};

void fill_sieve(struct sieve_t *sv) {
    if (sv->n == 0) {
        return;
    }

    sv->s[0] = 83;
    for (int i = 0; i * i < sv->n * 8; i++) {
        if (!((sv->s[i / 8] >> (i % 8)) & 1)) {
            for (int j = i * i; j < sv->n * 8; j += i) {
                sv->s[j / 8] |= 1 << (j % 8);
            }
        }
    }
}

int is_prime(struct sieve_t *sv, unsigned n) {
    return !((sv->s[n / 8] >> (n % 8)) & 1);
}
