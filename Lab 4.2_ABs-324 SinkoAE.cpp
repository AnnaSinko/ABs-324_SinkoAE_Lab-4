// Lab 4.2_ABs-324 SinkoAE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <map>
#include <locale.h>

using namespace std;

// Функция для проверки високосности года
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для пункта 1
vector<int> generateArray(int n, int min, int max) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> dis(min, max);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}

// Функция для пункта 2
void processArray(const vector<int>& arr, int& secondMax, int& minSum) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    secondMax = sortedArr[sortedArr.size() - 2];
    minSum = 0;
    for (int num : sortedArr) {
        if (num > sortedArr[0] && num < secondMax) {
            minSum += num;
        }
    }
}

// Функция для пункта 3
vector<int> generateAndProcessArrays(int n, int min, int max) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> dis(min, max);
    vector<int> arr1(n), arr2(n), arr3(n), arr4(n);
    for (int i = 0; i < n; ++i) {
        arr1[i] = dis(gen);
        arr2[i] = dis(gen);
        arr3[i] = dis(gen);
        arr4[i] = (i % 2 == 0 ? arr2[i] + arr3[i] : arr2[i] - arr3[i]);
    }
    return arr4;
}

// Функция для пункта 4
map<int, int> countElements(const vector<int>& arr) {
    map<int, int> count;
    for (int num : arr) {
        count[num]++;
    }
    return count;
}

// Функция для пункта 5
vector<int> findLeapYears(int startYear, int endYear) {
    vector<int> leapYears;
    for (int year = startYear; year <= endYear; ++year) {
        if (isLeapYear(year)) {
            leapYears.push_back(year);
        }
    }
    return leapYears;
}

int main() {
    setlocale(LC_ALL, "rus");

    // Пункт 1
    vector<int> arr1 = generateArray(10, 100, 200);
    cout << "Пункт 1: Исходный массив:" << endl;
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Пункт 2
    int secondMax, minSum;
    processArray(arr1, secondMax, minSum);
    cout << "Пункт 2: Минимальный элемент: " << arr1[0] << endl;
    cout << "Пункт 2: Второй по величине элемент: " << secondMax << endl;
    cout << "Пункт 2: Сумма элементов между минимальным и вторым по величине: " << minSum << endl;

    // Пункт 3
    vector<int> arr4 = generateAndProcessArrays(10, -50, 50);
    cout << "Пункт 3: Результат:" << endl;
    for (int num : arr4) {
        cout << num << " ";
    }
    cout << endl;

    // Пункт 4
    map<int, int> count = countElements(arr1);
    cout << "Пункт 4: Количество повторений каждого элемента в массиве из пункта 1:" << endl;
    for (auto& pair : count) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Пункт 5
    int startYear, endYear;
    cout << "Пункт 5: Введите начальный год: ";
    cin >> startYear;
    cout << "Пункт 5: Введите конечный год: ";
    cin >> endYear;
    vector<int> leapYears = findLeapYears(startYear, endYear);
    cout << "Пункт 5: Високосные года в диапазоне от " << startYear << " до " << endYear << ":" << endl;
    for (int year : leapYears) {
        cout << year << " ";
    }
    cout << endl;

    return 0;
}

//#include <iostream>
//#include <random>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <locale.h> //подключение библиотеки для задач связанных из локализацией
//
//// используются:
//// mt19937_64 - для генерации случайных чисел,
//// vector для хранения массивов,
//// sort для сортировки массива,
//// map для подсчета количества повторений элементов в массиве.
//
//using namespace std;    // пространство имен std для удобства
//
//// Функция для проверки високосности года
//bool isLeapYear(int year) { // принимает один целочисленный аргумент (год на проверку високосности)
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//
//// 1 условие - проверяет, делится ли год на 4 без остатка, и при этом год не должен быть кратен 100. Если это условие выполняется, то год високосный.
//// 2 условие - проверяет, делится ли год на 400 без остатка. Если это условие выполняется, то год также считается високосным.
//// Оператор ИЛИ объединяет эти два условия:
//// если хотя бы одно из условий выполняется, функция возвращает true, что означает, что год високосный,
//// в противном случае функция возвращает false.
//
//int main() {
//    setlocale(LC_ALL, "rus");   //установка русской локали
//    // Инициализация генератора случайных чисел (в соответствии с вариантом)
//    random_device rd;
//    mt19937_64 gen(rd());
//    uniform_int_distribution<> dis1(100, 200);
//    uniform_int_distribution<> dis2(-50, 50);
//
//    // Размер массива
//    const int n = 10;   // 𝑛 ≥ 10
//
//    // Пункт 1: Инициализация массива случайными числами из диапазона [100, 200]
//    vector<int> arr1(n);    // вектор arr1 целочисленных элементов размера n
//    // инициализация каждого элемента вектора случайным числом, которое генерируется генератором случайных чисел gen
//    // он в свою очередь использует равномерное распределение dis1
//    for (int i = 0; i < n; ++i) {   // цикл выполняется n раз. Переменная i начинается с 0 и увеличивается на 1 после каждой итерации цикла.
//        arr1[i] = dis1(gen);    // каждый элемент вектора arr1 получает новое случайное значение
//        // dis1(gen) вызывает функцию-член dis1 объекта gen, которая генерирует случайное число в соответствии с распределением, заданным при создании dis1
//    }
//
//    // Вывод на экран результата для пункта 1
//    cout << "Пункт 1: Исходный массив:" << endl;
//    for (int num : arr1) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    // Пункт 2: Поиск второго по величине элемента и сумма элементов между минимальным и вторым по величине
//    sort(arr1.begin(), arr1.end()); // сортирует вектор arr1 в порядке возрастания
//
//    // Вывод на экран отсортированного массива из пункта 1
//    cout << "Пункт 2: Отсортированный массив:" << endl;
//    for (int num : arr1) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    int secondMax = arr1[n - 2];    // определение второй по величине элемент вектора arr1
//    // поскольку изначально вектор arr1 отсортировали в порядке возрастания, то второй по величине элемент будет находиться на индексе n - 2
//    int min = arr1[0];  // определение минимального элемента вектора arr1
//    int sum = 0;    // инициализация переменной sum, которая будет использована для подсчета суммы элементов вектора arr1
//    for (int i = 0; i < n; ++i) {   // цикл, который проходит по всем элементам вектора arr1
//        // проверка, что каждый элемент вектора arr1 больше минимального элемента и меньше второго по величине элемента
//        if (arr1[i] > min && arr1[i] < secondMax) {
//            sum += arr1[i]; // при выполнении условия элемент добавляется к сумме
//        }
//    }
//
//    // Вывод результата для пункта 2
//    cout << "Пункт 2: Минимальный элемент: " << min << endl;
//    cout << "Пункт 2: Второй по величине элемент: " << secondMax << endl;
//    cout << "Пункт 2: Сумма элементов между минимальным и вторым по величине: " << sum << endl;
//
//    // Пункт 3: Создание двух массивов диапазона [-50, 50] и заполнение третьего массива суммой четных и разницей нечетных элементов
//    // создание трех векторов arr2, arr3 и arr4 целочисленных элементов размера n
//    vector<int> arr2(n);
//    vector<int> arr3(n);
//    vector<int> arr4(n);
//    for (int i = 0; i < n; ++i) {   // цикл, который выполняется n раз. Переменная i начинается с 0 и увеличивается на 1 после каждой итерации цикла
//        // каждый элемент векторов arr2 и arr3 получает новое случайное значение
//        // dis2(gen) вызывает функцию-член dis2 объекта gen, которая генерирует случайное число в соответствии с распределением, заданным при создании dis2
//        arr2[i] = dis2(gen);
//        arr3[i] = dis2(gen);
//        arr4[i] = (i % 2 == 0 ? arr2[i] + arr3[i] : arr2[i] - arr3[i]);
//        // если индекс i четный (i % 2 == 0), то в arr4[i] записывается сумма соответствующих элементов arr2[i] и arr3[i].
//        // если индекс i нечетный, то в arr4[i] записывается разность соответствующих элементов arr2[i] и arr3[i].
//    }
//
//    // Вывод изначальных данных для пункта 3
//    cout << "Пункт 3: Исходные массивы:" << endl;
//    for (int num : arr2) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    for (int num : arr3) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    // Вывод результата для пункта 3
//    cout << "Пункт 3: Результат:" << endl;
//    for (int num : arr4) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    // Пункт 4: Подсчет количества повторений каждого элемента в первом массиве
//    // map подсчитывает количество повторений каждого элемента в векторе arr1
//    map<int, int> count;    // ключ - элемент из arr1, а значение - количество повторений
//    for (int i = 0; i < n; ++i) {   // прохождение по всем элементам вектора arr1
//        count[arr1[i]]++;
//        // если элемент еще не встречался, то он добавляется в map со значением 1.
//        // если элемент уже есть в map, то значение, связанное с этим элементом, увеличивается на 1.
//    }
//
//    // Вывод результата для пункта 4
//    cout << "Пункт 4: Количество повторений каждого элемента в массиве из пункта 1:" << endl;
//    for (auto& pair : count) {
//        cout << pair.first << ": " << pair.second << endl;
//    }
//
//    // Пункт 5: Получение диапазона лет и вывод високосных годов в этом диапазоне
//    int startYear, endYear; // хранение начального и конечного годов диапазона соответственно
//    cout << "Пункт 5: Введите начальный год: ";
//    cin >> startYear;
//    cout << "Пункт 5: Введите конечный год: ";
//    cin >> endYear;
//
//    vector<int> leapYears;  // вектор целых чисел, который будет использоваться для хранения високосных годов из диапазона
//    for (int year = startYear; year <= endYear; ++year) {   // прохождение по всем годам в диапазоне от startYear до endYear включительно
//        if (isLeapYear(year)) { // проверка, является ли текущий год високосным
//            leapYears.push_back(year);  // если год високосный, то он добавляется в вектор leapYears
//        }
//    }
//
//    // Вывод результата для пункта 5
//    cout << "Пункт 5: Високосные года в диапазоне от " << startYear << " до " << endYear << ":" << endl;
//    for (int year : leapYears) {
//        cout << year << " ";
//    }
//    cout << endl;
//
//    return 0;
//}