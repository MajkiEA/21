/*------------------------------------
    Программа циклического сдвига
    массива влево/вправо
-------------------------------------*/

#include <stdio.h>

void input(int *buffer, int *length, int *shift);
void output(const int *buffer, int length);
void cycle_shift(int *buffer, int length, int shift);
void reverse(int *buffer, int start, int end);

/*------------------------------------
    Основная функция программы
-------------------------------------*/
int main()
{
    int length;
    int shift;
    int buffer[10];
    
    input(buffer, &length, &shift);
    
    if (length <= 0 || length > 10) {
        printf("n/a");
        return 0;
    }
    
    cycle_shift(buffer, length, shift);
    output(buffer, length);
    
    return 0;
}

/*------------------------------------
    Функция ввода данных: 
    длина массива, элементы массива,
    величина сдвига
-------------------------------------*/
void input(int *buffer, int *length, int *shift)
{
    if (scanf("%d", length) != 1) {
        *length = -1;
        return;
    }
    
    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            *length = -1;
            return;
        }
    }
    
    if (scanf("%d", shift) != 1) {
        *length = -1;
    }
}

/*------------------------------------
    Функция вывода массива
-------------------------------------*/
void output(const int *buffer, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) {
            printf(" ");
        }
    }
}

/*------------------------------------
    Функция циклического сдвига массива
    Положительный shift - сдвиг влево
    Отрицательный shift - сдвиг вправо
    
    Алгоритм:  используем метод тройного
    реверса для эффективного сдвига
-------------------------------------*/
void cycle_shift(int *buffer, int length, int shift)
{
    if (length <= 0) {
        return;
    }
    
    // Нормализуем сдвиг к диапазону [0, length)
    shift = shift % length;
    
    // Для отрицательного сдвига (вправо) преобразуем в положительный влево
    if (shift < 0) {
        shift = length + shift;
    }
    
    // Алгоритм тройного реверса: 
    // Чтобы сдвинуть массив влево на shift позиций: 
    // 1. Развернуть первые shift элементов
    // 2. Развернуть оставшиеся элементы
    // 3. Развернуть весь массив
    
    reverse(buffer, 0, shift - 1);
    reverse(buffer, shift, length - 1);
    reverse(buffer, 0, length - 1);
}

/*------------------------------------
    Вспомогательная функция разворота
    части массива от индекса start 
    до индекса end включительно
-------------------------------------*/
void reverse(int *buffer, int start, int end)
{
    while (start < end) {
        int temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }
}
