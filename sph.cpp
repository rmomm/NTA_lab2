#include "Header.h"

long long mod_pow(long long a, long long b, long long mod) {
    long long r = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1)
            r = (r * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return r;
}

long long extgcd(long long a, long long b, long long& x, long long& y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extgcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

long long mod_inv(long long a, long long mod) {
    long long x, y;
    long long g = extgcd(a, mod, x, y);
    if (g != 1) { 
        return -1; 
    }
    return (x % mod + mod) % mod;
}


int brute_force(long long a, long long b, long long p) {
    for (long long x = 0; x < p; x++) {
        if (mod_pow(a, x, p) == b) {
            return x; 
        }
    }
    return -1;
}


vector<pair<long long, long long>> factorize(long long n) {
    vector<pair<long long, long long>> f;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            long long c = 0;
            while (n % i == 0) {
                n /= i;
                c++;
            }
            f.push_back({ i, c });
        }
    }

    if (n > 1) {
        f.push_back({ n, 1 });
    }
       

    return f;
}

long long crt(vector<long long> r, vector<long long> m) {
    long long M = 1;
    for (auto x : m) 
        M *= x;

    long long x = 0;

    for (int i = 0; i < r.size(); i++) {
        long long Mi = M / m[i];
        long long inv = mod_inv(Mi % m[i], m[i]);

        x = (x + r[i] * Mi % M * inv % M) % M;
    }

    return (x + M) % M;
}

long long spp(long long a, long long b, long long p, long long r, long long l, long long n) {

    long long x = 0;
    long long cur_b = b;
    long long p_k = 1;

    for (int k = 0; k < l; k++) {

        long long exp = n / (p_k * r);
        long long step = mod_pow(a, n / (p_k * r), p);

        vector<long long> table(r);
        table[0] = 1;

        for (long long j = 1; j < r; j++) {
            table[j] = (table[j - 1] * step) % p;
        }

        long long left = mod_pow(cur_b, exp, p);

        long long x_i = 0;

        for (long long j = 0; j < r; j++) {
            if (table[j] == left) {
                x_i = j;
                break;
            }
        }

        x += x_i * p_k;

        long long dec = mod_pow(a, x_i * p_k, p);
        cur_b = (cur_b * mod_inv(dec, p)) % p;

        p_k *= r;
    }

    if (mod_pow(a, x, p) != b) {
        return brute_force(a, b, p);
    }

    return x;
}


long long sph(long long a, long long b, long long p) {
    long long n = p - 1;

    auto factors = factorize(n);

    vector<long long> res;
    vector<long long> mod;

    for (auto it : factors) {
        long long p_i = it.first;
        long long l_i = it.second;

        long long m_i = 1;
        for (int i = 0; i < l_i; i++) { 
            m_i *= p_i; 
        }

        long long x_i = spp(a, b, p, p_i, l_i, n);

        res.push_back(x_i);
        mod.push_back(m_i);
    }

    return crt(res, mod);
}

