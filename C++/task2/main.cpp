#include "utils.h"
#include "primality_tests.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int p = 2;
    int n = 500;
    vector<int> prime_nums = eratosthenes_sieve(p, n);  // таблица простых числе меньших 500

    for (int i = -100; i < 500; i++) {
        vector<pair<int,int>> factors = prime_factors(i - 1);
        if (miller_test(i, factors, 7)) {
            cout << i << " - It's a prime number!" << endl;
        }
    }

    return 0;
}
