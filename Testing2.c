#include <stdio.h>

int main(void) {
    int a, b, c;

    // Пытаемся прочитать три целых числа из stdin
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("n/a");
        return 0;
    }

    // Вычисляем максимум и минимум из трех чисел
    int max = a;
    int min = a;

    if (b > max) max = b;
    if (b < min) min = b;

    if (c > max) max = c;
    if (c < min) min = c;

    // Выводим результат в формате: max min
    printf("%d %d\n", max, min);

    return 0;
}
