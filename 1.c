#include <stdio.h>
int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XCoordBall, int YCoordBall);
void PrintLeftRocket(int width);
void PrintRightRocket(int width);
void  PrintWeb(int width);
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



int main() {
    int LeftY = 12, RightY = 12;
    int Player = 0;  // Если  ход левого игрока если 1 ход правого
    printf("\033[5m¤\033[0m \n");
    printPole(80, 25, LeftY, RightY, 12, 23);

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
                printPole(80, 25, LeftY, RightY, 12, 23);
        }
    }

    return 0;
}

/* Рисует прямаугольная область заданой шириной width, и высотой height*/
int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XCoordBall, int YCoordBall) {
    int MaxYRocket = 22;
    if (YLeftRocket > MaxYRocket) {
        YLeftRocket = MaxYRocket;
    }
    if (YRightRocket > MaxYRocket) {
        YRightRocket = MaxYRocket;
    }
    
    PrintTopBorder();
    // рисуем вертикальную границу
    for (int indexVerticalLine = 0; indexVerticalLine < height; ++indexVerticalLine) {
        if (indexVerticalLine >= YLeftRocket && indexVerticalLine < YLeftRocket + 3) {
            // рисуем левую рокетку
            PrintLeftRocket(width);
            // рисуем сетку   
            PrintWeb(width); 
            
        } else {
            // рисуем левую границу и сетку
            PrintLeftBorderAndWeb( width);
        }

        if (indexVerticalLine >= YRightRocket && indexVerticalLine < YRightRocket + 3) {
            // рисуем правую рокетку
            PrintRightRocket(width);         
            //PrintRightBorder(width);
            PrintRightBorderAfterRocket();
        } else {
            // рисуем правую границу и переходим на следующую строку
             PrintRightBorder(width);            
        }
    }

    PrintBottomBorder();
    
    return 0;
}


void PrintTopBorder() {
//рисуем угол
    LeftTopAngle();
    //Горизонтальная линия
    HorizontalBorder(width);  
    //рисуем угол
    RightTopAngle();  
    return;
}
void PrintBottomBorder() {
//рисуем угол
    LeftTopAngle();
    //Горизонтальная линия
    HorizontalBorder(width);  
    //рисуем угол
    RightTopAngle();  
    return;
}

void PrintWeb(int width) {
    printf("%*s%s", width / 2 - 4, "░", "");
    return;
}       
            

void PrintLeftBorderAndWeb(int width) {
    printf("\x1b[35m|\x1b[0m%*s%s", width / 2, "░", "");
    return;
}

void PrintRightBorder(int width){ 
    printf("%*s\x1b[35m|\x1b[0m\n", width / 2, "");
    return;
}

void PrintLeftRocket(int width) {
    printf("\x1b[35m|\x1b[0m\x1b[36m%*s%s\x1b[0m", width - 74, "▓", "");
   
    //printf("%*s%s", width - 74, "▓", "");
   
    return;
}
void PrintRightRocket(int width) {
    printf("\x1b[32m%*s%s\x1b[0m", width / 2, "▓", "");
    return;
}

void PrintRightBorderAfterRocket() {
      printf("%*s\x1b[35m|\x1b[0m\n", 2, "");
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
    for (int i = 0; i < width - 2; ++i) {  
        // рисуем горизонтальную линию длиной равно ширине поля -2, потому
        // что левый и правый угол рисуются отдельно
        printf("─");
    }
    return;
}
