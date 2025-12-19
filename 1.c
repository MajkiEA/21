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
    
    // Верхняя рамка
    printf("\x1b[35m┌");
    for (int x = 1; x < WIDTH - 1; ++x) printf("─");
    printf("┐\x1b[0m\n");

    // Поле
    for (int y = 0; y < HEIGHT; ++y) {
        printf("\x1b[35m│\x1b[0m");
        
        for (int x = 1; x < WIDTH - 1; ++x) {
            // Сетка по центру
            if (x == WIDTH / 2) {
                printf("░");
                continue;
            }
            
            // Левая ракетка (синяя)
            if (x == LEFT_X && y >= l->y && y < l->y + PADDLE_SIZE) {
                printf("\x1b[36m▓\x1b[0m");
                continue;
            }
            
            // Правая ракетка (зелёная)
            if (x == RIGHT_X && y >= r->y && y < r->y + PADDLE_SIZE) {
                printf("\x1b[32m▓\x1b[0m");
                continue;
            }
            
            // Мяч (жёлтый мигающий)
            if (x == b->x && y == b->y) {
                printf("\x1b[33m\x1b[5m●\x1b[0m");
                continue;
            }
            
            printf(" ");
        }
        
        printf("\x1b[35m│\x1b[0m\n");
    }

    // Нижняя рамка
    printf("\x1b[35m└");
    for (int x = 1; x < WIDTH - 1; ++x) printf("─");
    printf("┘\x1b[0m\n");
    
    // Счёт
    printf("Счёт: \x1b[36mЛевый %d\x1b[0m :  \x1b[32m%d Правый\x1b[0m\n", sL, sR);
    printf("Управление: \x1b[36mA/Z\x1b[0m (левый вверх/вниз) | \x1b[32mK/M\x1b[0m (правый вверх/вниз) | Пробел (пропуск) | q (выход)\n");
}

static void step_ball(Ball *ball, const Paddle *l, const Paddle *r, int *scoreL, int *scoreR) {
    int nextX = ball->x + ball->vx;
    int nextY = ball->y + ball->vy;

    // Отскок от потолка/пола
    if (nextY <= 0 || nextY >= HEIGHT - 1) {
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

    // Гол слева
    if (nextX <= 0) {
        (*scoreR)++;
        reset_ball(ball);
        return;
    }
    
    // Гол справа
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
            printf("\n\x1b[36m\x1b[1m🎉 ЛЕВЫЙ ИГРОК ПОБЕДИЛ!  🎉\x1b[0m\n");
            break;
        }
        if (scoreR >= WIN_SCORE) {
            printf("\n\x1b[32m\x1b[1m🎉 ПРАВЫЙ ИГРОК ПОБЕДИЛ! 🎉\x1b[0m\n");
            break;
        }
    }
    
    return 0;
}
