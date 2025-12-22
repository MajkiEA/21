#include <stdio. h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int input(int *buffer, int *length);
void output(const int *buffer, int length);
int compare(const int *buff1, int len1, const int *buff2, int len2);
int validate_digits(const int *buffer, int length);

/*
    Беззнаковая целочисленная длинная арифметика
*/
int main()
{
    int buff1[LEN];
    int buff2[LEN];
    int result[LEN + 1];
    int len1 = 0;
    int len2 = 0;
    int result_len = 0;
    int error = 0;
    
    // Считываем данные
    error = input(buff1, &len1);
    if (error == 0) {
        error = input(buff2, &len2);
    }
    
    // Проверяем длины
    if (error == 0) {
        if (len1 <= 0 || len2 <= 0 || len1 > LEN || len2 > LEN) {
            error = 1;
        }
    }
    
    // Проверяем цифры
    if (error == 0) {
        error = validate_digits(buff1, len1);
    }
    if (error == 0) {
        error = validate_digits(buff2, len2);
    }
    
    // Если есть ошибка - выводим n/a и выходим
    if (error != 0) {
        printf("n/a");
    } else {
        // Сложение
        sum(buff1, len1, buff2, len2, result, &result_len);
        output(result, result_len);
        printf("\n");
        
        // Вычитание
        sub(buff1, len1, buff2, len2, result, &result_len);
        
        if (result_len < 0) {
            printf("n/a");
        } else {
            output(result, result_len);
        }
    }
    
    return 0;
}

/*
    Функция ввода числа
    Возвращает:  0 - успех, 1 - ошибка
*/
int input(int *buffer, int *length)
{
    *length = 0;
    char c = ' ';
    int reading = 1;
    
    while (reading != 0 && *length < LEN) {
        if (scanf("%d%c", &buffer[*length], &c) != 2) {
            reading = 0;
            *length = -1;
        } else {
            (*length)++;
            if (c == '\n') {
                reading = 0;
            }
        }
    }
    
    return (*length <= 0) ? 1 : 0;
}

/*
    Проверка цифр в диапазоне 0-9
    Возвращает: 0 - OK, 1 - ошибка
*/
int validate_digits(const int *buffer, int length)
{
    int error = 0;
    int i = 0;
    
    while (i < length && error == 0) {
        if (buffer[i] < 0 || buffer[i] > 9) {
            error = 1;
        }
        i++;
    }
    
    return error;
}

/*
    Функция вывода числа
*/
void output(const int *buffer, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) {
            printf(" ");
        }
    }
}

/*
    Сравнение двух чисел
    Возвращает: 1 (>), 0 (==), -1 (<)
*/
int compare(const int *buff1, int len1, const int *buff2, int len2)
{
    int result = 0;
    
    if (len1 > len2) {
        result = 1;
    } else if (len1 < len2) {
        result = -1;
    } else {
        int i = 0;
        while (i < len1 && result == 0) {
            if (buff1[i] > buff2[i]) {
                result = 1;
            } else if (buff1[i] < buff2[i]) {
                result = -1;
            }
            i++;
        }
    }
    
    return result;
}

/*
    Функция сложения
*/
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length)
{
    int carry = 0;
    int i1 = len1 - 1;
    int i2 = len2 - 1;
    int pos = 0;
    int temp[LEN + 1];
    int continue_loop = 1;
    
    while (continue_loop != 0) {
        int digit1 = (i1 >= 0) ? buff1[i1] : 0;
        int digit2 = (i2 >= 0) ? buff2[i2] : 0;
        int sum_digits = digit1 + digit2 + carry;
        
        temp[pos] = sum_digits % 10;
        carry = sum_digits / 10;
        
        pos++;
        i1--;
        i2--;
        
        if (i1 < 0 && i2 < 0 && carry == 0) {
            continue_loop = 0;
        }
    }
    
    *result_length = pos;
    for (int i = 0; i < pos; i++) {
        result[i] = temp[pos - 1 - i];
    }
}

/*
    Функция вычитания
*/
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length)
{
    if (compare(buff1, len1, buff2, len2) < 0) {
        *result_length = -1;
    } else {
        int borrow = 0;
        int i1 = len1 - 1;
        int i2 = len2 - 1;
        int pos = 0;
        int temp[LEN];
        
        while (i1 >= 0) {
            int digit1 = buff1[i1];
            int digit2 = (i2 >= 0) ? buff2[i2] : 0;
            int diff = digit1 - digit2 - borrow;
            
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
        
        while (pos > 1 && temp[pos - 1] == 0) {
            pos--;
        }
        
        *result_length = pos;
        for (int i = 0; i < pos; i++) {
            result[i] = temp[pos - 1 - i];
        }
    }
}
