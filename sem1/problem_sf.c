#include <stdio.h>
#include <assert.h>

int fib[80] = {1, 2};

int calc_fib(int x) {
    int i = 1;
    int cnt = 0;

    while (fib[i] <= x) {
        fib[i + 1] = fib[i] + fib[i - 1];
        i += 1;
        cnt += 1;
    }

    return cnt;
}

void convert(int x, int cnt) {
    while (x > 0) {
        if (x - fib[cnt] >= 0) {
            x -= fib[cnt];
            cnt -= 1;
            printf("1");
        } else {
            cnt -= 1;
            printf("0");
        }
    }

    while (cnt >= 0) {
        printf("0");
        cnt -= 1;
    }
}

int main() {
    int x, res;;

    res = scanf("%d", &x);
    assert(res == 1);

    convert(x, calc_fib(x));

    return 0;
}
