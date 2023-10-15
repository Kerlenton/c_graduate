void fill_sieve(struct sieve_t *sv) {
    for (unsigned long long i = 2; i * i < (unsigned long long) sv->n; i++) {
        if (sv->s[i] == 0) {
            for (unsigned long long j = i * i; j < (unsigned long long) sv->n; j += i) {
                sv->s[j] = 1;
            }
        }
    }
}

int nth_prime(struct sieve_t *sv, int N) {
    int i = 2;
    
    for (; N; i++) {
        if (!sv->s[i]) {
            --N;
        }
    }

    return i - 1;
}
