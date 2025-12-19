# перейти на базовую ветку и обновить
git checkout develop-m
git pull origin develop-m

# создать свою ветку
git checkout -b develop-virginwh

# создать/обновить файл
mkdir -p src
nano src/pong.c   # вставь код, сохрани

# собрать и протестировать
gcc -Wall -Werror -Wextra src/pong.c -o pong
./pong   # управление: A/Z левый, K/M правый, Space пропуск, Q выход

# закоммитить и запушить
git add src/pong.c
git commit -m "Add turn-based Pong with bouncing ball"
git push origin develop-virginwh


#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define LEFT_X 2
#define RIGHT_X (WIDTH - 3)
#define MAX_SCORE 21

static void clamp_paddle(int *y) {
    if (*y < 0) *y = 0;
    if (*y > HEIGHT - PADDLE_SIZE) *y = HEIGHT - PADDLE_SIZE;
}

static void reset_ball(int *x, int *y, int *dx, int *dy, int toward_right) {
    *x = WIDTH / 2;
    *y = HEIGHT / 2;
    *dx = toward_right ? 1 : -1;
    *dy = 0;
}

static void draw_field(int left_y, int right_y, int ball_x, int ball_y, int score_l, int score_r) {
    printf("Score L: %d | Score R: %d\n", score_l, score_r);

    putchar('+');
    for (int i = 0; i < WIDTH; ++i) putchar('-');
    puts("+");

    for (int y = 0; y < HEIGHT; ++y) {
        putchar('|');
        for (int x = 0; x < WIDTH; ++x) {
            char c = ' ';
            if (x == ball_x && y == ball_y) {
                c = 'O';
            } else if (x == LEFT_X && y >= left_y && y < left_y + PADDLE_SIZE) {
                c = '#';
            } else if (x == RIGHT_X && y >= right_y && y < right_y + PADDLE_SIZE) {
                c = '#';
            } else if (x == WIDTH / 2) {
                c = '|';  // центральная линия
            }
            putchar(c);
        }
        puts("|");
    }

    putchar('+');
    for (int i = 0; i < WIDTH; ++i) putchar('-');
    puts("+");
}

int main(void) {
    int left_y = HEIGHT / 2 - PADDLE_SIZE / 2;
    int right_y = HEIGHT / 2 - PADDLE_SIZE / 2;

    int ball_x, ball_y, dx, dy;
    reset_ball(&ball_x, &ball_y, &dx, &dy, 1);  // старт летит вправо

    int score_l = 0, score_r = 0;
    int player = 0;  // 0 — ход левого, 1 — правого

    draw_field(left_y, right_y, ball_x, ball_y, score_l, score_r);

    int ch;
    while (score_l < MAX_SCORE && score_r < MAX_SCORE) {
        ch = getchar();
        if (ch == EOF) break;
        if (ch == '\n') continue;

        if (player == 0) {
            if (ch == 'a' || ch == 'A') {
                left_y -= 1;
            } else if (ch == 'z' || ch == 'Z') {
                left_y += 1;
            } else if (ch == ' ') {
                // пропуск хода
            } else if (ch == 'q' || ch == 'Q') {
                break;
            }
        } else {
            if (ch == 'k' || ch == 'K') {
                right_y -= 1;
            } else if (ch == 'm' || ch == 'M') {
                right_y += 1;
            } else if (ch == ' ') {
                // пропуск хода
            } else if (ch == 'q' || ch == 'Q') {
                break;
            }
        }

        clamp_paddle(&left_y);
        clamp_paddle(&right_y);

        // Шаг мяча
        ball_x += dx;
        ball_y += dy;

        // Отскок от верх/низ
        if (ball_y < 0) {
            ball_y = 0;
            dy = -dy;
        } else if (ball_y >= HEIGHT) {
            ball_y = HEIGHT - 1;
            dy = -dy;
        }

        // Левая сторона
        if (ball_x <= LEFT_X) {
            if (ball_y >= left_y && ball_y < left_y + PADDLE_SIZE) {
                ball_x = LEFT_X;
                dx = -dx;
            } else if (ball_x < 0) {
                score_r++;
                reset_ball(&ball_x, &ball_y, &dx, &dy, 1);  // летит к проигравшему (левый пропустил)
            }
        }

        // Правая сторона
        if (ball_x >= RIGHT_X) {
            if (ball_y >= right_y && ball_y < right_y + PADDLE_SIZE) {
                ball_x = RIGHT_X;
                dx = -dx;
            } else if (ball_x > WIDTH - 1) {
                score_l++;
                reset_ball(&ball_x, &ball_y, &dx, &dy, 0);  // летит к проигравшему (правый пропустил)
            }
        }

        draw_field(left_y, right_y, ball_x, ball_y, score_l, score_r);
        player = 1 - player;  // смена хода
    }

    if (score_l >= MAX_SCORE) {
        printf("Left player wins!\n");
    } else if (score_r >= MAX_SCORE) {
        printf("Right player wins!\n");
    } else {
        printf("Game aborted.\n");
    }
    return 0;
}
