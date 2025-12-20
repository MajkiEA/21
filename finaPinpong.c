#include <stdio.h>
int PrintPole(int width, int height, int YLeftRocket, int XLeftRocket, int YRightRocket, int XRightRocket,
              int XBall, int YBall, int GoalLeft, int ScoreRight);
void PrintLeftRocket();
void PrintRightRocket();
void PrintWeb();
void PrintLeftBorderAndWeb(int width);
void PrintRightBorder(int width);
void LeftTopAngle();
void RightTopAngle();
void LeftBottomAngle();
void RightBottomAngle();
void HorizontalBorder(int width);
void PrintRightBorderAfterRocket();
void PrintBottomBorder();
void PrintTopBorder();
void PrintBall();
void PrintVerticalBorder();
void PrintScore(int ScreenX, int GoalLeft, int GoalRight);
void PrintBigDigit(int digit, int line);

int main() {
    int YLeftRocket = 12,
        YRightRocket =
            12;  // координаты платформ дпо вертикали Y = 12 для обеих платформа чтобы отобразить по середине
    int XBall = 3, YBall = 13;  // координаты мячика , мячк у левого игрока
    int speedX = 1, speedY = 1;  // скорость перемещения мячика 2 символа за ход
    int Player = 0;  // флаг хода:    0 Если  ход левого игрока,  1 ход правого игрока
    int GoalLeft = 0, GoalRight = 0;  // количество голов для левого и правого игрока
    int ScreenX = 80, ScreenY = 25;  // размер игровой площадки
    int XLeftRocket = 2, XRightRocket = ScreenX - 3;

    PrintScore(ScreenX, GoalLeft, GoalRight);
    PrintPole(ScreenX, ScreenY, YLeftRocket, XLeftRocket, YRightRocket, XRightRocket, XBall, YBall, GoalLeft,
              GoalRight);  // функция рисует игровое поле в начальном сотоянии
    printf("    \033[1m!!   Ход \x1b[36m синего \x1b[0m игрока !!\033[0m \n");

    char input;
    while (1) {             // Запускаем бесконечный цикл,
        input = getchar();  // ожидаем ввод с клавиатуры, считываем символ

        if (XBall <=
            0) {  // мяч вышел за левую границу, гол  синему игроку, сбрасываем все значения на начальные
            GoalLeft++;  // добавляем очко левому игроку
            printf("%*s%sГол \x1b[36m синему \x1b[0m  игроку\n ", ScreenX / 2 - 17, " ",
                   " ");                 // Сообщение Гол
            YLeftRocket = 12;            // положение сверху левой рокетки
            YRightRocket = 12;           // положение сверху правой рокетки
            XLeftRocket = 2;             // положение слева левой рокетки
            XRightRocket = ScreenX - 3;  // положение слева правой рокетки
            XBall = 3;  // начальное положение мяча в центре левой рокетки
            YBall = 13;  // начальное положение мяча в центре левой рокетки
            speedX = 1;  // начальная скорость и направление движения мяча по оси x
            speedY = 1;  // начальная скорость и направление движения мяча по оси y
            Player = 0;  // Игрок начинающий ход
            continue;
            // гол левому новый раунд

        } else if (XBall >= ScreenX - 1) {
            GoalRight++;  // добавляем очко правой игроку
            printf("%*s%sГол \x1b[31m красному \x1b[0m  игроку\n ", ScreenX / 2 - 17, " ",
                   " ");                 // Сообщение Гол
            YLeftRocket = 12;            // положение сверху левой рокетки
            YRightRocket = 12;           // положение сверху правой рокетки
            XLeftRocket = 2;             // положение слева левой рокетки
            XRightRocket = ScreenX - 3;  // положение слева правой рокетки
            XBall = XRightRocket - 2;  // начальное положение мяча в центре правой рокетки
            YBall = 13;  // начальное положение мяча в центре правой рокетки
            speedX = -1;  // начальная скорость и направление движения мяча по оси x
            speedY = -1;  // начальная скорость и направление движения мяча по оси y
            Player = 1;  // Игрок начинающий ход
            continue;
            // гол правому игроку, начинаем новый раунд
        }

        // проверка на счёт
        if (GoalLeft == 21) {
            printf("     Синий игрок попедил со счётом \x1b[34m%d\x1b[0m :   \x1b[31m%d\x1b[0m\n", GoalLeft,
                   GoalRight);
            return 0;
        }
        if (GoalRight == 21) {
            printf("     Красный игрок попедил со счётом \x1b[34m%d\x1b[0m :  \x1b[31m%d\x1b[0m\n", GoalLeft,
                   GoalRight);
            return 0;
        }

        switch (input) {  // проверяем какой символ введён
            case 'q':     // если введена q заканчиваем игру
                printf("Игра закончена");
                return 0;
            case '\n':  // игнориируем перевод строки клавиша ENTER
                break;
            default:                //
                if (Player == 0) {  // проверяем чей ход и в заисимости от нажатой клавиши устанавливаем
                                    // координаты платформы

                    switch (input) {  // ещё раз проверяем какой символ введён
                        case 'a':     // движение левой рокетки вверх
                            YLeftRocket -= 1;
                            if (YLeftRocket <= 0) {
                                YLeftRocket = 1;
                            }
                            Player = 1;  // передаём ход  другому игроку
                            break;
                        case 'z':  // движение левой рокетки вниз
                            YLeftRocket += 1;
                            if (YLeftRocket >= ScreenX) {
                                YLeftRocket = ScreenX - 3;
                            }
                            Player = 1;  // передаём ход  другому игроку
                            break;
                        case 'k':  
                            printf("\033[1m !!  Ход \x1b[34m синего\x1b[0m игрока !!\033[0m \n");
                            break;
                        case 'm':
                            printf("\033[1m!!   Ход \x1b[34m синего\x1b[0m игрока !!\033[0m \n");
                            break;
                        case ' ':        // если пробел
                            Player = 1;  // передаём ход  другому игроку
                            break;
                    }
                } else {
                    switch (input) {  // ещё раз проверяем какой символ введён
                        case 'a':  
                            printf("\033[1m !! Ход \x1b[31m красного\x1b[0m игрока !!\033[0m \n");
                            break;
                        case 'z':  
                            printf("\033[1m !! Ход \x1b[31m красного\x1b[0m игрока \033[1m ! !\033[0m \n");
                            break;
                        case 'k':   // движение правой рокетки вверх
                            YRightRocket -= 1;
                            if (YRightRocket <= 0) {
                                YRightRocket = 1;
                            }
                            Player = 0;  // передаём ход  другому игроку
                            break;
                        case 'm':  // движение левой правой вниз
                            YRightRocket += 1;
                            if (YRightRocket <= 0) {
                                YRightRocket = 1;
                            }
                            Player = 0;  // передаём ход  другому игроку
                            break;
                        case ' ':        // если пробед
                            Player = 0;  // передаём ход  другому игроку
                            break;
                    }
                }
                printf("\033[2J\033[H");  // Очищаем консоль

                // Координат для отрисовки мяча XBall, YBall
                XBall += speedX;
                YBall += speedY;

                if (XBall == XLeftRocket + 1) {  // мяч коснулся левой рокетки
                    // если мяч коснулся верха платформы то меняем направление на
                    // противоположное мяч отлетает в обратную сторону
                    if (YBall == YLeftRocket) {
                        if (speedY <= 0) {
                            speedY = 1;
                        } else {
                            speedY = -1 * speedY;
                        }
                        speedX = -1 * speedX;
                    }
                    // Если нижней части платформы то меняем по X а по Y оставляем как есть
                    if (YBall == YLeftRocket + 1) {
                        speedX = -1 * speedX;
                    }
                    // Если нижней части платформы то меняем по X а по Y оставляем как есть
                    if (YBall == YLeftRocket + 1) {
                        speedX = -1 * speedX;
                        speedY = 0;
                    }
                }

                // мячо коснулся правой рокетки
                if (XBall == XRightRocket - 1) {
                    if (YBall == YRightRocket) {
                        speedX = -1 * speedX;
                        if (speedY <= 0) {
                            speedY = 1;
                        } else {
                            speedY = -1 * speedY;
                        }
                    }
                    // Если нижней части платформы то меняем по X а по Y оставляем как есть
                    if (YBall == YRightRocket + 1) {
                        speedX = -1 * speedX;
                    }
                    // Если нижней части платформы то меняем по X а по Y оставляем как есть
                    if (YBall == YRightRocket + 1) {
                        speedX = -1 * speedX;
                        speedY = 0;
                    }
                }
                // если мяч коснулся низа поля меняем направление движения по Y чтобы он полетеле вверх
                if (YBall >= ScreenY - 1) {
                    speedY = -1 * speedY;
                }
                // если мяч коснулся верх поля меняем направление движения по Y чтобы он полетеле вниз
                if (YBall <= 1) {
                    speedY = -1 * speedY;
                }
                // }
                // Выводим счёт
                PrintScore(ScreenX, GoalLeft, GoalRight);
                // перерисовывем поле
                PrintPole(ScreenX, ScreenY, YLeftRocket, XLeftRocket, YRightRocket, XRightRocket, XBall,
                          YBall, GoalLeft, GoalRight);
                // Выводим подсказку какой игрок ходит
                if (Player == 0) {
                    printf("    \033[1m!!  Ход \x1b[34m синего \x1b[0m игрока !!\033[0m \n");
                } else {
                    printf("%*s%s \033[1m !! Ход \x1b[31m красного \x1b[0m игрока \033[1m !!\033[0m \n",
                           ScreenX / 2, " ", " ");
                }
        }
    }
    return 0;
}

/* Рисует прямаугольная область заданой шириной width, и высотой height*/
int PrintPole(int width, int height, int YLeftRocket, int XLeftRocket, int YRightRocket, int XRightRocket,
              int XBall, int YBall, int GoalLeft, int ScoreRight) {
    // Вывод счета (используем переменные, чтобы избежать предупреждения компилятора)
    (void)GoalLeft;
    (void)ScoreRight;

    // рисуем вертикальную границу
    PrintTopBorder(width);

    // рисуем остальное поле, проходим построчно и отрисовываем каждую строчку
    for (int y = 1; y < height; ++y) {
        // рисуем вертикальную черту левой границы
        PrintVerticalBorder();
        // проходим курсоромпо  всей ширине поля
        for (int x = 0; x < width - 1; ++x) {
            // если достигаем середины поля то рисуем сетку
            if (x == width / 2) {
                PrintWeb();
                continue;
            }
            // проверим если текущее положение курсора совпадает с координатой левой рокетки то рисем рокетку
            if (x == XLeftRocket && y >= YLeftRocket && y < YLeftRocket + 3) {
                PrintLeftRocket();
                continue;
            }
            // проверим если текущее положение курсора совпадает с координатой правой рокетки то рисем рокетку
            if (x == XRightRocket && y >= YRightRocket && y < YRightRocket + 3) {
                PrintRightRocket(width);
                continue;
            }
            // проверим если текущее положение курсора совпадает с координатой лмячика то рисем мячик
            if (x == XBall && y == YBall) {
                PrintBall();
                continue;
            }
            // рисуем пустой пробел
            printf(" ");
        }
        // когда прошли всю ширину поля рисуем вертикульную черту правой границу
        PrintVerticalBorder();
        printf("\n");
    }

    PrintBottomBorder(width);

    return 0;
}

// === НАЧАЛО ИЗМЕНЕНИЙ:  Функция вывода счёта большими цифрами ===
void PrintScore(int ScreenX, int GoalLeft, int GoalRight) {
    // Выводим счёт в виде больших ASCII-цифр (5 строк высотой)
    printf("\n");  // Отступ сверху
    
    // Выводим 5 строк больших цифр
    for (int line = 0; line < 5; line++) {
        // ИЗМЕНЕНО: Центрирование по середине экрана (относительно двоеточия)
        printf("%*s", ScreenX / 2 - 8, " ");  
        
        // ИЗМЕНЕНО: Левая цифра (синий игрок) - изменён цвет с \x1b[36m на \x1b[34m
        printf("\x1b[34m");  // Синий цвет (было 36 - голубой, стало 34 - синий)
        PrintBigDigit(GoalLeft, line);
        printf("\x1b[0m");  // Сброс цвета
        
        // Разделитель ":"
        if (line == 2) {
            printf("  :  ");
        } else {
            printf("     ");
        }
        
        // Правая цифра (красный игрок) - цвет остался \x1b[31m (красный)
        printf("\x1b[31m");  // Красный цвет
        PrintBigDigit(GoalRight, line);
        printf("\x1b[0m");  // Сброс цвета
        
        printf("\n");
    }
    
    printf("\n");  // Отступ снизу
}

// ИЗМЕНЕНО: Функция рисования одной строки большой цифры - все цифры теперь пишутся как левая (без сдвига)
void PrintBigDigit(int digit, int line) {
    // Массив ASCII-арт для цифр 0-9 (5 строк высотой, 5 символов шириной)
    const char *digits[10][5] = {
        // Цифра 0
        {" ███ ", "█   █", "█   █", "█   █", " ███ "},
        // Цифра 1
        {"  █  ", " ██  ", "  █  ", "  █  ", "█████"},
        // Цифра 2
        {" ███ ", "█   █", "   █ ", "  █  ", "█████"},
        // Цифра 3
        {" ███ ", "█   █", "  ██ ", "█   █", " ███ "},
        // Цифра 4
        {"█   █", "█   █", "█████", "    █", "    █"},
        // Цифра 5
        {"█████", "█    ", "████ ", "    █", "████ "},
        // Цифра 6
        {" ███ ", "█    ", "████ ", "█   █", " ███ "},
        // Цифра 7
        {"█████", "    █", "   █ ", "  █  ", " █   "},
        // Цифра 8
        {" ███ ", "█   █", " ███ ", "█   █", " ███ "},
        // Цифра 9
        {" ███ ", "█   █", " ████", "    █", " ███ "}
    };
    
    // ИЗМЕНЕНО: Теперь все цифры выводятся одинаково (без разделения на десятки/единицы)
    // Если цифра больше 9, выводим как однозначное (берём остаток от деления на 10)
    if (digit > 9) {
        digit = digit % 10;  // Берём последнюю цифру
    }
    
    printf("%s", digits[digit][line]);
}
// === КОНЕЦ ИЗМЕНЕНИЙ ===

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
    // рисуем угол
    LeftTopAngle();
    // Горизонтальная линия
    HorizontalBorder(width);
    // рисуем угол
    RightTopAngle();
    return;
}
void PrintBottomBorder(int width) {
    // рисуем угол
    LeftBottomAngle();
    // Горизонтальная линия
    HorizontalBorder(width);
    // рисуем угол
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
