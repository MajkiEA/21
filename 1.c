
git clone git@gitlab.com:path/to/D05P01.ID_1577484-Team_TL_shinoher. 17f8fbf6_a34c_4a3f-1. git

#include <stdio.h>

// ========== Константы ==========
#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define WIN_SCORE 21

// ========== Глобальные переменные ==========
int leftScore = 0, rightScore = 0;
int ballX, ballY;    // координаты мяча
int ballVX, ballVY;  // скорость мяча (направление:  ±1)

// ========== Прототипы функций отрисовки (из кода товарища) ==========
void LeftTopAngle();
void RightTopAngle();
void LeftBottomAngle();
void RightBottomAngle();
void HorizontalBorder(int width);
void PrintLeftBorderAndWeb(int width);
void PrintRightBorder(int width);
void PrintLeftRocket(int width);
void PrintRightRocket(int width);
void PrintRightBorderAfterRocket();
void PrintWeb(int width);
void PrintTopBorder(int width);
void PrintBottomBorder(int width);

int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XCoordBall, int YCoordBall);

// ========== Функции для мяча ==========
void resetBall() {
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    ballVX = 1;   // движется вправо
    ballVY = 1;   // движется вниз
}

void moveBall(int leftY, int rightY) {
    // Двигаем мяч
    ballX += ballVX;
    ballY += ballVY;

    // Отскок от верхней/нижней границы
    if (ballY <= 1 || ballY >= HEIGHT - 1) {
        ballVY = -ballVY;
    }

    // Отскок от левой ракетки (X = 2, ракетка занимает 3 клетки по Y)
    if (ballX == 3 && ballY >= leftY && ballY < leftY + PADDLE_SIZE) {
        ballVX = -ballVX;
    }

    // Отскок от правой ракетки (X = WIDTH - 3 = 77)
    if (ballX == WIDTH - 4 && ballY >= rightY && ballY < rightY + PADDLE_SIZE) {
        ballVX = -ballVX;
    }

    // Гол в левые ворота
    if (ballX <= 1) {
        rightScore++;
        resetBall();
    }

    // Гол в правые ворота
    if (ballX >= WIDTH - 2) {
        leftScore++;
        resetBall();
    }
}

// ========== Функции отрисовки (из кода товарища) ==========
void LeftTopAngle() { printf("\x1b[35m┌"); }
void RightTopAngle() { printf("┐\x1b[0m\n"); }
void LeftBottomAngle() { printf("\x1b[35m└"); }
void RightBottomAngle() { printf("┘\x1b[0m\n"); }

void HorizontalBorder(int width) {
    for (int i = 0; i < width - 2; ++i) {
        printf("─");
    }
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

void PrintWeb(int width) {
    printf("%*s%s", width / 2 - 4, "░", "");
}

void PrintLeftBorderAndWeb(int width) {
    printf("\x1b[35m|\x1b[0m%*s%s", width / 2, "░", "");
}

void PrintRightBorder(int width) {
    printf("%*s\x1b[35m|\x1b[0m\n", width / 2, "");
}

void PrintLeftRocket(int width) {
    printf("\x1b[35m|\x1b[0m\x1b[36m%*s%s\x1b[0m", width - 74, "▓", "");
}

void PrintRightRocket(int width) {
    printf("\x1b[32m%*s%s\x1b[0m", width / 2, "▓", "");
}

void PrintRightBorderAfterRocket() {
    printf("%*s\x1b[35m|\x1b[0m\n", 2, "");
}

// ========== Основная функция отрисовки ==========
int printPole(int width, int height, int YLeftRocket, int YRightRocket, int XCoordBall, int YCoordBall) {
    int MaxYRocket = 22;
    if (YLeftRocket > MaxYRocket) YLeftRocket = MaxYRocket;
    if (YRightRocket > MaxYRocket) YRightRocket = MaxYRocket;
    if (YLeftRocket < 1) YLeftRocket = 1;
    if (YRightRocket < 1) YRightRocket = 1;

    PrintTopBorder(width);

    for (int y = 0; y < height; ++y) {
        // Левая граница + ракетка
        if (y >= YLeftRocket && y < YLeftRocket + PADDLE_SIZE) {
            PrintLeftRocket(width);
        } else {
            PrintLeftBorderAndWeb(width);
        }

        // Рисуем мяч (если на этой строке)
        if (y == YCoordBall) {
            // Вычисляем, сколько пробелов до мяча от центра
            int offset = XCoordBall - width / 2;
            if (offset > 0) {
                printf("%*s", offset - 1, "");  // пробелы до мяча
                printf("O");                     // мяч
            } else {
                PrintWeb(width);
            }
        } else {
            PrintWeb(width);
        }

        // Правая граница + ракетка
        if (y >= YRightRocket && y < YRightRocket + PADDLE_SIZE) {
            PrintRightRocket(width);
            PrintRightBorderAfterRocket();
        } else {
            PrintRightBorder(width);
        }
    }

    PrintBottomBorder(width);
    printf("Счёт: \x1b[36mЛевый %d\x1b[0m :  \x1b[32mПравый %d\x1b[0m\n", leftScore, rightScore);
    printf("Управление: A/Z (левая ↑↓), K/M (правая ↑↓), пробел (пропуск), q (выход)\n");
    return 0;
}

// ========== MAIN ==========
int main() {
    int LeftY = 12, RightY = 12;
    resetBall();

    printPole(WIDTH, HEIGHT, LeftY, RightY, ballX, ballY);

    char input;
    while (1) {
        input = getchar();

        if (input == 'q') {
            printf("Игра завершена.\n");
            return 0;
        }
        if (input == '\n') continue;  // игнорируем перевод строки

        // Обработка управления
        switch (input) {
            case 'a':  LeftY--; break;   // левая ракетка вверх
            case 'z': LeftY++; break;   // левая ракетка вниз
            case 'k': RightY--; break;  // правая ракетка вверх
            case 'm': RightY++; break;  // правая ракетка вниз
            case ' ': break;            // пропуск хода
            default:  continue;          // неизвестная клавиша — игнор
        }

        // Ограничиваем позиции ракеток
        if (LeftY < 1) LeftY = 1;
        if (LeftY > HEIGHT - PADDLE_SIZE - 1) LeftY = HEIGHT - PADDLE_SIZE - 1;
        if (RightY < 1) RightY = 1;
        if (RightY > HEIGHT - PADDLE_SIZE - 1) RightY = HEIGHT - PADDLE_SIZE - 1;

        // Двигаем мяч
        moveBall(LeftY, RightY);

        // Перерисовываем поле
        printPole(WIDTH, HEIGHT, LeftY, RightY, ballX, ballY);

        // Проверяем победу
        if (leftScore >= WIN_SCORE) {
            printf("\x1b[36m🎉 ПОБЕДИЛ ЛЕВЫЙ ИГРОК! 🎉\x1b[0m\n");
            break;
        }
        if (rightScore >= WIN_SCORE) {
            printf("\x1b[32m🎉 ПОБЕДИЛ ПРАВЫЙ ИГРОК!  🎉\x1b[0m\n");
            break;
        }
    }

    return 0;
}
