package main

import (
	"fmt"
	"math"
)

const E = 0.0001 // заданная точность вычислений по условию

// Функция 𝑥 𝑙𝑛(𝑥 + 1) = 1 (в соответствии с вариантом)
func f(x float64) float64 {
	return (x * math.Log(x+1) - 1)
}

// Производная функции f(x)
func f1(x float64) float64 {
	return x / (x + 1) + math.Log(x + 1)
}

// Метод половинного деления
func halfDivision(a, b float64) (float64, int) {
	if f(a)*f(b) >= 0 {
		fmt.Println("Неверный интервал")
		return 0, 0
	}

	var c, k float64
	for math.Abs(b-a) >= E {
		c = (a + b) / 2
		fmt.Printf("Итерация %d: a=%.4f, b=%.4f, c=%.4f, f(c)=%.4f\n", int(k), a, b, c, f(c))
		if f(c) == 0 {
			break
		} else if f(c)*f(a) < 0 {
			b = c
		} else {
			a = c
		}
		k++
	}

	return c, int(k)
}

// Метод Ньютона
func newtonMethod(x0 float64) (float64, int) {
	var x1, k float64
	x1 = x0 - f(x0)/f1(x0)

	for math.Abs(x1-x0) >= E {
		fmt.Printf("Итерация %d: x0=%.4f, x1=%.4f, f(x1)=%.4f\n", int(k), x0, x1, f(x1))
		x0 = x1
		x1 = x0 - f(x0)/f1(x0)
		k++
	}

	return x0, int(k)
}

// Метод простых итераций
func simpleIterations(x0 float64) (float64, int) {
	var x1, k float64
	x1 = 1 / math.Log(x0+1)

	for math.Abs(x1-x0) > E {
		fmt.Printf("Итерация %d: x0=%.4f, x1=%.4f, f(x1)=%.4f\n", int(k), x0, x1, f(x1))
		x0 = x1
		x1 = 1 / math.Log(x0+1)
		k++
	}

	return x0, int(k)
}

func main() {
	var roots []float64

	fmt.Println("Процесс уточнения корня методом половинного деления с точностью до E")
	root, s1 := halfDivision(-1, 1)
	roots = append(roots, root)

	fmt.Println("\nПроцесс уточнения корня методом Ньютона с точностью до E")
	root, s2 := newtonMethod(10)
	roots = append(roots, root)

	fmt.Println("\nПроцесс уточнения корня методом простых итераций с точностью до E")
	root, s3 := simpleIterations(2)
	roots = append(roots, root)

	fmt.Println("\nВсе найденные корни уравнения")
	for _, root := range roots {
		fmt.Printf("%f ", root)
	}

	fmt.Println("\n\nСкорости сходимости: ")
	fmt.Printf("\nметод половинного деления: %d итераций\n", s1)
	fmt.Printf("\nметод Ньютона: %d итераций\n", s2)
	fmt.Printf("\nметод простых итераций: %d итераций\n", s3)
}