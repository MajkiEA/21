Получен Quest 2. Внести исправления в программу src/squaring.c таким образом, чтобы программа собиралась и корректно работала (принимала через stdin массив целых чисел, возводила их в квадрат и выводила в stdout). В случае некорректного ввода необходимо выводить «n/a». Уменьшать декомпозицию нельзя — функции можно только добавлять при необходимости, но не убирать.
Входные данные	Выходные данные
3
1 2 3	1 4 9

Сделай по-простому, в рамках задания.
Изначально файл дали такой:
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main()
{
    int n, data[NMAX];
    input(data, n);
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n)
{
    scanf("%d", n);
    for(int *p = a; p - a < *n; p++)
    {
        scanf("%d", p);
    }
}

void output(int *a, int n)
{
    //NOTHING
}

void squaring(int *a, int n)
{
    //NOTHING
}
