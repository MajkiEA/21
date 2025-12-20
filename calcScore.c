#include <stdio.h>

int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XBall, int YBall, int ScoreL, int ScoreR);
void PrintLeftRocket();
void PrintRightRocket();
void PrintWeb();
void PrintLeftBorderAndWeb(int width);
void PrintRightBorder(int width);
void LeftTopAngle() ;
void RightTopAngle();
void LeftBottomAngle() ;
void RightBottomAngle();
void RightBottomAngle();
void HorizontalBorder(int width);
void PrintRightBorderAfterRocket();
void PrintBottomBorder();
void PrintTopBorder();
void PrintBall();
void PrintVerticalBorder();

int main() {
    int LeftY = 12, RightY = 12, XBall = 40, YBall = 13;
    int VxBall = 1, VyBall = 1;
    int ScoreL = 0, ScoreR = 0;
    int Player = 0;
    int nextX, nextY;
    
    printPole(80, 25, LeftY, RightY, XBall, YBall, ScoreL, ScoreR);

    char input;
    while (1) {
        input = getchar();

        switch (input) {
            case 'q': 
                printf("Игра закончена");
                return 0;
            case '\n': 
                break;
            default: 
                if (Player == 0) {
                    switch (input) {
                        case 'a':
                            LeftY -= 1;
                            Player = 1;
                            break;
                        case 'z': 
                            LeftY += 1;
                            Player = 1;
                            break;
                        case 'k': 
                            printf("\033[1m !!  Ход \x1b[36m левого\x1b[0m игрока ! !\033[0m \n");
                            break;
                        case 'm': 
                            printf("\033[1m!!  Ход \x1b[36m левого\x1b[0m игрока !!\033[0m \n");
                            break;
                        case ' ':
                            Player = 1;
                            break;
                    }
                } else {
                    switch (input) {
                        case 'a':
                            printf("\033[1m !! Ход \x1b[32m правого\x1b[0m игрока !!\033[0m \n");
                            break;
                        case 'z':
                            printf("\033[1m !! Ход \x1b[32m правого\x1b[0m игрока \033[1m ! !\033[0m \n");
                            break;
                        case 'k': 
                            RightY -= 1;
                            Player = 0;
                            break;
                        case 'm':
                            RightY += 1;
                            Player = 0;
                            break;
                        case ' ':
                            Player = 0;
                            break;
                    }
                }
                
                /* Ограничение ракеток в пределах поля */
                if (LeftY < 1) LeftY = 1;
                if (LeftY > 22) LeftY = 22;
                if (RightY < 1) RightY = 1;
                if (RightY > 22) RightY = 22;
                
                /* === НАЧАЛО РАСЧЁТА МЯЧА === */
                // Координат для отрисовки мяча XBall, YBall
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
                
                /* Проверка победы */
                if (ScoreL >= 21) {
                    printf("\nИгрок 1 победил!\n");
                    return 0;
                }
                if (ScoreR >= 21) {
                    printf("\nИгрок 2 победил!\n");
                    return 0;
                }
        }
    }
    return 0;
}

/* Рисует прямаугольная область заданой шириной width, и высотой height*/
int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XBall, int YBall, int ScoreL, int ScoreR) {
    int MaxYRocket = 22;
    int MinYRocket = 0;      
    
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
    
    /* === НАЧАЛО ВЫВОДА СЧЁТА === */
    // Вывод счета
    printf("\n");
    printf("                                      Счёт\n");
    printf("                                    %d  :  %d\n", ScoreL, ScoreR);
    printf("\n");
    /* === КОНЕЦ ВЫВОДА СЧЁТА === */

    PrintTopBorder(width);
    // рисуем вертикальную границу

    for (int y = 1; y < height; ++y) {
        PrintVerticalBorder();

        for (int x = 0; x < width - 1; ++x) {
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

void PrintLeftRocket() {
    printf("\x1b[34m▓\x1b[0m");
    return;
}

void PrintRightRocket() {
    printf("\x1b[31m▓\x1b[0m");
    return;
}

void PrintBall() {
    printf("\x1b[33m●\x1b[0m");
    return;
}

void PrintTopBorder(int width) {
    //рисуем угол
    LeftTopAngle();
    //Горизонтальная линия
    HorizontalBorder(width);  
    //рисуем угол
    RightTopAngle();  
    return;
}

void PrintBottomBorder(int width) {
//рисуем угол
    LeftBottomAngle();
    //Горизонтальная линия
    HorizontalBorder(width);  
    //рисуем угол
    RightBottomAngle();  
    return;
}

void PrintWeb() {
     printf("░");
    return;
}       
    
void PrintVerticalBorder() {
    printf("\x1b[35m│\x1b[0m");
    return;
}

void LeftTopAngle() {
    printf("\x1b[35m┌");
    return;
}

void RightTopAngle() {
    printf("┐\x1b[0m\n");
    return;
}

void LeftBottomAngle() {
     printf("\x1b[35m└");
    return;
}

void RightBottomAngle() {
    printf("┘\x1b[0m\n");
    return;
}

void HorizontalBorder(int width) {
    for (int i = 0; i < width - 1; ++i) {  
        // рисуем горизонтальную линию длиной равно ширине поля -2, потому
        // что левый и правый угол рисуются отдельно
        printf("─");
    }
    return;
}
