#include "utils.h"

#include <random>
#include <cmath>
#include <iostream>  //fjdklsjlskdjflksjdf
using namespace std;
using ll = long long;

ll gost_test(int t, ll q) {  // t - требуемая размерность простого числа (в битах), q - простое число (|q| = ceil(t / 2))
    /* ГОСТ Р 34.10-94 */
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> rv(0.0, 1.0);

    double eps = 0.5;
    int u = 0;

    ll p = pow(2, t) + 1;
    ll n = 0;
    
    while (p > pow(2, t)) {
        eps = rv(gen);
        if (eps == 0 || eps == 1) {
            continue;
        }

        n = ceil((int)pow(2, t - 1) / q) + ceil((int)pow(2, t - 1) * eps / q);
        if (n & 1) {
            n++;
        }
        cout << "N: " << n << endl;
        p = (n + u) * q + 1;  // кандидат в простые
    }
    
    while (!(mod_pow(2, p - 1, p) == 1 && mod_pow(2, n + u, p) != 1)) {
        u += 2;
        p = (n + u) * q + 1;
    }
    return p;
}