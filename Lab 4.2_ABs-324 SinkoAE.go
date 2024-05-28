package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

// Функция для проверки високосности года
func isLeapYear(year int) bool {
	return year%4 == 0 && (year%100 != 0 || year%400 == 0)
}

func main() {
	// Инициализация генератора случайных чисел
	rand.Seed(time.Now().UnixNano())

	// Размер массива
	const n = 10

	// Пункт 1: Инициализация массива случайными числами из диапазона [100, 200]
	arr1 := make([]int, n)
	for i := 0; i < n; i++ {
		arr1[i] = 100 + rand.Intn(101)
	}

	// Вывод на экран результата для пункта 1
	fmt.Println("Пункт 1: Исходный массив:")
	fmt.Println(arr1)

	// Пункт 2: Поиск второго по величине элемента и сумма элементов между минимальным и вторым по величине
	sort.Ints(arr1)

	// Вывод на экран отсортированного массива из пункта 1
	fmt.Println("Пункт 2: Отсортированный массив:")
	fmt.Println(arr1)

	secondMax := arr1[n-2]
	min := arr1[0]
	sum := 0
	for _, num := range arr1 {
		if num > min && num < secondMax {
			sum += num
		}
	}

	// Вывод результата для пункта 2
	fmt.Println("Пункт 2: Минимальный элемент:", min)
	fmt.Println("Пункт 2: Второй по величине элемент:", secondMax)
	fmt.Println("Пункт 2: Сумма элементов между минимальным и вторым по величине:", sum)

	// Пункт 3: Создание двух массивов диапазона [-50, 50] и заполнение третьего массива суммой четных и разницей нечетных элементов
	arr2 := make([]int, n)
	arr3 := make([]int, n)
	arr4 := make([]int, n)
	for i := 0; i < n; i++ {
		arr2[i] = -50 + rand.Intn(101)
		arr3[i] = -50 + rand.Intn(101)
		if i%2 == 0 {
			arr4[i] = arr2[i] + arr3[i]
		} else {
			arr4[i] = arr2[i] - arr3[i]
		}
	}

	// Вывод изначальных данных для пункта 3
	fmt.Println("Пункт 3: Исходные массивы:")
	fmt.Println(arr2)
	fmt.Println(arr3)

	// Вывод результата для пункта 3
	fmt.Println("Пункт 3: Результат:")
	fmt.Println(arr4)

	// Пункт 4: Подсчет количества повторений каждого элемента в первом массиве
	count := make(map[int]int)
	for _, num := range arr1 {
		count[num]++
	}

	// Вывод результата для пункта 4
	fmt.Println("Пункт 4: Количество повторений каждого элемента в массиве из пункта 1:")
	for num, cnt := range count {
		fmt.Println(num, ":", cnt)
	}

	// Пункт 5: Получение диапазона лет и вывод високосных годов в этом диапазоне
	var startYear, endYear int
	fmt.Print("Пункт 5: Введите начальный год: ")
	fmt.Scan(&startYear)
	fmt.Print("Пункт 5: Введите конечный год: ")
	fmt.Scan(&endYear)

	var leapYears []int
	for year := startYear; year <= endYear; year++ {
		if isLeapYear(year) {
			leapYears = append(leapYears, year)
		}
	}

	// Вывод результата для пункта 5
	fmt.Printf("Пункт 5: Високосные года в диапазоне от %d до %d:\n", startYear, endYear)
	fmt.Println(leapYears)
}