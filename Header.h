#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long mod_pow(long long a, long long b, long long mod);
long long extgcd(long long a, long long b, long long& x, long long& y);
long long mod_inv(long long a, long long mod);
int brute_force(long long a, long long b, long long p);
vector<pair<long long, long long>> factorize(long long n);
long long crt(vector<long long> r, vector<long long> m);
long long order(long long a, long long p);
long long spp(long long a, long long b, long long p, long long r, long long l, long long n);
long long sph(long long a, long long b, long long p);

