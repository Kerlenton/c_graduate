#include <stdio.h>
#include <assert.h>

void convert(unsigned num) {
    unsigned fact = 2;
    unsigned i = 1;
    unsigned buffer[100];

    while (num > 0) {
        buffer[i - 1] = (num % fact) / (fact / (i + 1));
        num -= num % fact;
        ++i;
        fact *= (i + 1);
    }

    for (int j = i - 2; j >= 0; j--) {
        printf("%u.", buffer[j]);
    }
}

int main() {
    unsigned num, res;

    res = scanf("%u", &num);
    assert(res == 1);

    convert(num);

    return 0;
}
