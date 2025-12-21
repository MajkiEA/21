#include <stdio.h>
#include <stdlib.h>

int read_size(int *n) {
    // Читаем одно целое число — размер массива.
    if (scanf("%d", n) != 1) return 0;
    if (*n <= 0) return 0;  // размер должен быть положительным
    return 1;
}

int read_array(int n, int *arr) {
    // Читаем n целых чисел в массив.
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 0;
    }
    return 1;
}

void square_array(int n, int *arr) {
    // Возводим каждый элемент в квадрат.
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * arr[i];
    }
}

void print_array(int n, int *arr) {
    // Печатаем элементы через пробел и перевод строки в конце.
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int n = 0;
    // 1. Читаем размер.
    if (!read_size(&n)) {
        printf("n/a");
        return 0;
    }

    // 2. Выделяем память под массив.
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("n/a");
        return 0;
    }

    // 3. Читаем числа.
    if (!read_array(n, arr)) {
        printf("n/a");
        free(arr);
        return 0;
    }

    // 4. Обрабатываем (квадратим).
    square_array(n, arr);

    // 5. Выводим результат.
    print_array(n, arr);

    // 6. Освобождаем память.
    free(arr);
    return 0;
}1
