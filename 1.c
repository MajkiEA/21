#include <stdio.h>

// Функция деления через вычитание
// Возвращает частное от деления a на b
int divide(int a, int b) {
    if (b == 0) return 0;
    
    int is_negative = 0;
    if (a < 0) {
        a = -a;
        is_negative = ! is_negative;
    }
    if (b < 0) {
        b = -b;
        is_negative = !is_negative;
    }
    
    int quotient = 0;
    while (a >= b) {
        a = a - b;
        quotient = quotient + 1;
    }
    
    return is_negative ? -quotient : quotient;
}

// Функция проверки остатка от деления через вычитание
// Возвращает остаток от деления a на b
int modulo(int a, int b) {
    if (b == 0) return 0;
    
    int is_negative = 0;
    if (a < 0) {
        a = -a;
        is_negative = 1;
    }
    if (b < 0) {
        b = -b;
    }
    
    while (a >= b) {
        a = a - b;
    }
    
    return is_negative ? -a : a;
}

// Функция проверки, является ли число простым
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (modulo(n, 2) == 0) return 0;
    
    int i = 3;
    while (i * i <= n) {
        if (modulo(n, i) == 0) return 0;
        i = i + 2;
    }
    
    return 1;
}

// Функция поиска наибольшего простого делителя
int find_largest_prime_divisor(int n) {
    // Обрабатываем отрицательные числа
    if (n < 0) {
        n = -n;
    }
    
    // Особые случаи
    if (n == 0 || n == 1) return n;
    
    int largest_prime = 2;
    
    // Проверяем делимость на 2
    while (modulo(n, 2) == 0) {
        largest_prime = 2;
        n = divide(n, 2);
    }
    
    // Проверяем нечетные делители начиная с 3
    int i = 3;
    while (i * i <= n) {
        while (modulo(n, i) == 0) {
            largest_prime = i;
            n = divide(n, i);
        }
        i = i + 2;
    }
    
    // Если n > 1, то это простой делитель
    if (n > 1) {
        largest_prime = n;
    }
    
    return largest_prime;
}

int main() {
    int number;
    
    // Проверка корректности ввода
    if (scanf("%d", &number) != 1) {
        printf("n/a\n");
        return 1;
    }
    
    // Особый случай для 0 и 1
    if (number == 0 || number == 1 || number == -1) {
        printf("n/a\n");
        return 1;
    }
    
    int result = find_largest_prime_divisor(number);
    printf("%d\n", result);
    
    return 0;
}
