#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main() {
    unsigned long long num, res;
    unsigned long long cnt = 0;
    char* sieve;

    res = scanf("%llu", &num);
    assert(res == 1);

    sieve = (char*)malloc((num + 1) * sizeof(char));

    for (unsigned long long i = 2; i <= num; i++) {
        sieve[i] = 1;
    }

    for (unsigned long long i = 2; i <= num; i++) {
        if (sieve[i] == 0) {
            continue;
        }
        
        cnt += 1;
        for (unsigned long long j = i * i; j <= num; j += i) {
            sieve[j] = 0;
        }
    }

    printf("%llu", cnt);

    return 0;
}
