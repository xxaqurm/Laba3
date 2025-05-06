#include "utils.h"
#include "primality_tests.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int p = 2;
    int n = 500;
    vector<int> prime_nums = eratosthenes_sieve(p, n);  // таблица простых числе меньших 500

    vector<int> my_nums = {13, 29, 61, 97, 157, 173, 179, 353};
    vector<vector<pair<int, int>>> my_factors = {{{2, 2}}, {{7, 1}}, {{3, 1}, {5, 1}}, {{3, 1}, {2, 2}}, {{13, 1}}, {{43, 1}}, {{89, 1}}, {{2, 1}, {11, 1}}};
    vector<int> my_r = {3, 4, 4, 8, 8, 4, 2, 16};

    for (int i = 0; i < my_nums.size(); i++) {
        if (pocklington_test(my_nums[i], my_factors[i], my_r[i])) {
            cout << my_nums[i] << " - Its primary number!" << endl;
        }
    }
    return 0;
}