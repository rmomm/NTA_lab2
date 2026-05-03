#include "Header.h"

long long mod_pow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

long long mod_inv(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}


int brute_force(long long a, long long b, long long p) {
    for (long long x = 0; x < p; x++) {
        if (mod_pow(a, x, p) == b)
            return x;
    }
    return -1;
}