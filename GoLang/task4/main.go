package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Print("Введите свои n и m: ")
	fmt.Scan(&n, &m)

	a := make([]int, n)
	prefix_sum := make([]int, n + 1)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		prefix_sum[i + 1] = prefix_sum[i] + a[i]
	}

	dp := make([]int, n + 1)
	dp[n] = 0

	for i := n - 1; i >= 0; i-- {
		for j := 1; j <= m && i + j <= n; j++ {
			sum := prefix_sum[i + j] - prefix_sum[i]
			dp[i] = max(dp[i], sum - dp[i + j])
		}
	}

	if dp[0] > 0 {
		fmt.Println(1)
	} else {
		fmt.Println(0)
	}
}