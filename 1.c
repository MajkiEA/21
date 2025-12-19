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
void PrintScore(int ScoreL, int ScoreR);
void PrintControls(void);

int main(void) {
    int LeftY = 12, RightY = 12;
    int XBall = 40, YBall = 13;
    int VxBall = 1, VyBall = 1;
    int ScoreL = 0, ScoreR = 0;
    int nextX, nextY;
    int ch;

    printPole(80, 25, LeftY, RightY, XBall, YBall, ScoreL, ScoreR);

    while (1) {
        ch = getchar();

        if (ch == 'q' || ch == 'Q') {
            printf("Игра закончена\n");
            return 0;
        }

        if (ch == '\n') {
            continue;
        }

        if (ch == 'a' || ch == 'A') {
            LeftY = LeftY - 1;
        } else if (ch == 'z' || ch == 'Z') {
            LeftY = LeftY + 1;
        } else if (ch == 'k' || ch == 'K') {
            RightY = RightY - 1;
        } else if (ch == 'm' || ch == 'M') {
            RightY = RightY + 1;
        } else if (ch == ' ') {
            /* пропуск хода */
        } else {
            continue;
        }

        /* Читаем только первый символ */
        while (getchar() != '\n') {
        }

        /* Ограничиваем ракетки */
        if (LeftY < 1) LeftY = 1;
        if (LeftY > 22) LeftY = 22;
        if (RightY < 1) RightY = 1;
        if (RightY > 22) RightY = 22;

        /* Расчёт следующей позиции мяча */
        nextX = XBall + VxBall;
        nextY = YBall + VyBall;

        /* Отскок от потолка и пола */
        if (nextY <= 1 || nextY >= 24) {
            VyBall = -VyBall;
            nextY = YBall + VyBall;
        }

        /* Отскок от левой ракетки */
        if (nextX == 2 && nextY >= LeftY && nextY < LeftY + 3) {
            VxBall = -VxBall;
            nextX = XBall + VxBall;
        }

        /* Отскок от правой ракетки */
        if (nextX == 77 && nextY >= RightY && nextY < RightY + 3) {
            VxBall = -VxBall;
            nextX = XBall + VxBall;
        }

        /* Голы */
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

void PrintScore(int ScoreL, int ScoreR) {
    printf("\n");
    printf("                                      Счёт\n");
    printf("                                    %d  :  %d\n", ScoreL, ScoreR);
    printf("\n");
}

void PrintControls(void) {
    printf("\n");
    printf("  Игрок 1: A/Z (вверх/вниз)   |   Игрок 2: K/M (вверх/вниз)   |   Пробел:  пропуск   |   Q: выход\n");
}

int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XBall, int YBall, int ScoreL, int ScoreR) {
    int y, x;
    int MaxYRocket = 22;
    int MinYRocket = 1;

    if (YLeftRocket > MaxYRocket) YLeftRocket = MaxYRocket;
    if (YRightRocket > MaxYRocket) YRightRocket = MaxYRocket;
    if (YLeftRocket < MinYRocket) YLeftRocket = MinYRocket;
    if (YRightRocket < MinYRocket) YRightRocket = MinYRocket;

    PrintScore(ScoreL, ScoreR);
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
    PrintControls();

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
