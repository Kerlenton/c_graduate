#include <stdio.h>
#include <assert.h>

void convert(unsigned int x, unsigned int y) {
    unsigned int buffer[100];
    unsigned int i = 0;

    while (x > 0) {
        buffer[i] = x % y;
        x /= y;
        i += 1;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%u", buffer[j]);
    }
}

int main() {
    unsigned int x, y, res;

    res = scanf("%u%u", &x, &y);
    assert(res == 2);

    convert(x, y);

    return 0;
}
