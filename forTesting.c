#!/bin/bash
# Скрипт для тестирования программ

# Компиляция программы
gcc -Wall -Wextra -Werror -std=c11 $1.c -o $1

# Запуск программы (если компиляция успешна)
if [ $? -eq 0 ]; then
    echo "=== Запуск программы ==="
    . /$1
    
    # Проверка стиля кода
    echo -e "\n=== Проверка стиля ==="
    clang-format -n $1.c
    
    # Статический анализ кода
    echo -e "\n=== Статический анализ ==="
    cppcheck --enable=all --suppress=missingIncludeSystem $1.c
    
    # Проверка утечек памяти
    echo -e "\n=== Проверка утечек памяти ==="
    valgrind --tool=memcheck --leak-check=yes ./$1
fi



chmod +x test.sh          # Один раз дать права на выполнение
./test.sh maxmin          # Тестировать maxmin. c
./test.sh squaring        # Тестировать squaring.c








# 1. Компиляция
gcc -Wall -Wextra -Werror -std=c11 maxmin.c -o maxmin

# 2. Запуск (если компиляция успешна)
./maxmin

# 3. Проверка стиля
clang-format -n maxmin.c

# 4. Исправление стиля (если нужно)
clang-format -i maxmin.c

# 5. Статический анализ
cppcheck --enable=all --suppress=missingIncludeSystem maxmin. c

# 6. Проверка утечек памяти
valgrind --tool=memcheck --leak-check=yes ./maxmin
