package main

import (
	"fmt"
	"math"
)

func compute_series_sum(a float64, b float64) float64 {
	/* Находит сумму 1000 итераций */
	iters := 1000.0
	var sum float64 = 0
	for n := 1.0; n <= iters; n++ {
		sum += math.Pow(n, a) / math.Pow(b, n)
	}
	return sum
}

func is_rational(x float64, eps float64) (int, int, int) {
	/* Проверяет число на рациональность */
	var denominator float64 = 1
	var numerator float64 = 1
	var difference float64 = math.Abs(x - (numerator / denominator))
	iters := 100

	for i := 0; i <= iters; i++ {
		if numerator / denominator < x {
			numerator++
		} else {
			denominator++
		}
		difference = math.Abs(x - (numerator / denominator))
		if difference < eps {
			return int(numerator), int(denominator), 1
		}
	}
	return int(numerator), int(denominator), 0
}

func main() {
	a := 1
	b := 1
	fmt.Print("Ввведите свои a и b: ")
	fmt.Scan(&a, &b)

	if b == 1 {
		fmt.Println("Infinity")
	} else {
		var total float64 = compute_series_sum(float64(a), float64(b))
		var eps float64 = math.Pow(10, -10)

		numerator, denominator, state := is_rational(total, eps)

		if state == 0 {
			fmt.Println("Irrational")
		} else {
			fmt.Printf("%d/%d \n", numerator, denominator)
		}
	}
}