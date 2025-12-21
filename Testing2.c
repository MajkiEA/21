#include <stdio.h>
#define NMAX 10  // максимальный размер массива

// Прототипы функций: ввод, вывод, метрики и вывод метрик
int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n = 0;          // фактический размер массива
    int data[NMAX];     // буфер под данные (до 10 целых)

    // Читаем размер и массив; при любой ошибке ввода печатаем n/a и выходим
    if (!input(data, &n)) {
        printf("n/a");
        return 0;
    }

    // Выводим исходный массив
    output(data, n);

    // Считаем метрики и выводим их одной строкой: max min mean variance
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    return 0;
}

// Ввод: читаем n, проверяем 0 < n <= NMAX, затем читаем n целых
// Возвращает 1 при успехе, 0 при любой ошибке (нехватка данных, неверный формат, плохой n)
int input(int *a, int *n) {
    if (scanf("%d", n) != 1) return 0;
    if (*n <= 0 || *n > NMAX) return 0;

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) return 0;
    }
    return 1;
}

// Вывод массива целых через пробел, затем перевод строки
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

// Максимум массива
int max(int *a, int n) {
    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > m) m = a[i];
    }
    return m;
}

// Минимум массива
int min(int *a, int n) {
    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < m) m = a[i];
    }
    return m;
}

// Математическое ожидание: сумма / n
double mean(int *a, int n) {
    double s = 0.0;
    for (int i = 0; i < n; i++) s += a[i];
    return s / n;
}
й
// Дисперсия для равномерного дискретного распределения: E[(x - mu)^2] = (1/n) * sum (x_i - mu)^2
double variance(int *a, int n) {
    double mu = mean(a, n);
    double s = 0.0;
    for (int i = 0; i < n; i++) {
        double d = a[i] - mu;
        s += d * d;
    }
    return s / n;
}

// Вывод метрик: max min mean variance с точностью 6 знаков после запятой для вещественных
void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f\n", max_v, min_v, mean_v, variance_v);
}
