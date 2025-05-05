#ifndef UTILS_H  // Защита от двойного включения
#define UTILS_H

#include <vector>

using namespace std;
using ll = long long;

vector<int> eratosthenes_sieve(int p, int n);
vector<pair<int, int>> prime_factors(ll n);
ll mod_pow(ll a, ll b, ll m);

#endif