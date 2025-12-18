#include <stdio. h>

// Функция кодирования символа в шестнадцатеричное представление
void encode_char(char c) {
    printf("%X", (unsigned char)c);
}

// Функция декодирования шестнадцатеричного числа в символ
int decode_hex(char *hex_str, char *result) {
    int value = 0;
    int i = 0;
    
    // Проверяем, что строка не пустая
    if (hex_str[0] == '\0') {
        return 0;  // Ошибка
    }
    
    // Парсим шестнадцатеричную строку
    while (hex_str[i] != '\0') {
        char c = hex_str[i];
        int digit;
        
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else {
            return 0;  // Некорректный символ
        }
        
        value = value * 16 + digit;
        i = i + 1;
    }
    
    // Проверяем, что значение в допустимом диапазоне ASCII
    if (value < 0 || value > 127) {
        return 0;
    }
    
    *result = (char)value;
    return 1;  // Успех
}

// Функция для проверки, является ли строка корректным hex-числом
int is_valid_hex(char *str) {
    int i = 0;
    int count = 0;
    
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n') {
        char c = str[i];
        if (! ((c >= '0' && c <= '9') || 
              (c >= 'A' && c <= 'F') || 
              (c >= 'a' && c <= 'f'))) {
            return 0;
        }
        count = count + 1;
        i = i + 1;
    }
    
    return count > 0;
}

int main(int argc, char *argv[]) {
    // Проверка наличия параметра командной строки
    if (argc != 2) {
        printf("n/a\n");
        return 1;
    }
    
    // Проверка корректности параметра (должен быть 0 или 1)
    if (argv[1][0] != '0' && argv[1][0] != '1') {
        printf("n/a\n");
        return 1;
    }
    
    if (argv[1][1] != '\0') {
        printf("n/a\n");
        return 1;
    }
    
    int mode = argv[1][0] - '0';
    
    if (mode == 0) {
        // Режим кодирования:  символы -> hex
        char c;
        int first = 1;
        int has_input = 0;
        int space_expected = 0;
        
        while (1) {
            int ch = getchar();
            if (ch == EOF || ch == '\n') {
                break;
            }
            
            c = (char)ch;
            
            if (c == ' ') {
                if (! has_input || space_expected == 0) {
                    printf("n/a\n");
                    return 1;
                }
                space_expected = 0;
                continue;
            }
            
            if (space_expected == 1) {
                // Ожидали пробел, но получили символ
                printf("n/a\n");
                return 1;
            }
            
            if (! first) {
                printf(" ");
            }
            
            encode_char(c);
            first = 0;
            has_input = 1;
            space_expected = 1;
        }
        
        if (!has_input) {
            printf("n/a\n");
            return 1;
        }
        
        printf("\n");
        
    } else {
        // Режим декодирования: hex -> символы
        char hex_str[100];
        int first = 1;
        int has_input = 0;
        int idx = 0;
        
        while (1) {
            int ch = getchar();
            
            if (ch == ' ' || ch == '\n' || ch == EOF) {
                if (idx > 0) {
                    hex_str[idx] = '\0';
                    
                    if (!is_valid_hex(hex_str)) {
                        printf("n/a\n");
                        return 1;
                    }
                    
                    char decoded_char;
                    if (! decode_hex(hex_str, &decoded_char)) {
                        printf("n/a\n");
                        return 1;
                    }
                    
                    if (! first) {
                        printf(" ");
                    }
                    printf("%c", decoded_char);
                    first = 0;
                    has_input = 1;
                    idx = 0;
                }
                
                if (ch == '\n' || ch == EOF) {
                    break;
                }
            } else {
                if (idx < 99) {
                    hex_str[idx] = (char)ch;
                    idx = idx + 1;
                } else {
                    printf("n/a\n");
                    return 1;
                }
            }
        }
        
        if (!has_input) {
            printf("n/a\n");
            return 1;
        }
        
        printf("\n");
    }
    
    return 0;
}
