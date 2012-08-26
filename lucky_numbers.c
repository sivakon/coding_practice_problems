#include <stdio.h>

const int MAX_LENGTH = 18;
const int MAX_SUM = 162;
const int MAX_SQUARE_SUM = 1458;
int primes[1459];
long long dyn_table[19][163][1459];

void gen_primes() {
    for (int i = 0; i <= MAX_SQUARE_SUM; ++i) {
        primes[i] = 1;
    }
    primes[0] = primes[1] = 0;

    for (int i = 2; i * i <= MAX_SQUARE_SUM; ++i) {
        if (!primes[i]) {
            continue;
        }
        for (int j = 2; i * j <= MAX_SQUARE_SUM; ++j) {
            primes[i*j] = 0;
        }
    }
}

void gen_table() {
    for (int i = 0; i <= MAX_LENGTH; ++i) {
        for (int j = 0; j <= MAX_SUM; ++j) {
            for (int k = 0; k <= MAX_SQUARE_SUM; ++k) {
                dyn_table[i][j][k] = 0;
            }
        }
    }
    dyn_table[0][0][0] = 1;

    for (int i = 0; i < MAX_LENGTH; ++i) {
        for (int j = 0; j <= 9 * i; ++j) {
            for (int k = 0; k <= 9 * 9 * i; ++k) {
                for (int l = 0; l < 10; ++l) {
                    dyn_table[i + 1][j + l][k + l*l] += dyn_table[i][j][k];
                }
            }
        }
    }
}

long long count_lucky (long long max) {
            long long result = 0;
    int len = 0;
    int split_max[MAX_LENGTH];
    while (max) {
        split_max[len] = max % 10;
        max /= 10;
        ++len;
    }
    int sum = 0;
    int sq_sum = 0;
    for (int i = len-1; i >= 0; --i) {
        long long step_result = 0;
        for (int l = 0; l < split_max[i]; ++l) {
            for (int j = 0; j <= 9 * i; ++j) {
                for (int k = 0; k <= 9 * 9 * i; ++k) {
                    if (primes[j + l + sum] && primes[k + l*l + sq_sum]) {
                        step_result += dyn_table[i][j][k];
                    }
                }
            }
        }
        result += step_result;

        sum += split_max[i];
        sq_sum += split_max[i] * split_max[i];
    }

    if (primes[sum] && primes[sq_sum]) {
        ++result;
    }

    return result;
}

int main(int argc, char** argv) {
    gen_primes();
    gen_table();

    int cases = 0;
    scanf("%d", &cases);
    for (int i = 0; i < cases; ++i) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", count_lucky(b) - count_lucky(a-1));
    }
    return 0;
}