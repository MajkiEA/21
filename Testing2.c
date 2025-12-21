11
virginwh@kr-h5:~/D03T03.ID_1577483-1$ gcc -Wall -Werror -Wextra src/char_decode.c -o char_decode
src/char_decode.c: In function ‘decode_hex’:
src/char_decode.c:33:33: error: implicit declaration of function ‘strtoul’; did you mean ‘strtok’? [-Werror=implicit-function-declaration]
   33 |             unsigned long val = strtoul(hex_pair, NULL, 16); // Преобразование из HEX в десятичное
      |                                 ^~~~~~~
      |                                 strtok
src/char_decode.c: In function ‘main’:
src/char_decode.c:48:16: error: implicit declaration of function ‘atoi’ [-Werror=implicit-function-declaration]
   48 |     int mode = atoi(argv[1]);
      |                ^~~~
src/char_decode.c: In function ‘encode_hex’:
src/char_decode.c:14:54: error: ‘snprintf’ output truncated before the last format character [-Werror=format-truncation=]
   14 |         snprintf(hex_value, sizeof(hex_value), "%02X ", (unsigned char)input_str[i]);
      |                                                      ^
src/char_decode.c:14:9: note: ‘snprintf’ output 4 bytes into a destination of size 3
   14 |         snprintf(hex_value, sizeof(hex_value), "%02X ", (unsigned char)input_str[i]);
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cc1: all warnings being treated as errors
virginwh@kr-h5:~/D03T03.ID_1577483-1$ ./char_decode
bash: ./char_decode: No such file or directory
virginwh@kr-h5:~/D03T03.ID_1577483-1$ /.char_decode
bash: /.char_decode: No such file or directory
virginwh@kr-h5:~/D03T03.ID_1577483-1$ /.char_decode
bash: /.char_decode: No such file or directory
virginwh@kr-h5:~/D03T03.ID_1577483-1$ /.char_decode
bash: /.char_decode: No such file or directory
virginwh@kr-h5:~/D03T03.ID_1577483-1$ gcc src/char_decode.c -o char-decode
src/char_decode.c: In function ‘decode_hex’:
src/char_decode.c:33:33: warning: implicit declaration of function ‘strtoul’; did you mean ‘strtok’? [-Wimplicit-function-declaration]
   33 |             unsigned long val = strtoul(hex_pair, NULL, 16); // Преобразование из HEX в десятичное
      |                                 ^~~~~~~
      |                                 strtok
src/char_decode.c: In function ‘main’:
src/char_decode.c:48:16: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
   48 |     int mode = atoi(argv[1]);
      |                ^~~~
src/char_decode.c: In function ‘encode_hex’:
src/char_decode.c:14:54: warning: ‘snprintf’ output truncated before the last format character [-Wformat-truncation=]
   14 |         snprintf(hex_value, sizeof(hex_value), "%02X ", (unsigned char)input_str[i]);
      |                                                      ^
src/char_decode.c:14:9: note: ‘snprintf’ output 4 bytes into a destination of size 3
   14 |         snprintf(hex_value, sizeof(hex_value), "%02X ", (unsigned char)input_str[i]);
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
