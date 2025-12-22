/*------------------------------------
	Здравствуй, человек!  
	Чтобы получить ключ, 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

void input (int *buffer, int *length);
void output (const int *buffer, int length);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int* buffer, int length, int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin. 
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа.
-------------------------------------*/
int main()
{
    int length;
    int buffer[10];
    int numbers[10];
    
    input(buffer, &length);
    
    int sum = sum_numbers(buffer, length);
    
    if (sum == 0) {
        printf("n/a");
        return 0;
    }
    
    int count = find_numbers(buffer, length, sum, numbers);
    
    if (count == 0) {
        printf("n/a");
        return 0;
    }
    
    printf("%d\n", sum);
    output(numbers, count);
    
    return 0;
}

/*------------------------------------
	Функция должна считывать длину массива
	и затем элементы массива через stdin.
-------------------------------------*/
void input(int *buffer, int *length)
{
    scanf("%d", length);
    
    for (int i = 0; i < *length; i++) {
        scanf("%d", &buffer[i]);
    }
}

/*------------------------------------
	Функция должна выводить массив
	в stdout через пробел.
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
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(const int *buffer, int length)
{
    int sum = 0;
    
    for (int i = 0; i < length; i++)
    {
        // Ноль считаем нечетным, поэтому проверяем != 0 и четность
        if (buffer[i] != 0 && buffer[i] % 2 == 0)
        {
            sum = sum + buffer[i];
        }
    }
    
    return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число, и
	записывать их в выходной массив.
-------------------------------------*/
int find_numbers(const int* buffer, int length, int number, int* numbers)
{
    int count = 0;
    
    for (int i = 0; i < length; i++) {
        // Пропускаем ноль (деление на ноль невозможно)
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        }
    }
    
    return count;
}
