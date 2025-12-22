virginwh@kr-h5:~/D07T04.ID_1577485-1$ cppcheck --enable=all --suppress=missingIncludeSystem src/key9part2.c
2025/12/22 22:44:22.381929 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
Checking src/key9part2.c ...
src/key9part2.c:19:9: style: The scope of the variable 'result' can be reduced. [variableScope]
    int result[LEN + 1];
        ^
src/key9part2.c:190:15: style: Parameter 'buff1' can be declared as pointer to const [constParameterPointer]
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length)
              ^
nofile:0:0: information: Active checkers: 106/592 (use --checkers-report=<filename> to see details) [checkersReport]
