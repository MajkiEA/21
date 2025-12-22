#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main()
{
    int n, data[NMAX];
    
    // Проверка корректности ввода
    if (input(data, &n) != 0) {
        printf("n/a");
        return 0;
    }
    
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n)
{
    // Проверка ввода количества элементов
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 1; // Ошибка ввода
    }
    
    // Ввод элементов массива
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            return 1; // Ошибка ввода
        }
    }
    
    return 0; // Успешный ввод
}

void output(int *a, int n)
{
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a < n - 1) {
            printf(" "); // Пробел между числами
        }
    }
}

void squaring(int *a, int n)
{
    for (int *p = a; p - a < n; p++) {
        *p = (*p) * (*p); // Возведение в квадрат
    }
}
