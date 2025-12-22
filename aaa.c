virginwh@kr-h5:~/D07T04.ID_1577485-1$ clang-format -n src/squaring.c 
2025/12/22 20:15:47.833707 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
virginwh@kr-h5:~/D07T04.ID_1577485-1$ gcc -Wall -Wextra -Werror -std=c11 src/squaring.c -o squaring
virginwh@kr-h5:~/D07T04.ID_1577485-1$ ./squaring 
3 
1 2 3
1 4 9virginwh@kr-h5:~/D07T04.ID_157748 cppcheck --enable=all --suppress=missingIncludeSystem src/squaring.c src/squaring.c 
2025/12/22 20:16:25.607709 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
Checking src/squaring.c ...
nofile:0:0: information: Active checkers: 106/592 (use --checkers-report=<filename> to see details) [checkersReport]

virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrind --tool=memcheck --leak-check=yes ./squaring
==646105== Memcheck, a memory error detector
==646105== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==646105== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==646105== Command: ./squaring
==646105== 
3
1 2 3
1 4 9==646105== 
==646105== HEAP SUMMARY:
==646105==     in use at exit: 0 bytes in 0 blocks
==646105==   total heap usage: 2 allocs, 2 frees, 2,048 bytes allocated
==646105== 
==646105== All heap blocks were freed -- no leaks are possible
==646105== 
==646105== For lists of detected and suppressed errors, rerun with: -s
==646105== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
