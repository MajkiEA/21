#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

static int encode_char(char c, char *out) {
    /* Пишем двухсимвольный HEX в верхнем регистре */
    return sprintf(out, "%02X", (unsigned char)c);
}

static int hex_to_val(char ch, int *out) {
    if ('0' <= ch && ch <= '9') {
        *out = ch - '0';
        return 1;
    }
    if ('A' <= ch && ch <= 'F') {
        *out = ch - 'A' + 10;
        return 1;
    }
    if ('a' <= ch && ch <= 'f') {
        *out = ch - 'a' + 10;
        return 1;
    }
    return 0;
}

static int decode_token(const char *tok, char *out) {
    /* Токен должен быть ровно из 2 hex-символов */
    if (strlen(tok) != 2) return 0;
    int hi, lo;
    if (!hex_to_val(tok[0], &hi)) return 0;
    if (!hex_to_val(tok[1], &lo)) return 0;
    *out = (char)((hi << 4) | lo);
    return 1;
}

static int has_single_spaces_only(const char *s) {
    /* Проверка: между токенами ровно один пробел, нет ведущих/хвостовых */
    if (*s == ' ' || *s == '\0') return 0;
    for (size_t i = 0; s[i]; ++i) {
        if (s[i] == ' ') {
            if (s[i + 1] == ' ' || s[i + 1] == '\0') return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2 || (argv[1][0] != '0' && argv[1][0] != '1') || argv[1][1] != '\0') {
        printf("n/a\n");
        return 1;
    }

    char line[BUF_SIZE];
    if (!fgets(line, sizeof(line), stdin)) {
        printf("n/a\n");
        return 1;
    }

    /* Убираем завершающий \n */
    size_t len = strlen(line);
    if (len && line[len - 1] == '\n') line[len - 1] = '\0';

    if (!has_single_spaces_only(line)) {
        printf("n/a\n");
        return 1;
    }

    int mode = argv[1][0] - '0';

    if (mode == 0) {
        /* Кодирование: ожидаем токены длиной 1 символ */
        char *tok = strtok(line, " ");
        int first = 1;
        while (tok) {
            if (strlen(tok) != 1) {
                printf("n/a\n");
                return 1;
            }
            char buf[3];
            encode_char(tok[0], buf);
            if (!first) printf(" ");
            printf("%s", buf);
            first = 0;
            tok = strtok(NULL, " ");
        }
        if (first) { /* не было ни одного токена */
            printf("n/a\n");
            return 1;
        }
        printf("\n");
    } else {
        /* Декодирование: ожидаем токены длиной 2 HEX-символа */
        char *tok = strtok(line, " ");
        int first = 1;
        while (tok) {
            char c;
            if (!decode_token(tok, &c)) {
                printf("n/a\n");
                return 1;
            }
            if (!first) printf(" ");
            printf("%c", c);
            first = 0;
            tok = strtok(NULL, " ");
        }
        if (first) { /* не было токенов */
            printf("n/a\n");
            return 1;
        }
        printf("\n");
    }

    return 0;
}
