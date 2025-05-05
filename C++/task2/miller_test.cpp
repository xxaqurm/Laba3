#include "primality_tests.h"
#include "utils.h"

#include <vector>
#include <random>
#include <cmath>
#include <set>

using namespace std;
using ll = long long;

bool miller_test(ll n, vector<pair<int, int>> factors, int t) {
    /* Проверка числа на простоту тестом Миллера */
    if (n == 2 || n == 3 || n == 5 || n == 7) {
        return true;
    } else if (n < 9) return false;

    random_device rd;   // источник энтропии
    mt19937 gen(rd());  // генератор Мерсенна-Твистера с инициализацией
    uniform_int_distribution<> rv(2, n - 1);

    set<ll> random_values;
    while (random_values.size() < t) {  // генерируем t случайных aj
        random_values.insert(rv(gen));
    }

    for (auto& aj : random_values) {  // первое условие
        if (mod_pow(aj, n - 1, n) != 1) {
            return false;
        }
    }

    for (auto& pair_elms : factors) {  // второе условие  # перебираем пары #
        bool second_condition = true;
        for (auto& aj : random_values) {
            if (mod_pow(aj, (int)((n - 1) / pair_elms.first), n) != 1) {
                second_condition = false;
                break;
            }
        }
        if (second_condition) {
            return false;
        }
    }
    return true;
}