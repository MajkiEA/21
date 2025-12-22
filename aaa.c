#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void input(int *buffer, int *length);
void output(const int *buffer, int length);
int compare(const int *buff1, int len1, const int *buff2, int len2);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов. 
     * В один элемент массива нельзя вводить число > 9.
    Вывод: 
     * Результат сложения и разности чисел-массивов.
    Пример: 
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main()
{
    int buff1[LEN];    // Первое число
    int buff2[LEN];    // Второе число
    int result[LEN + 1]; // Результат (может быть на 1 цифру длиннее)
    int len1 = 0;      // Длина первого числа
    int len2 = 0;      // Длина второго числа
    int result_len = 0; // Длина результата
    
    // Считываем первое число
    input(buff1, &len1);
    
    // Считываем второе число
    input(buff2, &len2);
    
    // Проверяем корректность ввода
    if (len1 <= 0 || len2 <= 0 || len1 > LEN || len2 > LEN) {
        printf("n/a");
        return 0;
    }
    
    // Проверяем, что все цифры в диапазоне 0-9
    for (int i = 0; i < len1; i++) {
        if (buff1[i] < 0 || buff1[i] > 9) {
            printf("n/a");
            return 0;
        }
    }
    for (int i = 0; i < len2; i++) {
        if (buff2[i] < 0 || buff2[i] > 9) {
            printf("n/a");
            return 0;
        }
    }
    
    // Выполняем сложение
    sum(buff1, len1, buff2, len2, result, &result_len);
    output(result, result_len);
    printf("\n");
    
    // Выполняем вычитание
    sub(buff1, len1, buff2, len2, result, &result_len);
    
    // Если result_len = -1, значит вычитаемое больше уменьшаемого
    if (result_len < 0) {
        printf("n/a");
    } else {
        output(result, result_len);
    }
    
    return 0;
}

/*------------------------------------
    Функция ввода числа в виде массива цифр
    Читает цифры до конца строки
-------------------------------------*/
void input(int *buffer, int *length)
{
    *length = 0;
    char c;
    
    // Читаем символы до конца строки
    while (scanf("%d%c", &buffer[*length], &c) == 2) {
        (*length)++;
        
        // Если достигли конца строки - прекращаем чтение
        if (c == '\n') {
            break;
        }
        
        // Если массив переполнен
        if (*length >= LEN) {
            break;
        }
    }
}

/*------------------------------------
    Функция вывода числа (массива цифр)
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
    Вспомогательная функция сравнения двух чисел
    Возвращает:
     1, если buff1 > buff2
     0, если buff1 == buff2
    -1, если buff1 < buff2
-------------------------------------*/
int compare(const int *buff1, int len1, const int *buff2, int len2)
{
    // Сначала сравниваем длины
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    
    // Если длины равны, сравниваем поцифрово слева направо
    for (int i = 0; i < len1; i++) {
        if (buff1[i] > buff2[i]) return 1;
        if (buff1[i] < buff2[i]) return -1;
    }
    
    // Числа равны
    return 0;
}

/*------------------------------------
    Функция сложения двух больших чисел
    Складываем справа налево с учетом переноса
-------------------------------------*/
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length)
{
    int carry = 0;  // Перенос в следующий разряд
    int i1 = len1 - 1;  // Индекс в первом числе (идем справа налево)
    int i2 = len2 - 1;  // Индекс во втором числе
    int pos = 0;    // Позиция в результате (заполняем справа налево)
    
    int temp[LEN + 1]; // Временный массив для результата
    
    // Складываем, пока есть цифры хотя бы в одном числе
    while (i1 >= 0 || i2 >= 0 || carry > 0) {
        int digit1 = (i1 >= 0) ? buff1[i1] : 0;  // Берем цифру или 0
        int digit2 = (i2 >= 0) ? buff2[i2] : 0;
        
        int sum_digits = digit1 + digit2 + carry;  // Складываем с переносом
        
        temp[pos] = sum_digits % 10;  // Цифра результата
        carry = sum_digits / 10;       // Новый перенос
        
        pos++;
        i1--;
        i2--;
    }
    
    // Переворачиваем результат (он у нас задом наперед)
    *result_length = pos;
    for (int i = 0; i < pos; i++) {
        result[i] = temp[pos - 1 - i];
    }
}

/*------------------------------------
    Функция вычитания двух больших чисел
    Вычитаем buff2 из buff1
    Если buff2 > buff1, устанавливаем result_length = -1
-------------------------------------*/
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length)
{
    // Проверяем, что buff1 >= buff2
    if (compare(buff1, len1, buff2, len2) < 0) {
        *result_length = -1;  // Вычитаемое больше уменьшаемого
        return;
    }
    
    int borrow = 0;  // Заем из следующего разряда
    int i1 = len1 - 1;  // Идем справа налево
    int i2 = len2 - 1;
    int pos = 0;
    
    int temp[LEN]; // Временный массив
    
    // Вычитаем поцифрово
    while (i1 >= 0) {
        int digit1 = buff1[i1];
        int digit2 = (i2 >= 0) ? buff2[i2] : 0;
        
        // Вычитаем с учетом займа
        int diff = digit1 - digit2 - borrow;
        
        // Если результат отрицательный, занимаем 10 из следующего разряда
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        temp[pos] = diff;
        pos++;
        i1--;
        i2--;
    }
    
    // Убираем ведущие нули
    while (pos > 1 && temp[pos - 1] == 0) {
        pos--;
    }
    
    // Переворачиваем результат
    *result_length = pos;
    for (int i = 0; i < pos; i++) {
        result[i] = temp[pos - 1 - i];
    }
}
