#include "utils.h"
#include "primality_tests.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t = 4;
    int q = 3;

    cout << gost_test(t, q);
    return 0;
}