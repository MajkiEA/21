#include <stdio.h>
int printPole(int width, int height, int YLeftRocket, int XLeftRocket, int YRightRocket, int XRightRocket, int XBall, int YBall, int GoalLeft, int ScoreRight);
void PrintLeftRocket();
void PrintRightRocket();
void PrintWeb();
void PrintLeftBorderAndWeb(int width);
void PrintRightBorder(int width);
void LeftTopAngle() ;
void RightTopAngle();
void LeftBottomAngle() ;
void RightBottomAngle();
void HorizontalBorder(int width);
void PrintRightBorderAfterRocket();
void PrintBottomBorder();
void PrintTopBorder();
void PrintBall();
void PrintVerticalBorder();

int main() {
    int YLeftRocket = 12, YRightRocket = 12; // координаты платформ дпо вертикали Y = 12 для обеих платформа чтобы отобразить по середине
    int XBall = 3, YBall=13; // координаты мячика , мячк у левого игрока
    int speedX = 1, speedY =1; // скорость перемещения мячика 2 символа за ход
    int Player = 0;  // флаг хода:  0 Если  ход левого игрока,  1 ход правого игрока
    int GoalLeft = 0, GoalRight = 0; // количество голов для левого и правого игрока
    int ScreenX = 80, ScreenY = 25; // размер игровой площадки
    int XLeftRocket = 2, XRightRocket = ScreenX -3; 
    
    printPole(ScreenX, ScreenY, YLeftRocket, XLeftRocket, YRightRocket, XRightRocket, XBall, YBall, GoalLeft, GoalRight);// функция рисует игровое поле в начальном сотоянии

    char input;
    while (1) { // Запускаем бесконечный цикл,
        input = getchar(); // ожидаем ввод с клавиатуры, считываем символ



                    if (XBall <=0){
                        GoalLeft++;
                        printf(" гол левому \n ");
                        YLeftRocket = 12;
                        YRightRocket = 12;
                        XLeftRocket = 2;
                        XRightRocket = ScreenX -3;
                        XBall = 3;
                        YBall=13;
                        speedX = 1; 
                        speedY =1;
                        Player = 0;
                        continue;
                        // гол левому новый раунд
                       
                    } else if (XBall >= ScreenX-1){
                        GoalRight++;
                        printf(" гол правому \n ");
                        YLeftRocket = 12;
                        YRightRocket = 12;
                        XLeftRocket = 2;
                        XRightRocket = ScreenX -3;
                        XBall = XRightRocket - 2;
                        YBall=13;
                        speedX = -1; 
                        speedY = -1;
                        Player = 1;
                        continue;
                        // гол правому игроку, начинаем новый раунд                        
                    } 

        switch (input) {
            case 'q': // если введена q заканчиваем игру
                printf("Игра закончена");
                return 0;
            case '\n': // игнориируем перевод строки клавиша ENTER
                break;
            default:
                if (Player == 0) { // проверяем чей ход и в заисимости от нажатой клавиши устанавливаем координаты платформы
                    switch (input) {
                        case 'a':
                            YLeftRocket -= 1;
                            if (YLeftRocket <= 0) {
                                YLeftRocket = 1;
                            }
                            Player = 1;
                            break;
                        case 'z':
                            YLeftRocket += 1;
                            if (YLeftRocket >= ScreenX) {
                                YLeftRocket = ScreenX-3;
                            }
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
                            YRightRocket -= 1;
                            if (YRightRocket <= 0){
                                YRightRocket=1;
                            }
                            Player = 0;
                            break;
                        case 'm':
                            YRightRocket += 1;
                            if (YRightRocket <= 0){
                                YRightRocket=1;
                            }
                            Player = 0;
                            break;
                        case ' ':
                            Player = 0;
                            break;
                    }
                }             
                //printf("\033[2J\033[H"); // Очищаем консоль
                
     

                
             
                   // Координат для отрисовки мяча XBall, YBall
                    XBall += speedX;
                    YBall += speedY;
                    
                    //if (XBall == XLeftRocket && YBall >= YLeftRocket && YBall <= YLeftRocket+3) {
                        // мяч коснулся левой платформы меняем направление по оси X на противополжно
                        // знак у переменной скорость которая отвечает и за направление движение по оси X
                        if (XBall == XLeftRocket+1 ){

                            if (YBall == YLeftRocket) { // если мяч коснулся верха платформы то меняем направление на противоположное мяч отлетает в обратную сторону
                                if (speedY <=0) {
                                    speedY = 1;
                                } else {
                                    speedY = -1*speedY;
                                }                                
                                speedX = -1*speedX;
                            }
                            if (YBall == YLeftRocket+1) { // Если нижней части платформы то меняем по X а по Y оставляем как есть
                                speedX = -1*speedX;
                            }
                            if (YBall == YLeftRocket+1) { // Если нижней части платформы то меняем по X а по Y оставляем как есть
                                speedX = -1*speedX;
                                speedY = 0;
                            }
                        }
                    
                        if (XBall == XRightRocket-1 ){
                            if (YBall == YRightRocket){
                                
                                speedX = -1*speedX;
                                if (speedY <=0) {
                                    speedY = 1;
                                } else {
                                    speedY = -1*speedY;
                                }   
                            }
                            if (YBall == YRightRocket+1) { // Если нижней части платформы то меняем по X а по Y оставляем как есть
                                
                                speedX = -1*speedX;
                            }
                            if (YBall == YRightRocket+1) { // Если нижней части платформы то меняем по X а по Y оставляем как есть
                                
                                speedX = -1*speedX;
                                speedY = 0;
                            }
                        }

                     

                        if (YBall >= ScreenY-1) {
                            speedY = -1*speedY;
                        }
                        if (YBall <=1) {
                            speedY = -1*speedY;
                        }
                   // }                
                       
                printPole(ScreenX, ScreenY, YLeftRocket, XLeftRocket, YRightRocket, XRightRocket, XBall, YBall, GoalLeft, GoalRight);
                printf("creenX %d, ScreenY %d XBall %d,YBall %d,  XLeftRocket %d, YLeftRocket %d, XRightRocket %d, YRightRocket%d, speedX %d , speedY %d \n", ScreenX, ScreenY, XBall ,YBall, XLeftRocket,  YLeftRocket, XRightRocket, YRightRocket, speedX, speedY);
        }
    }
    return 0;
}

/* Рисует прямаугольная область заданой шириной width, и высотой height*/
int printPole(int width, int height, int YLeftRocket, int XLeftRocket, int YRightRocket, int XRightRocket, int XBall, int YBall, int GoalLeft, int ScoreRight) {
   

    // Вывод счета

    // рисуем вертикальную границу
    PrintTopBorder(width);
    


    for (int y= 1; y < height; ++y) {
        PrintVerticalBorder();

        for (int x =  0; x < width-1;++x) {
            if (x == width / 2) {
               PrintWeb() ;
                continue;
            }
            if (x == XLeftRocket && y >= YLeftRocket && y < YLeftRocket + 3 ){
                PrintLeftRocket();
                continue;
            }
             if (x == XRightRocket && y >= YRightRocket && y < YRightRocket + 3 ){
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

