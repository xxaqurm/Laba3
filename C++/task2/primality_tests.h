#ifndef PRIMALITY_TESTS_H  // Защита от двойного включения
#define PRIMALITY_TESTS_H

#include <vector>

using namespace std;
using ll = long long;

bool miller_test(ll n, vector<pair<int, int>> factors, int t = 10);
bool ponclickton_test();

#endif