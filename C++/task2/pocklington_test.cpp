#include "utils.h"

#include <vector>
#include <random>
#include <set>

using namespace std;
using ll = long long;

bool pocklington_test(ll n, vector<pair<int, int>> partical_factors, ll r, int t) {
    /* Тест Поклингтона */
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> rv (2, n - 1);

    set<ll> random_values;
    while (random_values.size() < t) {  // пункт 1
        random_values.insert(rv(gen));
    }

    for (auto& aj : random_values) {  // пункт 2
        if (mod_pow(aj, n - 1, n) != 1) {
            return false;
        }
    }

    for (auto& aj : random_values) {  // пункт 3
        bool thrid_point = true;
        for (auto& pair_elms : partical_factors) {
            if (mod_pow(aj, (int)((n - 1) / pair_elms.first), n) == 1) {
                thrid_point = false;
                break;
            }
        }
        if (thrid_point) {
            return true;
        }
    }
    return false;
}