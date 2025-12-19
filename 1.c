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
    int y;  // верхняя клетка ракетки
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

static void render(const Paddle *l, const Paddle *r, const Ball *b, int sL, int sR) {
    // Верхняя рамка
    for (int x = 0; x < WIDTH; ++x) putchar('-');
    putchar('\n');

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            char c = ' ';
            // Бордюры
            if (x == 0 || x == WIDTH - 1) c = '|';
            // Сетка по центру
            if (x == WIDTH / 2) c = '|';
            // Левая ракетка
            if (x == LEFT_X && y >= l->y && y < l->y + PADDLE_SIZE) c = '#';
            // Правая ракетка
            if (x == RIGHT_X && y >= r->y && y < r->y + PADDLE_SIZE) c = '#';
            // Мяч
            if (x == b->x && y == b->y) c = 'O';
            putchar(c);
        }
        putchar('\n');
    }

    // Нижняя рамка
    for (int x = 0; x < WIDTH; ++x) putchar('-');
    putchar('\n');
    printf("Score: Left %d : %d Right\n", sL, sR);
    printf("Controls: A/Z (left up/down), K/M (right up/down), Space (skip), q (quit)\n");
}

static void step_ball(Ball *ball, const Paddle *l, const Paddle *r, int *scoreL, int *scoreR) {
    // Движение
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

    // Проверка гола
    if (nextX <= 0) {
        (*scoreR)++;
        reset_ball(ball);
        return;
    }
    if (nextX >= WIDTH - 1) {
        (*scoreL)++;
        reset_ball(ball);
        return;
    }

    ball->x = nextX;
    ball->y = nextY;
}

int main(void) {
    Paddle left = {.y = HEIGHT / 2 - PADDLE_SIZE / 2};
    Paddle right = {.y = HEIGHT / 2 - PADDLE_SIZE / 2};
    Ball ball;
    int scoreL = 0, scoreR = 0;
    reset_ball(&ball);

    render(&left, &right, &ball, scoreL, scoreR);

    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') continue;
        if (ch == 'q') break;

        switch (ch) {
            case 'a': left.y--; break;
            case 'z': left.y++; break;
            case 'k': right.y--; break;
            case 'm': right.y++; break;
            case ' ': /* пропуск */ break;
            default:  /* игнор */ break;
        }
        clamp_paddle(&left);
        clamp_paddle(&right);

        step_ball(&ball, &left, &right, &scoreL, &scoreR);
        render(&left, &right, &ball, scoreL, scoreR);

        if (scoreL >= WIN_SCORE) {
            printf("Left player wins!\n");
            break;
        }
        if (scoreR >= WIN_SCORE) {
            printf("Right player wins!\n");
            break;
        }
    }
    return 0;
}
