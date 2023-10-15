#include <stdio.h>

unsigned long long gcd(unsigned long long a,
                       unsigned long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

unsigned long long lcm(unsigned long long a,
                       unsigned long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    unsigned long long N;
    unsigned long long ans = 2;
    scanf("%llu", &N);


    
    for (unsigned long long i = 2; i <= N; i++) {
        ans = lcm(ans, i);
    }

    printf("%llu", ans);

    return 0;
}
