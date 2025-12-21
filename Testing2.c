#include <stdio.h>

int main(void) {
    int a, b, c;

    // Читаем три целых; при неуспехе — "n/a"
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("n/a");
        return 0;
    }

    // Вычисляем максимум и минимум
    int max = a;
    int min = a;

    if (b > max) max = b;
    if (b < min) min = b;

    if (c > max) max = c;
    if (c < min) min = c;

    // Вывод: "max min"
    printf("%d %d\n", max, min);

    return 0;
}
