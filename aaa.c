virginwh@kr-h5:~/D07T04.ID_1577485-1$ cppcheck --enable=all --suppress=missingIncludeSystem src/cycle_shift.c 
2025/12/22 23:06:37.312479 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
Checking src/cycle_shift.c ...
src/cycle_shift.c:142:9: style: The scope of the variable 'normalized_shift' can be reduced. [variableScope]
    int normalized_shift = 0;
        ^
src/cycle_shift.c:142:26: style: Variable 'normalized_shift' is assigned a value that is never used. [unreadVariable]
    int normalized_shift = 0;
                         ^
nofile:0:0: information: Active checkers: 106/592 (use --checkers-report=<filename> to see details) [checkersReport]
