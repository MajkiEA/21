Новое задание по такой же схеме.
Quest 4. Search
> Готово

AI Data Analyzer v0.01
Initialising...
Loading...
1. Load module #1... Success!     
2. Load module #2... Success!
3. Load decision decision-making module 
3.1. Load maxmin module... Success!
3.2. Load data i/o & squaring module... Success!
3.2. Load stat module... Success!
3.4. Load searching module

NOT FOUND 
> Посмотреть папку src репозитория еще раз

Есть модуль search. Но он тебе не понравится.

> Посмотреть модуль search

Только комментарии. Кода нет. Чтобы двигаться дальше, видимо, нужно реализовать его. Интересно, хоть что-то в этой комнате будет проходить легко?

Получен Quest 4. Реализовать программу src/search.c в соответствии с комментарием. Программа должна принимать через stdin массив целых чисел и находить в нем первое вхождение числа, удовлетворяющего следующим требованиям: быть четным, быть большим или равным математическому ожиданию, подчиняться правилу трех сигм и не равняться 0. Найденное число должно быть выведено в stdout. Если такого числа нет, то программа должна выдавать 0. Максимальное количество введенных чисел равно 30. В случае некорректного ввода необходимо выводить «n/a». При разработке необходимо придерживаться идей декомпозиции из предыдущих квестов, приветствуется переиспользование уже разработанных функций. Функции должны быть компактными, простыми и занимать не более 20–30 строк кода.
Входные данные	Выходные данные
4
1 2 3 4	4

Прошлый код:
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


