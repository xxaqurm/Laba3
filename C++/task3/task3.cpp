#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = 1;
    int b = 1;
    int iter = 10000000;

    double sum = 0;
    for (int a = 1; a <= 10; a++) {
        for (int b = 1; b <= 10; b++) {
            for (int n = 0; n < iter; n++) {
                sum += pow(n, a) / pow(b, n);
            }
            cout << "a: " << a << " | " << "b: " << b << "| sum: " << sum << endl;
            sum = 0;
        }
    }
}