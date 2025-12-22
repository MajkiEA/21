virginwh@kr-h5:~/D07T04.ID_1577485-1$ gcc -Wall -Werror -std=c11 src/maxmin.c -o maxmin
virginwh@kr-h5:~/D07T04.ID_1577485-1$ ./maxmin
1 2 3
3 1virginwh@kr-h5:~/D07T04.ID_1577485-1$ clang-format -n maxmin.c
2025/12/22 15:36:25.101324 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
No such file or directory
virginwh@kr-h5:~/D07T04.ID_1577485-1$ ccpcheck --enable=all --suppress=missingIncludeSystem maxmin.c
WARNING:root:could not open file '/etc/apt/sources.list': [Errno 13] Permission denied: '/etc/apt/sources.list'

Command 'ccpcheck' not found, did you mean:
  command 'cppcheck' from snap cppcheck (2.13.99)
  command 'cccheck' from deb mono-devel (6.8.0.105+dfsg-3.5ubuntu1)
  command 'cppcheck' from deb cppcheck (2.13.0-2)
See 'snap info <snapname>' for additional versions.
virginwh@kr-h5:~/D07T04.ID_1577485-1$ ccpcheck --enable=all --suppress=missingIncludeSystem src/maxmin.c
WARNING:root:could not open file '/etc/apt/sources.list': [Errno 13] Permission denied: '/etc/apt/sources.list'

Command 'ccpcheck' not found, did you mean:
  command 'cppcheck' from snap cppcheck (2.13.99)
  command 'cppcheck' from deb cppcheck (2.13.0-2)
  command 'cccheck' from deb mono-devel (6.8.0.105+dfsg-3.5ubuntu1)
See 'snap info <snapname>' for additional versions.
virginwh@kr-h5:~/D07T04.ID_1577485-1$ ccpcheck --enable=all --suppress=missingIncludeSystem src/maxmin.c

