#include <stdio.h>

int main() {
    unsigned long long N;
    signed char mn = -1;
    signed char mx = -1;
    signed char cnt = 0;
    scanf("%llu", &N);

    while (N > 0) {
        if ((N % 2) == 1 && (mn == -1)) {
           mn = cnt;
           mx = cnt;
        } else {
            mx = cnt;
        }

        cnt += 1;
        N /= 2;
    }

    if ((mn == -1) && (mx == -1)) {
        printf("%d", -1);
    } else {
        printf("%u %u", mx, mn);
    }

    return 0;
}
