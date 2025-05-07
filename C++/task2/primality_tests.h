#ifndef PRIMALITY_TESTS_H  // Защита от двойного включения
#define PRIMALITY_TESTS_H

#include <vector>

using namespace std;
using ll = long long;

bool miller_test(ll n, vector<pair<int, int>> factors, int t = 7);
bool pocklington_test(ll n, vector<pair<int, int>> partical_factors, ll r, int t = 7);
ll gost_test(int t, ll q);

#endif