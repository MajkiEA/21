Quest 1. Arguments and pointers
> Посмотреть папку src репозитория

Ты видишь несколько файлов, в том числе модуль maxmin.

> Запустить модуль maxmin отдельно

Segmentation fault
По всей видимости, придется его починить.

> Всю жизнь мечтал чинить maxmin-модули...

Наконец-то твоя мечта сбудется!

> Открыть напоминание

НЕ ЗАБЫВАЙ! Все твои программы тестируются на стилевую норму и утечки памяти. Инструкция по запуску тестов все также лежит в папке materials.

Получен Quest 1. Внести исправления в программу src/maxmin.c таким образом, чтобы программа собиралась и корректно работала (находила max и min из 3 целых чисел и выводила их на экран). Структуру программы не менять. В случае некорректного ввода необходимо выводить «n/a».
ВАЖНО! Запрещено выполнять системные вызовы, используя функцию system() и другие аналогичные ей функции, которые могут обращаться напрямую к ядру системы. Данный запрет распространяется на все последующие задачи.

Входные данные	Выходные данные
1 2 3	3 1

#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

int main() {
    int x, y, z;
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        printf("n/a");
        return 0;
    }
    int max, min;
    maxmin(x, y, z, &max, &min);
    printf("%d %d", max, min);
    return 0;
}

/* Эту функцию нужно сохранить! (Твой ИИ) */
/* Но ошибки и баги необходимо исправить. */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    *max = *min = prob1;

    if (prob2 > *max) *max = prob2;
    if (prob2 < *min) *min = prob2;

    if (prob3 > *max) *max = prob3;
    if (prob3 < *min) *min = prob3;
}
а изначально код такой: 
#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int min);

/* Найди максимальную и минимальную вероятности. */
int main()
{
    int x, y, z;
    scanf("%d %d", x, y, z);

    int max, min;

    maxmin(x, y, z, max, min);

    printf("%d %d", max, min);

    return 0;
}


/* Эту функцию нужно сохранить! (Твой ИИ) */
/* Но ошибки и баги необходимо исправить. */
void maxmin(int prob1, int prob2, int prob3, int *max, int min)
{
    *max = min = prob1;
    
    if(prob2 > max)
        max = prob2;
    if(prob2 < min)
        min = prob2;
    
    if(prob3 > max)
        max = prob3;
    if(prob3 < min)
        min = prob3;    
}

