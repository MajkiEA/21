#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define LEFT_X 2
#define RIGHT_X (WIDTH - 3)
#define WIN_SCORE 21

typedef struct {
    int x, y;
    int vx, vy;
} Ball;

typedef struct {
    int y;
} Paddle;

static void clamp_paddle(Paddle *p) {
    if (p->y < 1) p->y = 1;
    if (p->y > HEIGHT - PADDLE_SIZE - 1) p->y = HEIGHT - PADDLE_SIZE - 1;
}

static void reset_ball(Ball *b) {
    b->x = WIDTH / 2;
    b->y = HEIGHT / 2;
    b->vx = 1;
    b->vy = 1;
}

static void clear_screen(void) {
    printf("\033[2J\033[H");
}

static void render(const Paddle *l, const Paddle *r, const Ball *b, int sL, int sR) {
    clear_screen();
    
    // === ВЕРХНЯЯ РАМКА ===
    printf("\x1b[35m┌");
    for (int x = 1; x < WIDTH - 1; ++x) printf("─");
    printf("┐\x1b[0m\n");

    // === ПЕРВАЯ СТРОКА СО СЧЁТОМ В ЦЕНТРЕ ===
    printf("\x1b[35m│\x1b[0m");
    
    // Вычисляем текст счёта
    char score_text[50];
    sprintf(score_text, "%d :  %d", sL, sR);
    
    // Вычисляем длину текста счёта
    int score_len = 0;
    for (int i = 0; score_text[i] != '\0'; ++i) score_len++;
    
    // Вычисляем сколько пробелов нужно слева, чтобы центрировать текст
    int total_space = WIDTH - 2;  // ширина без рамок
    int left_spaces = (total_space - score_len) / 2;
    
    // Рисуем левые пробелы
    for (int i = 0; i < left_spaces; ++i) printf(" ");
    
    // Рисуем счёт (синий :  красный)
    printf("\x1b[34m%d\x1b[0m :  \x1b[31m%d\x1b[0m", sL, sR);
    
    // Рисуем правые пробелы (до правой рамки)
    int right_spaces = total_space - left_spaces - score_len;
    for (int i = 0; i < right_spaces; ++i) printf(" ");
    
    printf("\x1b[35m│\x1b[0m\n");

    // === ПОЛЕ (24 строки, т.к. одну заняли счётом) ===
    for (int y = 1; y < HEIGHT; ++y) {
        printf("\x1b[35m│\x1b[0m");
        
        for (int x = 1; x < WIDTH - 1; ++x) {
            // Сетка по центру
            if (x == WIDTH / 2) {
                printf("░");
                continue;
            }
            
            // Левая ракетка (синяя)
            if (x == LEFT_X && y >= l->y && y < l->y + PADDLE_SIZE) {
                printf("\x1b[34m▓\x1b[0m");
                continue;
            }
            
            // Правая ракетка (красная)
            if (x == RIGHT_X && y >= r->y && y < r->y + PADDLE_SIZE) {
                printf("\x1b[31m▓\x1b[0m");
                continue;
            }
            
            // Мяч (жёлтый)
            if (x == b->x && y == b->y) {
                printf("\x1b[33m●\x1b[0m");
                continue;
            }
            
            printf(" ");
        }
        
        printf("\x1b[35m│\x1b[0m\n");
    }

    // === НИЖНЯЯ РАМКА ===
    printf("\x1b[35m└");
    for (int x = 1; x < WIDTH - 1; ++x) printf("─");
    printf("┘\x1b[0m\n");
    
    // === ПОДСКАЗКА ПО УПРАВЛЕНИЮ ===
    printf("Управление: \x1b[34mA/Z\x1b[0m (синий) | \x1b[31mK/M\x1b[0m (красный) | Пробел (пропуск) | Q (выход)\n");
}

static void step_ball(Ball *ball, const Paddle *l, const Paddle *r, int *scoreL, int *scoreR) {
    int nextX = ball->x + ball->vx;
    int nextY = ball->y + ball->vy;

    // Отскок от потолка и пола
    if (nextY <= 1 || nextY >= HEIGHT - 1) {
        ball->vy = -ball->vy;
        nextY = ball->y + ball->vy;
    }

    // Отскок от левой ракетки
    if (nextX == LEFT_X && nextY >= l->y && nextY < l->y + PADDLE_SIZE) {
        ball->vx = -ball->vx;
        nextX = ball->x + ball->vx;
    }
    
    // Отскок от правой ракетки
    if (nextX == RIGHT_X && nextY >= r->y && nextY < r->y + PADDLE_SIZE) {
        ball->vx = -ball->vx;
        nextX = ball->x + ball->vx;
    }

    // Гол слева (правый игрок забил)
    if (nextX <= 0) {
        (*scoreR)++;
        reset_ball(ball);
        return;
    }
    
    // Гол справа (левый игрок забил)
    if (nextX >= WIDTH - 1) {
        (*scoreL)++;
        reset_ball(ball);
        return;
    }

    ball->x = nextX;
    ball->y = nextY;
}

int main(void) {
    Paddle left = {. y = HEIGHT / 2 - PADDLE_SIZE / 2};
    Paddle right = {. y = HEIGHT / 2 - PADDLE_SIZE / 2};
    Ball ball;
    int scoreL = 0, scoreR = 0;
    reset_ball(&ball);

    render(&left, &right, &ball, scoreL, scoreR);

    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') continue;
        if (ch == 'q' || ch == 'Q') break;

        switch (ch) {
            case 'a':
            case 'A':
                left.y--;
                break;
            case 'z':
            case 'Z':
                left.y++;
                break;
            case 'k':
            case 'K':
                right.y--;
                break;
            case 'm':
            case 'M':
                right.y++;
                break;
            case ' ':
                break;
            default:
                continue;
        }
        
        clamp_paddle(&left);
        clamp_paddle(&right);
        step_ball(&ball, &left, &right, &scoreL, &scoreR);
        render(&left, &right, &ball, scoreL, scoreR);

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
