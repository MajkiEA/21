#include <stdio.h>

// Размеры поля (80x25 по заданию)
#define WIDTH 80
#define HEIGHT 25

// Размер ракетки (3 символа по заданию)
#define PADDLE_SIZE 3

// Позиции ракеток по X (левая у края, правая у края)
#define LEFT_X 2
#define RIGHT_X (WIDTH - 3)

// Победный счёт (21 по заданию)
#define WIN_SCORE 21

// Структура для мяча
typedef struct {
    int x, y;     // координаты мяча
    int vx, vy;   // скорость (направление) мяча:  +1 или -1
} Ball;

// Структура для ракетки
typedef struct {
    int y;  // верхняя точка ракетки (занимает y, y+1, y+2)
} Paddle;

// Функция ограничения ракетки в пределах поля
static void clamp_paddle(Paddle *p) {
    // Верхняя граница — не выше строки 1 (строка 0 — рамка)
    if (p->y < 1) p->y = 1;
    // Нижняя граница — ракетка из 3 клеток, рамка на HEIGHT-1
    if (p->y > HEIGHT - PADDLE_SIZE - 1) p->y = HEIGHT - PADDLE_SIZE - 1;
}

// Функция сброса мяча в центр (после гола)
static void reset_ball(Ball *b) {
    b->x = WIDTH / 2;       // центр по X
    b->y = HEIGHT / 2;      // центр по Y
    b->vx = 1;              // направление вправо
    b->vy = 1;              // направление вниз
}

// Функция очистки экрана (ANSI escape-последовательность)
static void clear_screen(void) {
    // \033[2J — очистить весь экран
    // \033[H — переместить курсор в верхний левый угол
    printf("\033[2J\033[H");
}

// Функция отрисовки всего игрового поля
static void render(const Paddle *l, const Paddle *r, const Ball *b, int sL, int sR) {
    // Очищаем экран перед новой отрисовкой
    clear_screen();
    
    // === ВЕРХНЯЯ РАМКА ===
    // \x1b[35m — фиолетовый цвет
    // \x1b[0m — сброс цвета
    printf("\x1b[35m┌");
    for (int x = 1; x < WIDTH - 1; ++x) printf("─");
    printf("┐\x1b[0m\n");

    // === ОТРИСОВКА ПОЛЯ (25 строк) ===
    for (int y = 0; y < HEIGHT; ++y) {
        // Левая граница (фиолетовая вертикальная линия)
        printf("\x1b[35m│\x1b[0m");
        
        // Проходим по всем столбцам внутри поля
        for (int x = 1; x < WIDTH - 1; ++x) {
            
            // Рисуем сетку по центру (серая пунктирная линия)
            if (x == WIDTH / 2) {
                printf("░");
                continue;
            }
            
            // Рисуем левую ракетку (синяя, символ ▓)
            // Проверяем:  X совпадает с позицией левой ракетки
            // И Y попадает в диапазон [l->y, l->y + 3)
            if (x == LEFT_X && y >= l->y && y < l->y + PADDLE_SIZE) {
                printf("\x1b[34m▓\x1b[0m");  // \x1b[34m — синий цвет
                continue;
            }
            
            // Рисуем правую ракетку (красная, символ ▓)
            if (x == RIGHT_X && y >= r->y && y < r->y + PADDLE_SIZE) {
                printf("\x1b[31m▓\x1b[0m");  // \x1b[31m — красный цвет
                continue;
            }
            
            // Рисуем мяч (жёлтый, символ ●)
            if (x == b->x && y == b->y) {
                printf("\x1b[33m●\x1b[0m");  // \x1b[33m — жёлтый цвет
                continue;
            }
            
            // Иначе — пустое место
            printf(" ");
        }
        
        // Правая граница (фиолетовая вертикальная линия)
        printf("\x1b[35m│\x1b[0m\n");
    }

    // === НИЖНЯЯ РАМКА ===
    printf("\x1b[35m└");
    for (int x = 1; x < WIDTH - 1; ++x) printf("─");
    printf("┘\x1b[0m\n");
    
    // === СЧЁТ ===
    // Левый игрок — синий, правый — красный
    printf("Счёт: \x1b[34mСиний %d\x1b[0m :  \x1b[31m%d Красный\x1b[0m\n", sL, sR);
    
    // === ПОДСКАЗКА ПО УПРАВЛЕНИЮ ===
    printf("Управление: \x1b[34mA/Z\x1b[0m (синий вверх/вниз) | \x1b[31mK/M\x1b[0m (красный вверх/вниз) | Пробел (пропуск) | Q (выход)\n");
}

// Функция движения мяча на один шаг
static void step_ball(Ball *ball, const Paddle *l, const Paddle *r, int *scoreL, int *scoreR) {
    // Вычисляем следующую позицию мяча
    int nextX = ball->x + ball->vx;  // новая X (текущая + скорость по X)
    int nextY = ball->y + ball->vy;  // новая Y (текущая + скорость по Y)

    // === ОТСКОК ОТ ПОТОЛКА И ПОЛА ===
    // Если мяч касается верхней (0) или нижней (HEIGHT-1) границы
    if (nextY <= 0 || nextY >= HEIGHT - 1) {
        ball->vy = -ball->vy;        // разворачиваем направление по Y
        nextY = ball->y + ball->vy;  // пересчитываем новую Y
    }

    // === ОТСКОК ОТ ЛЕВОЙ РАКЕТКИ ===
    // Если мяч попадает на X левой ракетки
    // И Y мяча находится в пределах ракетки
    if (nextX == LEFT_X && nextY >= l->y && nextY < l->y + PADDLE_SIZE) {
        ball->vx = -ball->vx;        // разворачиваем направление по X
        nextX = ball->x + ball->vx;  // пересчитываем новую X
    }
    
    // === ОТСКОК ОТ ПРАВОЙ РАКЕТКИ ===
    if (nextX == RIGHT_X && nextY >= r->y && nextY < r->y + PADDLE_SIZE) {
        ball->vx = -ball->vx;
        nextX = ball->x + ball->vx;
    }

    // === ПРОВЕРКА ГОЛА СЛЕВА (правый игрок забил) ===
    if (nextX <= 0) {
        (*scoreR)++;         // увеличиваем счёт правого игрока
        reset_ball(ball);    // сбрасываем мяч в центр
        return;              // выходим, чтобы не двигать мяч дальше
    }
    
    // === ПРОВЕРКА ГОЛА СПРАВА (левый игрок забил) ===
    if (nextX >= WIDTH - 1) {
        (*scoreL)++;         // увеличиваем счёт левого игрока
        reset_ball(ball);
        return;
    }

    // Если не было гола и не было отскока — перемещаем мяч
    ball->x = nextX;
    ball->y = nextY;
}

// === ГЛАВНАЯ ФУНКЦИЯ ===
int main(void) {
    // Инициализация ракеток (по центру поля по вертикали)
    Paddle left = {. y = HEIGHT / 2 - PADDLE_SIZE / 2};
    Paddle right = {.y = HEIGHT / 2 - PADDLE_SIZE / 2};
    
    // Инициализация мяча
    Ball ball;
    
    // Счёт игроков
    int scoreL = 0, scoreR = 0;
    
    // Сброс мяча в центр
    reset_ball(&ball);

    // Первая отрисовка поля
    render(&left, &right, &ball, scoreL, scoreR);

    // === ОСНОВНОЙ ИГРОВОЙ ЦИКЛ ===
    int ch;
    while ((ch = getchar()) != EOF) {
        // Пропускаем символ новой строки (Enter)
        if (ch == '\n') continue;
        
        // Выход из игры по нажатию Q
        if (ch == 'q' || ch == 'Q') break;

        // === ОБРАБОТКА УПРАВЛЕНИЯ ===
        switch (ch) {
            case 'a':    // Левая ракетка вверх
            case 'A':  
                left.y--;
                break;
                
            case 'z':   // Левая ракетка вниз
            case 'Z':  
                left.y++;
                break;
                
            case 'k':   // Правая ракетка вверх
            case 'K': 
                right.y--;
                break;
                
            case 'm':   // Правая ракетка вниз
            case 'M': 
                right.y++;
                break;
                
            case ' ':   // Пропуск хода (пробел)
                break;
                
            default:    // Игнорируем все остальные символы
                continue;  // не делаем шаг, ждём следующий ввод
        }
        
        // Ограничиваем ракетки в пределах поля
        clamp_paddle(&left);
        clamp_paddle(&right);
        
        // Двигаем мяч на один шаг
        step_ball(&ball, &left, &right, &scoreL, &scoreR);
        
        // Перерисовываем поле
        render(&left, &right, &ball, scoreL, scoreR);

        // === ПРОВЕРКА ПОБЕДЫ ===
        if (scoreL >= WIN_SCORE) {
            printf("\n\x1b[34m\x1b[1m🎉 СИНИЙ ИГРОК ПОБЕДИЛ! 🎉\x1b[0m\n");
            break;
        }
        if (scoreR >= WIN_SCORE) {
            printf("\n\x1b[31m\x1b[1m🎉 КРАСНЫЙ ИГРОК ПОБЕДИЛ! 🎉\x1b[0m\n");
            break;
        }
    }
    
    return 0;
}
