#include <stdio.h>

int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XBall, int YBall, int ScoreL, int ScoreR);
void PrintLeftRocket(void);
void PrintRightRocket(void);
void PrintWeb(void);
void LeftTopAngle(void);
void RightTopAngle(void);
void LeftBottomAngle(void);
void RightBottomAngle(void);
void HorizontalBorder(int width);
void PrintBottomBorder(int width);
void PrintTopBorder(int width);
void PrintBall(void);
void PrintVerticalBorder(void);

int main(void) {
    int LeftY = 12, RightY = 12, XBall = 40, YBall = 13;
    int VxBall = 1, VyBall = 1;
    int ScoreL = 0, ScoreR = 0;
    int Player = 0;
    int input;
    int nextX, nextY;
    
    printPole(80, 25, LeftY, RightY, XBall, YBall, ScoreL, ScoreR);

    while (1) {
        input = getchar();

        if (input == 'q') {
            printf("Игра закончена\n");
            return 0;
        }
        
        if (input == '\n') {
            continue;
        }

        if (Player == 0) {
            if (input == 'a') {
                LeftY = LeftY - 1;
                Player = 1;
            } else if (input == 'z') {
                LeftY = LeftY + 1;
                Player = 1;
            } else if (input == 'k') {
                printf("\033[1m !!  Ход левого игрока !!\033[0m \n");
                continue;
            } else if (input == 'm') {
                printf("\033[1m!! Ход левого игрока !!\033[0m \n");
                continue;
            } else if (input == ' ') {
                Player = 1;
            } else {
                continue;
            }
        } else {
            if (input == 'a') {
                printf("\033[1m !! Ход правого игрока !!\033[0m \n");
                continue;
            } else if (input == 'z') {
                printf("\033[1m !! Ход правого игрока \033[1m ! !\033[0m \n");
                continue;
            } else if (input == 'k') {
                RightY = RightY - 1;
                Player = 0;
            } else if (input == 'm') {
                RightY = RightY + 1;
                Player = 0;
            } else if (input == ' ') {
                Player = 0;
            } else {
                continue;
            }
        }

        while (getchar() != '\n') {
        }

        if (LeftY < 1) LeftY = 1;
        if (LeftY > 22) LeftY = 22;
        if (RightY < 1) RightY = 1;
        if (RightY > 22) RightY = 22;

        /* === РАСЧЁТ МЯЧА === */
        nextX = XBall + VxBall;
        nextY = YBall + VyBall;

        if (nextY <= 1 || nextY >= 24) {
            VyBall = -VyBall;
            nextY = YBall + VyBall;
        }

        if (nextX == 2 && nextY >= LeftY && nextY < LeftY + 3) {
            VxBall = -VxBall;
            nextX = XBall + VxBall;
        }

        if (nextX == 77 && nextY >= RightY && nextY < RightY + 3) {
            VxBall = -VxBall;
            nextX = XBall + VxBall;
        }

        if (nextX >= 79) {
            ScoreL = ScoreL + 1;
            XBall = 40;
            YBall = 13;
            VxBall = 1;
            VyBall = 1;
        } else if (nextX <= 0) {
            ScoreR = ScoreR + 1;
            XBall = 40;
            YBall = 13;
            VxBall = 1;
            VyBall = 1;
        } else {
            XBall = nextX;
            YBall = nextY;
        }
        /* === КОНЕЦ РАСЧЁТА МЯЧА === */

        printf("\033[2J\033[H");
        printPole(80, 25, LeftY, RightY, XBall, YBall, ScoreL, ScoreR);

        if (ScoreL >= 21) {
            printf("\nИгрок 1 победил!\n");
            return 0;
        }
        if (ScoreR >= 21) {
            printf("\nИгрок 2 победил!\n");
            return 0;
        }
    }
    return 0;
}

int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XBall, int YBall, int ScoreL, int ScoreR) {
    int y, x;
    int MaxYRocket = 22;
    int MinYRocket = 1;
    
    if (YLeftRocket > MaxYRocket) {
        YLeftRocket = MaxYRocket;
    }
    if (YRightRocket > MaxYRocket) {
        YRightRocket = MaxYRocket;
    }
    if (YLeftRocket < MinYRocket) {
        YLeftRocket = MinYRocket;
    }
    if (YRightRocket < MinYRocket) {
        YRightRocket = MinYRocket;
    }

    /* === ВЫВОД СЧЁТА === */
    printf("\n");
    printf("                                      Счёт\n");
    printf("                                    %d  :  %d\n", ScoreL, ScoreR);
    printf("\n");
    /* === КОНЕЦ ВЫВОДА СЧЁТА === */

    PrintTopBorder(width);

    for (y = 1; y < height; y = y + 1) {
        PrintVerticalBorder();

        for (x = 1; x < width - 1; x = x + 1) {
            if (x == width / 2) {
                PrintWeb();
                continue;
            }
            if (x == 2 && y >= YLeftRocket && y < YLeftRocket + 3) {
                PrintLeftRocket();
                continue;
            }
            if (x == width - 3 && y >= YRightRocket && y < YRightRocket + 3) {
                PrintRightRocket();
                continue;
            }
            if (x == XBall && y == YBall) {
                PrintBall();
                continue;
            }
            printf(" ");
        }

        PrintVerticalBorder();
        printf("\n");
    }

    PrintBottomBorder(width);
    
    printf("\n");
    printf("  Игрок 1: A/Z (вверх/вниз)   |   Игрок 2: K/M (вверх/вниз)   |   Пробел: пропуск   |   Q:  выход\n");
    
    return 0;
}

void PrintLeftRocket(void) {
    printf("\x1b[34m▓\x1b[0m");
}

void PrintRightRocket(void) {
    printf("\x1b[31m▓\x1b[0m");
}

void PrintBall(void) {
    printf("\x1b[33m●\x1b[0m");
}

void PrintTopBorder(int width) {
    LeftTopAngle();
    HorizontalBorder(width);
    RightTopAngle();
}

void PrintBottomBorder(int width) {
    LeftBottomAngle();
    HorizontalBorder(width);
    RightBottomAngle();
}

void PrintWeb(void) {
    printf("░");
}

void PrintVerticalBorder(void) {
    printf("\x1b[35m│\x1b[0m");
}

void LeftTopAngle(void) {
    printf("\x1b[35m┌");
}

void RightTopAngle(void) {
    printf("┐\x1b[0m\n");
}

void LeftBottomAngle(void) {
    printf("\x1b[35m└");
}

void RightBottomAngle(void) {
    printf("┘\x1b[0m\n");
}

void HorizontalBorder(int width) {
    int i;
    for (i = 0; i < width - 1; i = i + 1) {
        printf("─");
    }
}
