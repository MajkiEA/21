Quest 3. Data metrics
> Готово

AI Data Analyzer v0.01
Initialising...
Loading...
1. Load module #1... Success!     
2. Load module #2... Success!
3. Load decision decision-making module 
3.1. Load maxmin module... Success!
3.2. Load data i/o & squaring module... Success!
3.2. Load stat module

ERROR 
«Сколько ж можно», — проскальзывает в твоей голове.

> Снова посмотреть папку src репозитория

В папке находится модуль stat. Он практически пустой. Судя по всему, он предназначен для расчета статистических метрик по массиву данных.

> Открыть учебник по математической статистике

Твой любезный сумасшедший друг его, к сожалению, не оставил. Придется гадать и разбираться так.

Получен Quest 3. Добавить реализации необходимых функций в программу src/stat.c таким образом, чтобы программа собиралась и корректно работала (принимала через stdin массив целых чисел, выводила бы его, вычисляла и выводила на новой строке набор статистических метрик — экстремумы (max и min), математическое ожидание и дисперсию, считая, что мы имеем дело с дискретным равномерным распределением). В случае некорректного ввода необходимо выводить «n/a». Уменьшать декомпозицию нельзя — функции можно только добавлять при необходимости, но не убирать. Придерживаться предложенной структуры программы. Числа с плавающей запятой выводить с точностью 6 знаков после запятой.
Входные данные	Выходные данные
4
1 2 3 4	1 2 3 4
4 1 2.500000 1.250000

Вот изначальный код:
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n, data[NMAX];
    input(data, n);
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    return 0;
}


