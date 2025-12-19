#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define LEFT_X 2
#define RIGHT_X 77
#define WIN_SCORE 21

void clamp(int *value, int min_val, int max_val) {
    if (*value < min_val) {
        *value = min_val;
    }
    if (*value > max_val) {
        *value = max_val;
    }
}

void clear_screen(void) {
    int i;
    for (i = 0; i < 50; i = i + 1) {
        printf("\n");
    }
}

void draw_top_border(void) {
    int x;
    printf("\x1b[35m");
    printf("%c", 226);
    printf("%c", 148);
    printf("%c", 140);
    for (x = 1; x < WIDTH - 1; x = x + 1) {
        printf("%c", 226);
        printf("%c", 148);
        printf("%c", 128);
    }
    printf("%c", 226);
    printf("%c", 148);
    printf("%c", 144);
    printf("\x1b[0m\n");
}

void draw_bottom_border(void) {
    int x;
    printf("\x1b[35m");
    printf("%c", 226);
    printf("%c", 148);
    printf("%c", 148);
    for (x = 1; x < WIDTH - 1; x = x + 1) {
        printf("%c", 226);
        printf("%c", 148);
        printf("%c", 128);
    }
    printf("%c", 226);
    printf("%c", 148);
    printf("%c", 152);
    printf("\x1b[0m\n");
}

void draw_score_line(int score_l, int score_r) {
    int i, spaces_before, spaces_after, score_width;
    
    printf("\x1b[35m");
    printf("%c", 226);
    printf("%c", 148);
    printf("%c", 130);
    printf("\x1b[0m");
    
    score_width = 7;
    spaces_before = (WIDTH - 2 - score_width) / 2;
    spaces_after = WIDTH - 2 - score_width - spaces_before;
    
    for (i = 0; i < spaces_before; i = i + 1) {
        printf(" ");
    }
    
    printf("\x1b[34m%d\x1b[0m", score_l);
    printf(" :  ");
    printf("\x1b[31m%d\x1b[0m", score_r);
    
    for (i = 0; i < spaces_after; i = i + 1) {
        printf(" ");
    }
    
    printf("\x1b[35m");
    printf("%c", 226);
    printf("%c", 148);
    printf("%c", 130);
    printf("\x1b[0m\n");
}

void draw_field(int left_y, int right_y, int ball_x, int ball_y, int score_l, int score_r) {
    int x, y;
    
    clear_screen();
    
    draw_top_border();
    draw_score_line(score_l, score_r);
    
    for (y = 1; y < HEIGHT; y = y + 1) {
        printf("\x1b[35m");
        printf("%c", 226);
        printf("%c", 148);
        printf("%c", 130);
        printf("\x1b[0m");
        
        for (x = 1; x < WIDTH - 1; x = x + 1) {
            if (x == WIDTH / 2) {
                printf("%c", 226);
                printf("%c", 150);
                printf("%c", 145);
            } else if (x == LEFT_X && y >= left_y && y < left_y + PADDLE_SIZE) {
                printf("\x1b[34m");
                printf("%c", 226);
                printf("%c", 150);
                printf("%c", 147);
                printf("\x1b[0m");
            } else if (x == RIGHT_X && y >= right_y && y < right_y + PADDLE_SIZE) {
                printf("\x1b[31m");
                printf("%c", 226);
                printf("%c", 150);
                printf("%c", 147);
                printf("\x1b[0m");
            } else if (x == ball_x && y == ball_y) {
                printf("\x1b[33m");
                printf("%c", 226);
                printf("%c", 151);
                printf("%c", 143);
                printf("\x1b[0m");
            } else {
                printf(" ");
            }
        }
        
        printf("\x1b[35m");
        printf("%c", 226);
        printf("%c", 148);
        printf("%c", 130);
        printf("\x1b[0m\n");
    }
    
    draw_bottom_border();
    
    printf("Controls:  \x1b[34mA/Z\x1b[0m (left up/down) | \x1b[31mK/M\x1b[0m (right up/down) | Space (skip) | Q (quit)\n");
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
            /* skip rest */
        }
        
        clamp(&left_y, 1, HEIGHT - PADDLE_SIZE - 1);
        clamp(&right_y, 1, HEIGHT - PADDLE_SIZE - 1);
        
        next_x = ball_x + ball_vx;
        next_y = ball_y + ball_vy;
        
        if (next_y <= 1 || next_y >= HEIGHT - 1) {
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
            printf("\n\x1b[34m\x1b[1mLeft player wins!\x1b[0m\n");
            done = 1;
        }
        
        if (score_r >= WIN_SCORE) {
            printf("\n\x1b[31m\x1b[1mRight player wins!\x1b[0m\n");
            done = 1;
        }
    }
    
    return 0;
}
