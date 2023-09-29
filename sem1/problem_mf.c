#include <stdio.h>
#include <assert.h>

void pow_mod(unsigned a[4], unsigned b, unsigned n) {
    unsigned mult[4];
    unsigned prod[4] = {1, 0, 0, 1};
    unsigned tmp[4];
    unsigned r, c;

    for (unsigned i = 0; i < 4; i++) {
        mult[i] = a[i] % n;
    }

    while (b > 0) {
        if ((b % 2) == 1) {
            for (unsigned i = 0; i < 4; i++) {
                r = i / 2;
                c = i % 2;

                tmp[i] = (((prod[r * 2] * mult[c]) % n) + 
                        ((prod[r * 2 + 1] * mult[c + 2]) % n)) % n;
            }

            for (unsigned i = 0; i < 4; i++) {
                prod[i] = tmp[i];
            }

            b = b - 1;;
        }
        
        for (unsigned i = 0; i < 4; i++) {
            r = i / 2;
            c = i % 2;

            tmp[i] = (((mult[r * 2] * mult[c]) % n) + 
                    ((mult[r * 2 + 1] * mult[c + 2]) % n)) % n;
        }

        for (unsigned i = 0; i < 4; i++) {
            mult[i] = tmp[i];
        }

        b = b / 2;
    }

    for (unsigned i = 0; i < 4; i++) {
        printf("%u ", prod[i]);
    }
}

int main() {
    unsigned a[4], b, n, res;

    for (int i = 0; i < 4; i++) {
        res = scanf("%u", a + i);
        assert(res == 1);    
    }

    res = scanf("%u%u", &b, &n);
    assert(res == 2);

    pow_mod(a, b, n);

    return 0;
}
