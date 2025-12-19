#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define LEFT_X 2
#define RIGHT_X 77
#define WIN_SCORE 21

void draw_line(int len) {
    int i;
    for (i = 0; i < len; i = i + 1) {
        printf("-");
    }
}

void draw_spaces(int count) {
    int i;
    for (i = 0; i < count; i = i + 1) {
        printf(" ");
    }
}

void draw_field(int left_y, int right_y, int ball_x, int ball_y, int score_l, int score_r) {
    int x, y;
    
    draw_line(WIDTH);
    printf("\n");
    
    printf("Score: %d - %d\n", score_l, score_r);
    
    for (y = 0; y < HEIGHT; y = y + 1) {
        for (x = 0; x < WIDTH; x = x + 1) {
            if (x == 0 || x == WIDTH - 1) {
                printf("|");
            } else if (x == WIDTH / 2) {
                printf("|");
            } else if (x == LEFT_X && y >= left_y && y < left_y + PADDLE_SIZE) {
                printf("]");
            } else if (x == RIGHT_X && y >= right_y && y < right_y + PADDLE_SIZE) {
                printf("[");
            } else if (x == ball_x && y == ball_y) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    draw_line(WIDTH);
    printf("\n");
    printf("Controls:  A/Z (left), K/M (right), Space (skip), Q (quit)\n");
}

void clamp(int *value, int min_val, int max_val) {
    if (*value < min_val) {
        *value = min_val;
    }
    if (*value > max_val) {
        *value = max_val;
    }
}

int main(void) {
    int left_y, right_y, ball_x, ball_y, ball_vx, ball_vy;
    int score_l, score_r;
    int ch, done, next_x, next_y;
    
    left_y = HEIGHT / 2 - PADDLE_SIZE / 2;
    right_y = HEIGHT / 2 - PADDLE_SIZE / 2;
    ball_x = WIDTH / 2;
    ball_y = HEIGHT / 2;
    ball_vx = 1;
    ball_vy = 1;
    score_l = 0;
    score_r = 0;
    done = 0;
    
    draw_field(left_y, right_y, ball_x, ball_y, score_l, score_r);
    
    while (done == 0) {
        ch = getchar();
        
        if (ch == 10) {
            continue;
        }
        
        if (ch == 113 || ch == 81) {
            break;
        }
        
        if (ch == 97 || ch == 65) {
            left_y = left_y - 1;
        } else if (ch == 122 || ch == 90) {
            left_y = left_y + 1;
        } else if (ch == 107 || ch == 75) {
            right_y = right_y - 1;
        } else if (ch == 109 || ch == 77) {
            right_y = right_y + 1;
        } else if (ch == 32) {
            /* skip */
        } else {
            continue;
        }
        
        while (getchar() != 10) {
            /* skip rest of line */
        }
        
        clamp(&left_y, 0, HEIGHT - PADDLE_SIZE);
        clamp(&right_y, 0, HEIGHT - PADDLE_SIZE);
        
        next_x = ball_x + ball_vx;
        next_y = ball_y + ball_vy;
        
        if (next_y <= 0 || next_y >= HEIGHT - 1) {
            ball_vy = -ball_vy;
            next_y = ball_y + ball_vy;
        }
        
        if (next_x == LEFT_X && next_y >= left_y && next_y < left_y + PADDLE_SIZE) {
            ball_vx = -ball_vx;
            next_x = ball_x + ball_vx;
        }
        
        if (next_x == RIGHT_X && next_y >= right_y && next_y < right_y + PADDLE_SIZE) {
            ball_vx = -ball_vx;
            next_x = ball_x + ball_vx;
        }
        
        if (next_x <= 0) {
            score_r = score_r + 1;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_vx = 1;
            ball_vy = 1;
        } else if (next_x >= WIDTH - 1) {
            score_l = score_l + 1;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_vx = 1;
            ball_vy = 1;
        } else {
            ball_x = next_x;
            ball_y = next_y;
        }
        
        draw_field(left_y, right_y, ball_x, ball_y, score_l, score_r);
        
        if (score_l >= WIN_SCORE) {
            printf("\nLeft player wins!\n");
            done = 1;
        }
        
        if (score_r >= WIN_SCORE) {
            printf("\nRight player wins!\n");
            done = 1;
        }
    }
    
    return 0;
}
