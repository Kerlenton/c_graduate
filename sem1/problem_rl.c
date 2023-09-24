#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long gcd(long long x, 
                       long long y) {
    if (x < 0)
        x = -x;

    if (y < 0)
        y = -y;

    while (y != 0) {
        long long tmp = x;
        x = y;
        y = tmp % x;
    }
    
    assert(x > 0);
    return x;
}

int main() {
    long long x = 0, y = 0, g;
    int res;

    res = scanf("%lli %lli", &x, &y);
    assert(res == 2);
    
    g = gcd(x, y);
    printf("%lli\n", g);
    return 0;
}
