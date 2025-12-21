virginwh@kr-h5:~/D07T04.ID_1577485-1$ gcc -Wall -Werror -Wextra src/stat.c -o stat
src/stat.c:80:2: error: expected ‘;’ before ‘double’
   80 | й
      |  ^
      |  ;
   81 | // Дисперсия для равномерного дискретного распределения: E[(x - mu)^2] = (1/n) * sum (x_i - mu)^2
   82 | double variance(int *a, int n) {
      | ~~~~~~
virginwh@kr-h5:~/D07T04.ID_1577485-1$ 
