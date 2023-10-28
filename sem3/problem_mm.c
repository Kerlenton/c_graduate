#include <stdio.h>
#include <limits.h>

int main() {
    unsigned long long size;
    long long tmp;
    long long mx = LLONG_MIN;
    long long mn = LLONG_MAX;
    
    scanf("%llu", &size);

    for (unsigned long long i = 0; i < size; i++) {
        scanf("%lld", &tmp);
        
        if (mx < tmp) {
            mx = tmp;
        }

        if (mn > tmp) {
            mn = tmp;
        }
    }
    
    if (size == 0) {
        printf("%d %d", 0, 0);
    } else {
        printf("%lld %lld", mn, mx);
    }

    return 0;
}
