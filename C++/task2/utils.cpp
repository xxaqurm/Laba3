#include "utils.h"

#include <vector>

using namespace std;
using ll = long long;

vector<int> eratosthenes_sieve(int p, int n) {
    /* Создание решета Эратосфена */
    vector<int> nums;
    for (int i = p; i <= n; i++) {
        nums.push_back(i);
    }

    for (int i = p; i * i < n - p; i++) {
        for (int j = i * i; j < n; j += i) {
            nums[j - p] = 0;
        }
    }

    vector<int> res;
    for (int i = 0; i < n - p; i++) {
        if (nums[i]) {
            res.push_back(nums[i]);
        }
    }
    return res;
}

ll mod_pow(ll a, ll b, ll m) {
    /* Функция для выполнения операции (a^b) mod m */
    ll result = 1 % m;
    ll base = a % m;

    while (b > 0) {
        if (b & 1) {  // если степень не четная
            result = (result * base) % m;
        }
        base = (base * base) % m;
        b >>= 1;
    }
    return result;
}

vector<pair<int, int>> prime_factors(ll n) {
    /* Каноническое разложение числа */
    vector<pair<int, int>> factors;
    if (n == 0) return factors;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int exponent = 0;
            while (n % i == 0) {
                exponent++;
                n /= i;
            }
            factors.push_back({i, exponent});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}