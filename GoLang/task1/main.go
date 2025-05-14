package main

import (
	"fmt"
	"math"
	"strings"
)

func print_table(points [][]float64) {
	/* Выводит таблицу значений */
	const cell_width int = 5
	border := "+-+"

	for i := 0; i < len(points); i++ {
		border += strings.Repeat("-", cell_width) + "+"
	}

	fmt.Println(border)

	fmt.Printf("|x")
	for _, point := range points {
		fmt.Printf("|%-*.1f", cell_width, point[0])
	}
	fmt.Println("|")

	fmt.Println(border)

	fmt.Printf("|y")
	for _, point := range points {
		fmt.Printf("|%-*.1f", cell_width, point[1])
	}
	fmt.Println("|")

	fmt.Println(border)
}

func main() {
	var x_start float64 = -10
	var x_finish float64 = 8
	var dx float64 = 0.5
	var change bool = false

	fmt.Printf("Значения по умолчанию: \nx начальное: %.1f \nx конечное: %.1f \ndx: %.1f\n", x_start, x_finish, dx)
	fmt.Print("Хотите ли вы изменить значения по умолчанию? (1 - да / 0 - нет): ")
	fmt.Scan(&change)

	if change {
		fmt.Print("\nВведите х начальное, х конечное и dx (xs xf dx): ")
		fmt.Scan(&x_start, &x_finish, &dx)
	}

	var xy_values [][]float64
	
	for x := x_start; x <= x_finish; x += dx {
		var y float64 = 0
		if x >= -10 && x <= -6 {
			if x == -8 {
				y = 0
			} else {
				y = math.Sqrt(4 - math.Pow(x + 8, 2))
			}
		} else if x > -6 && x <= 2 {  // наклонная прямая
			y = 0.5 * x + 1
		} else if x > 2 && x <= 6 {  // y = 0
			y = 0
		} else if x > 6 && x <= 8 {  // парабола
			y = math.Pow(x - 6, 2)
		} else {
			y = 0
		}
		xy_values = append(xy_values, []float64{x, y})
	}
	print_table(xy_values)
}