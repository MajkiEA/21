Следующие задание командное. 
Quest: Level 1. Hall
Получен Quest. Разработать программу src/pong.c, представляющую из себя игру для двух игроков, схожую с игрой Pong. Для отображения графики использовать только символьную (ASCII) графику (с выводом в терминал). Вам с командой необходимо реализовать пошаговый вариант исключительно в рамках уже изученного материала и стандартной библиотеки.
ВАЖНО! Запрещено выполнять системные вызовы, используя функцию system() и другие аналогичные ей функции, которые могут обращаться напрямую к ядру системы. Данный запрет распространяется и на последующую задачу.

Управление:

A/Z и K/M для перемещения ракеток.
Space Bar для пропуска действия на очередном шаге игры в пошаговом режиме.
После запуска программа переходит к ожиданию корректного ввода, т. е. один из игроков должен передвинуть свою ракетку или пропустить ход. После чего происходит отрисовка, и программа снова переходит к ожиданию ввода. И так игра продолжается, пока не будет завершена.
Графика:

Поле — прямоугольник 80 на 25 символов.
Размер ракетки — 3 символа.
Размер мяча — 1 символ.
UI/UX:

После достижения одним из игроков счета в 21 очко игра выводит поздравление победителя и завершается.

Такой гитлаб D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1
Selected
master 
default
 
protected
Branches 
2
develop-m
develop

Как мне войти в файлы и создать свою ветку, например develop-virginwh

Вот что человек уже сделал другой:
.clang-format
BasedOnStyle: Google
IndentWidth: 4
ColumnLimit: 110
.gitkeep
0 B
Empty file

pong.c
#include <stdio.h>
int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XCoordBall, int YCoordBall);
void PrintLeftRocket(int width);
void PrintRightRocket(int width);

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
    //рисуем угол
    LeftTopAngle()

    HorizontalBorder(width);
  
    //рисуем угол
    RightTopAngle();  

    // рисуем вертикальную границу
    for (int indexVerticalLine = 0; indexVerticalLine < height; ++indexVerticalLine) {
        if (indexVerticalLine >= YLeftRocket && indexVerticalLine < YLeftRocket + 3) {
            // рисуем левую рокетку
             PrintLeftRocket(width);
            // рисуем сетку
            printf("%*s%s", width / 2 - 4, "░", "");
            // рисуем правую границу
        } else {
            // рисуем сетку
            printf("\x1b[35m|\x1b[0m%*s%s", width / 2, "░", "");
        }

        if (indexVerticalLine >= YRightRocket && indexVerticalLine < YRightRocket + 3) {
            // рисуем правую рокетку
            PrintRightRocket(width);
            // рисуем правую границу и переходим на седующую строку
            printf("%*s\x1b[35m|\x1b[0m\n", 2, "");

        } else {
            // рисуем правую границу и переходим на следующую строку
            printf("%*s\x1b[35m|\x1b[0m\n", width / 2, "");
        }
    }

    //рисуем угол
    printf("\x1b[35m└");

    for (int k = 0; k < width - 2; ++k) {  // рисуем горизонтальную линию длиной равно ширине поля -2, потому
                                           // что левый и правый угол рисуются отдельно
        printf("─");
    }
   //рисуем угол
    printf("┘\x1b[0m\n");
    return 0;
}

void PrintLeftRocket(int width) {
    printf("\x1b[35m|\x1b[0m\x1b[36m%*s%s\x1b[0m", width - 74, "▓", "");
    return;
}
void PrintRightRocket(int width) {
    printf("\x1b[32m%*s%s\x1b[0m", width / 2, "▓", "");
    return;
}

void LeftTopAngle() {
    printf("\x1b[35m┌");
    return;
}

void RightTopAngle(){
    printf("┐\x1b[0m\n");
}

void HorizontalBorder(width) {
    for (int i = 0; i < width - 2; ++i) {  
        // рисуем горизонтальную линию длиной равно ширине поля -2, потому
        // что левый и правый угол рисуются отдельно
        printf("─");
    }
}

Моя задача сделать мячик, который будет отталкиваться. Сделай это, обьясни весь код, и скажи как запустить.
