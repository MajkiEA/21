#include <stdio.h>

int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XBall, int YBall, int ScoreL, int ScoreR);
void PrintLeftRocket();
void PrintRightRocket();
void PrintWeb();
void PrintVerticalBorder();
void LeftTopAngle();
void RightTopAngle();
void LeftBottomAngle();
void RightBottomAngle();
void HorizontalBorder(int width);
void PrintBall();
void PrintTopBorder(int width);
void PrintBottomBorder(int width);
void PrintScoreLine(int ScoreL, int ScoreR, int width);

int main() {
    int LeftY = 12, RightY = 12;
    int XBall = 40, YBall = 13;
    int VxBall = 1, VyBall = 1;
    int ScoreL = 0, ScoreR = 0;
    int input;
    int nextX, nextY;

    printPole(80, 25, LeftY, RightY, XBall, YBall, ScoreL, ScoreR);

    while (1) {
        input = getchar();

        if (input == 10) {
            continue;
        }

        if (input == 113) {
            printf("Игра закончена\n");
            return 0;
        }

        if (input == 97) {
            LeftY = LeftY - 1;
        } else if (input == 122) {
            LeftY = LeftY + 1;
        } else if (input == 107) {
            RightY = RightY - 1;
        } else if (input == 109) {
            RightY = RightY + 1;
        } else if (input == 32) {
            /* skip */
        } else {
            continue;
        }

        while (getchar() != 10) {
            /* skip rest */
        }

        if (LeftY < 1) LeftY = 1;
        if (LeftY > 22) LeftY = 22;
        if (RightY < 1) RightY = 1;
        if (RightY > 22) RightY = 22;

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

        if (nextX <= 0) {
            ScoreR = ScoreR + 1;
            XBall = 40;
            YBall = 13;
            VxBall = 1;
            VyBall = 1;
        } else if (nextX >= 79) {
            ScoreL = ScoreL + 1;
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
            printf("\n\x1b[34mЛевый игрок победил!\x1b[0m\n");
            break;
        }
        if (ScoreR >= 21) {
            printf("\n\x1b[31mПравый игрок победил!\x1b[0m\n");
            break;
        }
    }

    return 0;
}

int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XBall, int YBall, int ScoreL, int ScoreR) {
    int MaxYRocket = 22;
    int MinYRocket = 1;

    if (YLeftRocket > MaxYRocket) YLeftRocket = MaxYRocket;
    if (YRightRocket > MaxYRocket) YRightRocket = MaxYRocket;
    if (YLeftRocket < MinYRocket) YLeftRocket = MinYRocket;
    if (YRightRocket < MinYRocket) YRightRocket = MinYRocket;

    PrintTopBorder(width);
    PrintScoreLine(ScoreL, ScoreR, width);

    for (int y = 1; y < height; y = y + 1) {
        PrintVerticalBorder();

        for (int x = 1; x < width - 1; x = x + 1) {
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

    return 0;
}

void PrintScoreLine(int ScoreL, int ScoreR, int width) {
    int i, spaces_before, spaces_after, score_width;

    PrintVerticalBorder();

    score_width = 7;
    spaces_before = (width - 2 - score_width) / 2;
    spaces_after = width - 2 - score_width - spaces_before;

    for (i = 0; i < spaces_before; i = i + 1) {
        printf(" ");
    }

    printf("\x1b[34m%d\x1b[0m", ScoreL);
    printf(" :  ");
    printf("\x1b[31m%d\x1b[0m", ScoreR);

    for (i = 0; i < spaces_after; i = i + 1) {
        printf(" ");
    }

    PrintVerticalBorder();
    printf("\n");
}

void PrintLeftRocket() {
    printf("\x1b[34m▓\x1b[0m");
}

void PrintRightRocket() {
    printf("\x1b[31m▓\x1b[0m");
}

void PrintBall() {
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

void PrintWeb() {
    printf("░");
}

void PrintVerticalBorder() {
    printf("\x1b[35m│\x1b[0m");
}

void LeftTopAngle() {
    printf("\x1b[35m┌");
}

void RightTopAngle() {
    printf("┐\x1b[0m\n");
}

void LeftBottomAngle() {
    printf("\x1b[35m└");
}

void RightBottomAngle() {
    printf("┘\x1b[0m\n");
}

void HorizontalBorder(int width) {
    int i;
    for (i = 0; i < width - 1; i = i + 1) {
        printf("─");
    }
}
