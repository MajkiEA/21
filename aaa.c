#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void sort(int *a, int n);
void output(const int *a, int n);

int main() {
    int data[NMAX];

    // Читаем данные.  Если ошибка — выводим "n/a" и выходим
    if (input(data, NMAX) != 0) {
        printf("n/a");
        return 0;
    }

    // Сортируем массив по возрастанию
    sort(data, NMAX);

    // Выводим отсортированный массив
    output(data, NMAX);

    return 0;
}

// Читаем ровно n чисел из ввода
int input(int *a, int n) {
    // Читаем все числа по одному
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;  // ошибка чтения
        }
    }
    return 0;  // всё ок
}

// Сортируем массив по возрастанию (пузырьковая сортировка)
void sort(int *a, int n) {
    // Проходим по массиву n-1 раз
    for (int i = 0; i < n - 1; i++) {
        // На каждом проходе "всплывает" самое большое число в конец
        for (int j = 0; j < n - i - 1; j++) {
            // Если текущее число больше следующего — меняем их местами
            if (a[j] > a[j + 1]) {
                // Обмен без дополнительной переменной через арифметику
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Печатаем массив через пробел
void output(const int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");  // пробел между числами
        }
    }
}
