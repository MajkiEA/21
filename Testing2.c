#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n = 0;
    int data[NMAX];

    if (!input(data, &n)) {   // передаём адрес n, проверяем успех
        printf("n/a");
        return 0;
    }

    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    // читаем размер
    if (scanf("%d", n) != 1) return 0;
    if (*n <= 0 || *n > NMAX) return 0;

    // читаем n целых
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) return 0;
    }
    return 1;
}

void output(int *a, int n) {
    // вывод через пробел, затем перевод строки
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}
