package main

import (
	"fmt"
	"math/rand"
	"time"
)

func algorithm1(roundNumber int, own, enemy []bool) []bool {
	if roundNumber == 0 {
		return append(own, true)
	}
	return append(own, false)
}

func algorithm2(roundNumber int, own, enemy []bool) []bool {
	rand.Seed(time.Now().UnixNano())
	action := rand.Intn(2) == 1
	return append(own, action)
}

func algorithm3(roundNumber int, own, enemy []bool) []bool {
	if roundNumber > 0 && !enemy[roundNumber-1] {
		return append(own, true)
	}
	return append(own, false)
}

func main() {
	rand.Seed(time.Now().UnixNano())
	n := rand.Intn(101) + 100

	var first, second []bool
	check1, check2 := 0, 0

	for i := 0; i < n; i++ {
		// Вызывается одна из комбинаций алгоритмов

		// 3 и 2 алгоритм
		//first =	algorithm3(i, first, second);
		//second = algorithm2(i, second, first);

		// 2 и 1 алгоритм
		first = algorithm2(i, first, second)
		second = algorithm1(i, second, first)

		// 1 и 3 алгоритм
		//first = algorithm3(i, first, second);
		//second = algorithm2(i, second, first);

		// Проверяется, какие действия совершили игроки в текущем раунде и начисляются очки в соответствии с правилами игры
		if first[i] && second[i] { // оба выбирают сотрудничество
			check1 += 24
			check2 += 24
		} else if first[i] && !second[i] { // сотрудничество и предательство
			check1 += 0
			check2 += 20
		} else if !first[i] && second[i] { // предательство и сотрудничество
			check1 += 20
			check2 += 0
		} else if !first[i] && !second[i] { // оба предательство
			check1 += 4
			check2 += 4
		}

		// Вывод на экран текущих действий игроков и их очков
		fmt.Println(first[i], second[i], check1, check2)
	}
}