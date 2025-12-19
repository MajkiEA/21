#include <stdio.h>
int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XBall, int YBall, int Score);
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
    int LeftY = 12, RightY = 12, XBall = 2, YBall=13;

    int Player = 0, Score = 0;  // Если  ход левого игрока если 1 ход правого
    
    printPole(80, 25, LeftY, RightY, XBall, YBall, Score);

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
                            printf("\033[1m !! Ход \x1b[36m левого\x1b[0m игрока !!\033[0m \n");
                            break;
                        case 'm':
                            printf("\033[1m!! Ход \x1b[36m левого\x1b[0m игрока !!\033[0m \n");
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
                            printf("\033[1m !! Ход \x1b[32m правого\x1b[0m игрока \033[1m !!\033[0m \n");
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
                printf("\033[2J\033[H");    
                
                // Координат для отрисовки мяча XBall, YBall
                
                printPole(80, 25, LeftY, RightY, XBall, YBall, Score);
        }
    }
    return 0;
}

/* Рисует прямаугольная область заданой шириной width, и высотой height*/
int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XBall, int YBall, int Score) {
   //int XBall = 2;
   //int YBall = 13;
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
    

    // Вывод счета

    PrintTopBorder(width);
    // рисуем вертикальную границу


    for (int y= 1; y < height; ++y) {
        PrintVerticalBorder();

        for (int x =  0; x < width-1;++x) {
            if (x == width / 2) {
               PrintWeb() ;
                continue;
            }
            if (x == 2 && y >= YLeftRocket && y < YLeftRocket + 3 ){
                PrintLeftRocket();
                continue;
            }
             if (x == width-3 && y >= YRightRocket && y < YRightRocket + 3 ){
                PrintRightRocket(width);
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


void PrintBall(){
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
    

void PrintVerticalBorder(){
    printf("\x1b[35m│\x1b[0m");
    return;
}


void LeftTopAngle() {
    printf("\x1b[35m┌");
    return;
}

void RightTopAngle(){
    printf("┐\x1b[0m\n");
    return;
}

void LeftBottomAngle() {
     printf("\x1b[35m└");
    return;
}

void RightBottomAngle(){
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

почему не запускает этот код и исправь где тут я написал, что в мейн раассчёт координаты мячика и сделай вывод счёта сверху границы
