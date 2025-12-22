virginwh@kr-h5:~/D07T04.ID_1577485-1$ clang-format -n squaring.c
2025/12/22 19:44:13.652771 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
No such file or directory
virginwh@kr-h5:~/D07T04.ID_1577485-1$ clang-format -i squaring.c
2025/12/22 19:44:18.579652 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
No such file or directory
virginwh@kr-h5:~/D07T04.ID_1577485-1$ clang-format -n src/squaring.c
2025/12/22 19:44:24.237213 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
src/squaring.c:9:15: warning: code should be clang-formatted [-Wclang-format-violations]
    int n = 0;          // сюда запишем, сколько чисел ввёл пользователь
src/squaring.c:10:20: warning: code should be clang-formatted [-Wclang-format-violations]
    int data[NMAX];     // здесь храним сами числа (не больше 10 штук)
virginwh@kr-h5:~/D07T04.ID_1577485-1$ clang-format -i src/squaring.c
2025/12/22 19:45:39.653222 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
virginwh@kr-h5:~/D07T04.ID_1577485-1$ clang-format -n src/squaring.c
2025/12/22 19:45:41.591267 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
virginwh@kr-h5:~/D07T04.ID_1577485-1$ clang-format -n src/squaring.c
2025/12/22 19:51:46.983466 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
virginwh@kr-h5:~/D07T04.ID_1577485-1$ cppcheck --enable=all --suppress=missingIncludeSystem squaring.c
2025/12/22 19:52:30.339660 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
cppcheck: error: could not find or open any of the paths given.
virginwh@kr-h5:~/D07T04.ID_1577485-1$ cppcheck --enable=all --suppress=missingIncludeSystem src/squaring.c
2025/12/22 19:52:35.368668 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
Checking src/squaring.c ...
src/squaring.c:55:18: style: Parameter 'a' can be declared as pointer to const [constParameterPointer]
void output(int *a, int n) {
                 ^
nofile:0:0: information: Active checkers: 106/592 (use --checkers-report=<filename> to see details) [checkersReport]

virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrind --tool=memcheck --leak-check=yes ./squaring
valgrind: ./squaring: Permission denied
virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrind --tool=memcheck --leak-check=yes ./squaring
valgrind: ./squaring: Permission denied
virginwh@kr-h5:~/D07T04.ID_1577485-1$ gcc -Wall -Wextra -Werror -std=c11 src/squaring.c -o squaring
virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrind --tool=memcheck --leak-check=yes ./squaring
==643558== Memcheck, a memory error detector
==643558== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==643558== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==643558== Command: ./squaring
==643558== 
3           
1 2 3
1 4 9==643558== 
==643558== HEAP SUMMARY:
==643558==     in use at exit: 0 bytes in 0 blocks
==643558==   total heap usage: 2 allocs, 2 frees, 2,048 bytes allocated
==643558== 
==643558== All heap blocks were freed -- no leaks are possible
==643558== 
==643558== For lists of detected and suppressed errors, rerun with: -s
==643558== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
virginwh@kr-h5:~/D07T04.ID_1577485-1$ 
