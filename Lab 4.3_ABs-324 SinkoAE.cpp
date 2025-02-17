﻿// Lab 4.3_ABs-324 SinkoAE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <vector>
#include <locale.h> // подключение библиотеки для задач связанных из локализацией

using namespace std;	// использование стандартного пространства имен

const int n1 = 50, n2 = 100, n3 = 1000;	// константы для размеров массивов


void filling(int* arr, int n) {
	random_device rd;	// генерация случайного числа
	mt19937_64 gen(rd());	// инициализация генератора случайных чисел mt19937_64 с помощью rd
	uniform_int_distribution<> dist(1, 100);	// создание равномерного распределения от 1 до 100
	// Заполнение массива случайными числами
	for (int i = 0; i < n; i++) {
		arr[i] = dist(gen);
	}
}

int X2(int arr[], int n) {
// выполняет задачу оценки распределения значений элементов массива и возвращает статистический критерий хи-квадрат,
// который может использоваться для проверки гипотезы о равномерном распределении значений,
// если значение x меньше некоторого критического значения, гипотеза о равномерном распределении может быть принята

	// Определяется константа, которая представляет количество интервалов, на которые будет делиться диапазон значений элементов массива
	const int iter = 25;

	// Создается массив sum размером iter и инициализируется нулями, для подсчета количества элементов в каждом интервале
	int sum[iter] = { 0 };

	// Переменная для подсчета общей суммы всех элементов массива
	int mat = 0;

	for (int i = 0; i < n; i++) {	// проходится по всем элементам массива arr
		// Для каждого элемента массива вычисляется индекс интервала, в который он попадает, и увеличивается соответствующий счетчик в массиве sum
		sum[arr[i] * iter / 101]++;
		// Добавляется значение текущего элемента к общей сумме mat
		mat += arr[i];
	}

	float x = 0;	// переменная для вычисления статистического критерия хи-квадрат

	cout << "Кол-во i элементов в 25 интервалах" << endl;

	for (int i : sum) {	// проходится по всем элементам массива sum
		cout << i << " ";

		// Вычисляется статистический критерий хи-квадрат для каждого интервала.
		// Это выражение считает разницу между фактическим количеством элементов в интервале и ожидаемым количеством элементов в интервале,
		// возводит эту разницу в квадрат и делит на ожидаемое количество элементов в интервале.
		// Результат прибавляется к x.
		x += float((i - (n / iter)) * (i - (n / iter))) / (n / iter);
	}

	cout << endl << "Мат ожидание ожидание: 50,5 реальность: " << mat / n << endl;

	return x;	// возвращается вычисленное значение статистического критерия хи-квадрат
}

int main() {
	setlocale(LC_ALL, "rus");   //установка русской локали

	// Объявляются три массива размеров n1, n2, n3 соответственно
	// Вызывается функция filling для заполнения каждого из массивов случайными числами
	int arr1[n1];
	filling(arr1, n1);
	int arr2[n2];
	filling(arr2, n2);
	int arr3[n3];
	filling(arr3, n3);

	// Объявляется переменная krit, которая содержит значение критического значения для статистического критерия хи-квадрат
	float krit = 44.314;

	cout << "Адреса элементов массива arr1:" << endl;
	for (int i = 0; i < n1; i++) {
		cout << &arr1[i] << " ";
	}
	cout << endl;

	cout << "Адреса элементов массива arr2:" << endl;
	for (int i = 0; i < n2; i++) {
		cout << &arr2[i] << " ";
	}
	cout << endl;

	// Вывод сообщения о начале проверки гипотезы для массива с определенным количеством элементов
	cout << "Для массива на 50 элементов " << endl;
	// Вызов функции X2 для вычисления статистического критерия хи-квадрат для массива
	int x = X2(arr1, n1);
	// Вывод значения статистического критерия хи-квадрат
	cout << " x^2 : " << x << endl;
	// Проверка, меньше ли значение статистического критерия хи-квадрат критического значения
	if (x < krit) {	// если да, то выводится сообщение о принятии гипотезы о нормальном распределении
		cout << "Гипотеза о нормальном распределении принимается." << endl;
	}
	else {	// иначе - о ее отклонении
		cout << "Гипотеза о нормальном распределении отклоняется." << endl;
	}

	// Вывод сообщения о начале проверки гипотезы для массива с определенным количеством элементов
	cout << "Для массива на 100 элементов " << endl;
	// Вызов функции X2 для вычисления статистического критерия хи-квадрат для массива
	x = X2(arr2, n2);
	// Вывод значения статистического критерия хи-квадрат
	cout << " x^2 : " << x << endl;
	// Проверка, меньше ли значение статистического критерия хи-квадрат критического значения
	if (x < krit) {	// если да, то выводится сообщение о принятии гипотезы о нормальном распределении
		cout << "Гипотеза о нормальном распределении принимается." << endl;
	}
	else {	// иначе - о ее отклонении
		cout << "Гипотеза о нормальном распределении отклоняется." << endl;
	}

	// Вывод сообщения о начале проверки гипотезы для массива с определенным количеством элементов
	cout << "Для массива на 1000 элементов " << endl;
	// Вызов функции X2 для вычисления статистического критерия хи-квадрат для массива
	x = X2(arr3, n3);
	// Вывод значения статистического критерия хи-квадрат
	cout << " x^2 : " << x << endl;
	// Проверка, меньше ли значение статистического критерия хи-квадрат критического значения
	if (x < krit) {	// если да, то выводится сообщение о принятии гипотезы о нормальном распределении
		cout << "Гипотеза о нормальном распределении принимается." << endl;
	}
	else {	// иначе - о ее отклонении
		cout << "Гипотеза о нормальном распределении отклоняется." << endl;
	}
}