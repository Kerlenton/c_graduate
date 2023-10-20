#include <stdio.h>
#include <stdlib.h>


struct sieve_t {
    int n;
    unsigned char *mod1;
    unsigned char *mod5;  
};

char check_mul(int x, int b) {
    if (x != 0 && x > 2147483647 / b)
        return 0;
    else
        return 1;
}

char check_add(int x, int b) {
    if (x > 0 && b > 2147483647 - x) {
        return 0;
    }
    else
        return 1;
}

void fill_sieve(struct sieve_t *sv) {
    sv->mod1[0] = 17;
    sv->mod5[0] = 32;

    for (int i = 1; i < sv->n; i++) {
        sv->mod1[i] = 0;
        sv->mod5[i] = 0;
    }
    
    for (int i = 0; i < sv->n * 8; i++) {
        int tmp1 = 6 * i + 1;
        int tmp5 = 6 * i + 5;

        char is_prime_tmp1 = !((sv->mod1[i / 8] >> (i % 8)) & 1);
        char is_prime_tmp5 = !((sv->mod5[i / 8] >> (i % 8)) & 1);
        
        if (is_prime_tmp1) {
            if (check_mul(tmp1, tmp1)) {
                for (int j = tmp1 * tmp1; j < sv->n * 48 + 1; ) {
                    sv->mod1[(j / 6) / 8] |= (1 << ((j / 6) % 8));
                    if (check_mul(6, tmp1) && check_add(j, 6 * tmp1)) {
                        j += 6 * tmp1;
                    } else {
                        break;
                    }
                }
            }

            if (check_mul(tmp1, tmp1) && check_mul(4, tmp1) && check_add(tmp1 * tmp1, 4 * tmp1)) {
                for (int j = tmp1 * tmp1 + 4 * tmp1; j < sv->n * 48 + 5; ) {
                    sv->mod5[(j / 6) / 8] |= (1 << ((j / 6) % 8));
                    if (check_mul(6, tmp1) && check_add(j, 6 * tmp1)) {
                        j += 6 * tmp1;
                    } else {
                        break;
                    }
                }
            }
        }

        if (is_prime_tmp5) {
            if (check_mul(tmp5, tmp5)) {
                for (int j = tmp5 * tmp5; j < sv->n * 48 + 1; ) {
                    sv->mod1[(j / 6) / 8] |= (1 << ((j / 6) % 8));
                    if (check_mul(6, tmp5) && check_add(j, 6 * tmp5)) {
                        j += 6 * tmp5;
                    } else {
                        break;
                    }
                }
            }
            
            if (check_mul(tmp5, tmp5) && check_mul(2, tmp5) && check_add(tmp5 * tmp5, 2 * tmp5)) {
                for (int j = tmp5 * tmp5 + 2 * tmp5; j < sv->n * 48 + 5; ) {
                    sv->mod5[(j / 6) / 8] |= (1 << ((j / 6) % 8));
                    if (check_mul(6, tmp5) && check_add(j, 6 * tmp5)) {
                        j += 6 * tmp5;
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

int is_prime(struct sieve_t *sv, unsigned n) {
    if ((n % 6) == 1) {
        return !((sv->mod1[(n / 6) / 8] >> ((n / 6) % 8)) & 1);
    } else if ((n % 6) == 5u) {
        return !((sv->mod5[(n / 6) / 8] >> ((n / 6) % 8)) & 1);
    } else if ((n < 4) && (n > 1)) {
        return 1;
    } else {
        return 0;
    }
}

unsigned find_prime(struct sieve_t *sv, unsigned n) {
    unsigned cnt = 0u;
    for (unsigned i = 1u; ; i++) {
        if (is_prime(sv, i)) {
            cnt += 1u;
        }

        if (cnt == n) {
            return i;
        }
    }
}

unsigned main() {
    struct sieve_t sv;
    sv.n = 30000000;
    sv.mod1 = (unsigned char*)malloc(sizeof(unsigned char) * sv.n);
    sv.mod5 = (unsigned char*)malloc(sizeof(unsigned char) * sv.n);
    fill_sieve(&sv);
    
    unsigned k;
    scanf("%u", &k);
    printf("%u\n", find_prime(&sv, k));
    return 0;
}
