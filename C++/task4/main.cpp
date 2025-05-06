#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cout << "Введите свои n и m: ";
    cin >> n >> m;

    vector<int> a(n);
    vector<int> prefix_sum(n + 1, 0);  // префиксные суммы
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    vector<int> dp(n + 1, INT_MIN);  // dp[i] - макс разница очков от позиции i
    dp[n] = 0; // если всё удалено, разность 0

    // Обрабатываем позиции с конца к началу
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= m && i + j <= n; ++j) {
            int sum = prefix_sum[i + j] - prefix_sum[i]; // сумма взятых чисел
            dp[i] = max(dp[i], sum - dp[i + j]); // макс разность очков
        }
    }

    cout << (dp[0] > 0 ? 1 : 0) << endl;
}
