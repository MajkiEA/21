#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846
#define A2 2.0  // a^2 для лемнискаты Бернулли (a = sqrt(2))

static double agnesi(double x) {
    return 1.0 / (x * x + 1.0);
}

static int bernoulli_lemniscate(double x, double *out_y) {
    // Решаем (x^2 + y^2)^2 = A2 * (x^2 - y^2) при y >= 0.
    double x2 = x * x;
    double x4 = x2 * x2;
    double B = 2.0 * x2 + A2;
    double C = x4 - A2 * x2;
    double D = B * B - 4.0 * C;  // дискриминант

    if (D < 0.0) {
        return 0;  // не определена
    }

    double sqrtD = sqrt(D);
    double y2 = (-B + sqrtD) / 2.0;  // выбираем плюс, чтобы иметь шанс на y^2 >= 0
    if (y2 <= 0.0) {
        return 0;  // не определена
    }

    *out_y = sqrt(y2);  // y >= 0 по условию
    return 1;
}

static int quadratic_hyperbola(double x, double *out_y) {
    if (x == 0.0) {
        return 0;  // не определена
    }
    *out_y = 1.0 / (x * x);
    return 1;
}

int main(void) {
    const int points = 42;
    const double step = (2.0 * PI) / (points - 1);  // 41 шага между 42 точками

    for (int i = 0; i < points; ++i) {
        double x = -PI + step * i;

        double f1 = agnesi(x);

        double f2_val = 0.0;
        int f2_ok = bernoulli_lemniscate(x, &f2_val);

        double f3_val = 0.0;
        int f3_ok = quadratic_hyperbola(x, &f3_val);

        // Подготовим вывод с 7 знаками после запятой
        char buf1[32], buf2[32], buf3[32];
        snprintf(buf1, sizeof(buf1), "%.7f", f1);

        if (f2_ok) {
            snprintf(buf2, sizeof(buf2), "%.7f", f2_val);
        } else {
            snprintf(buf2, sizeof(buf2), "-");
        }

        if (f3_ok) {
            snprintf(buf3, sizeof(buf3), "%.7f", f3_val);
        } else {
            snprintf(buf3, sizeof(buf3), "-");
        }

        printf("%.7f | %s | %s | %s\n", x, buf1, buf2, buf3);
    }
    return 0;
}
