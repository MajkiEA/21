#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(const int *a, int n);
int max(const int *a, int n);
int min(const int *a, int n);
double mean(const int *a, int n);
double variance(const int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    // Читаем данные.  Если ошибка — выводим "n/a" и выходим
    if (input(data, &n) != 0) {
        printf("n/a");
        return 0;
    }

    // Печатаем введённые числа
    output(data, n);

    // Считаем и печатаем статистику:  макс, мин, среднее, дисперсию
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

// Читаем количество чисел и сами числа
int input(int *a, int *n) {
    // Читаем сколько чисел будет (от 1 до 10)
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

// Печатаем массив чисел через пробел
void output(const int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");  // пробел между числами
        }
    }
    printf("\n");  // переход на новую строку после массива
}

// Ищем максимальное число в массиве
int max(const int *a, int n) {
    int max_value = a[0];  // берём первое число как максимум

    // Проходим по всем числам и ищем больше
    for (int i = 1; i < n; i++) {
        if (a[i] > max_value) {
            max_value = a[i];  // нашли больше — обновляем максимум
        }
    }

    return max_value;
}

// Ищем минимальное число в массиве
int min(const int *a, int n) {
    int min_value = a[0];  // берём первое число как минимум

    // Проходим по всем числам и ищем меньше
    for (int i = 1; i < n; i++) {
        if (a[i] < min_value) {
            min_value = a[i];  // нашли меньше — обновляем минимум
        }
    }

    return min_value;
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

// Считаем дисперсию (насколько числа разбросаны относительно среднего)
double variance(const int *a, int n) {
    double mean_value = mean(a, n);  // сначала находим среднее
    double sum = 0.0;                // сумма квадратов отклонений

    // Для каждого числа: 
    // 1. Вычитаем среднее (отклонение от среднего)
    // 2. Возводим в квадрат
    // 3. Складываем
    for (int i = 0; i < n; i++) {
        double diff = a[i] - mean_value;  // отклонение от среднего
        sum += diff * diff;               // квадрат отклонения
    }

    // Дисперсия = сумма квадратов отклонений / количество чисел
    return sum / n;
}

// Печатаем результаты:  макс, мин, среднее, дисперсия
void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    // %. 6f — это 6 знаков после запятой для дробных чисел
    printf("%d %d %.6f %.6f\n", max_v, min_v, mean_v, variance_v);
}
