virginwh@kr-h5:~/D07T04.ID_1577485-1$ cppcheck --enable=all --suppress=missingIncludeSystem src/key9part1.c
2025/12/22 21:44:17.844759 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
Checking src/key9part1.c ...
src/key9part1.c:69:18: style: Parameter 'buffer' can be declared as pointer to const [constParameterPointer]
void output(int *buffer, int length)
                 ^
src/key9part1.c:84:22: style: Parameter 'buffer' can be declared as pointer to const [constParameterPointer]
int sum_numbers(int *buffer, int length)
                     ^
src/key9part1.c:106:23: style: Parameter 'buffer' can be declared as pointer to const [constParameterPointer]
int find_numbers(int* buffer, int length, int number, int* numbers)
                      ^
nofile:0:0: information: Active checkers: 106/592 (use --checkers-report=<filename> to see details) [checkersReport]

virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrind --tool=memcheck --leak-check=yes ./key9part1
==657513== Memcheck, a memory error detector
==657513== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==657513== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==657513== Command: ./key9part1
==657513== 
10
4 3 9 0 1 2 0 2 7 -1
8
4 1 2 2 -1==657513== 
==657513== HEAP SUMMARY:
==657513==     in use at exit: 0 bytes in 0 blocks
==657513==   total heap usage: 2 allocs, 2 frees, 2,048 bytes allocated
==657513== 
==657513== All heap blocks were freed -- no leaks are possible
==657513== 
==657513== For lists of detected and suppressed errors, rerun with: -s
==657513== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
virginwh@kr-h5:~/D07T04.ID_1577485-1$ 
