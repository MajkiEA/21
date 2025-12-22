#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(const int *a, int n);
double variance(const int *a, int n);
int search(const int *a, int n);

int main() {
    int n, data[NMAX];

    // Читаем данные.  Если ошибка — выводим "n/a" и выходим
    if (input(data, &n) != 0) {
        printf("n/a");
        return 0;
    }

    // Ищем число по условию и выводим результат
    printf("%d", search(data, n));

    return 0;
}

// Читаем количество чисел и сами числа
int input(int *a, int *n) {
    // Читаем сколько чисел будет (от 1 до 30)
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 1;  // ошибка
    }

    // Читаем сами числа по одному
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;  // ошибка
        }
    }

    return 0;  // всё ок
}

// Считаем среднее арифметическое (математическое ожидание)
double mean(const int *a, int n) {
    double sum = 0.0;  // сумма всех чисел

    // Складываем все числа
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    // Делим сумму на количество чисел = среднее
    return sum / n;
}

// Считаем дисперсию
double variance(const int *a, int n) {
    double mean_value = mean(a, n);  // сначала находим среднее
    double sum = 0.0;                // сумма квадратов отклонений

    // Для каждого числа считаем (число - среднее)² и складываем
    for (int i = 0; i < n; i++) {
        double diff = a[i] - mean_value;  // отклонение от среднего
        sum += diff * diff;               // квадрат отклонения
    }

    // Дисперсия = сумма квадратов отклонений / количество чисел
    return sum / n;
}

// Ищем первое число, которое подходит под все условия
int search(const int *a, int n) {
    double mean_value = mean(a, n);           // считаем среднее
    double var = variance(a, n);              // считаем дисперсию
    double std_dev = sqrt(var);               // стандартное отклонение (сигма) = √дисперсия
    double lower_bound = mean_value - 3 * std_dev;  // нижняя граница (среднее - 3σ)
    double upper_bound = mean_value + 3 * std_dev;  // верхняя граница (среднее + 3σ)

    // Проходим по массиву и ищем первое подходящее число
    for (int i = 0; i < n; i++) {
        int num = a[i];

        // Проверяем все 4 условия: 
        // 1. Число чётное (остаток от деления на 2 равен 0)
        // 2. Число >= среднего
        // 3. Число в пределах 3 сигм (от lower_bound до upper_bound)
        // 4. Число не равно 0
        if (num % 2 == 0 &&                      // чётное
            num >= mean_value &&                 // >= среднего
            num >= lower_bound &&                // >= нижней границы
            num <= upper_bound &&                // <= верхней границы
            num != 0) {                          // не ноль
            return num;  // нашли — возвращаем его
        }
    }

    return 0;  // ничего не нашли — возвращаем 0
}
