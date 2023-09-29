int next_turn(int total, int possible) {
    int fib[80] = {1, 2};
    int i = 1;
    int cnt = 0;
    int tmp = 0;

    if (total <= possible) {
        return total;
    }

    while (fib[i] <= total) {
        fib[i + 1] = fib[i] + fib[i - 1];
        i += 1;
        cnt += 1;
    }

    while (total > 0) {
        if (total - fib[cnt] >= 0) {
            total -= fib[cnt];
            tmp = fib[cnt];
            cnt -= 1;
        } else {
            cnt -= 1;
        }
    }

    if (tmp <= possible) {
        return tmp;
    } else {
        return 1;
    }
}
