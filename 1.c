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
virginwh@kr-h5:~/D07T04.ID_1577485-1$ cppcheck --enable=all --suppress=missingIncludeSystem src/maxmin.c
2025/12/22 15:45:31.549148 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
Checking src/maxmin.c ...
nofile:0:0: information: Active checkers: 106/592 (use --checkers-report=<filename> to see details) [checkersReport]

virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrid --tool=memcheck --leak-check=yes ./maxmin
WARNING:root:could not open file '/etc/apt/sources.list': [Errno 13] Permission denied: '/etc/apt/sources.list'

Command 'valgrid' not found, did you mean:
  command 'valgrind' from snap valgrind (3.26.0)
  command 'valgrind' from deb valgrind (1:3.22.0-0ubuntu2)
See 'snap info <snapname>' for additional versions.
virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrid --tool=memcheck --leak-check=yes /.maxmin
WARNING:root:could not open file '/etc/apt/sources.list': [Errno 13] Permission denied: '/etc/apt/sources.list'

Command 'valgrid' not found, did you mean:
  command 'valgrind' from snap valgrind (3.26.0)
  command 'valgrind' from deb valgrind (1:3.22.0-0ubuntu2)
See 'snap info <snapname>' for additional versions.
virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrid --tool=memcheck --leak-check=yes src/.maxmin
WARNING:root:could not open file '/etc/apt/sources.list': [Errno 13] Permission denied: '/etc/apt/sources.list'

Command 'valgrid' not found, did you mean:
  command 'valgrind' from snap valgrind (3.26.0)
  command 'valgrind' from deb valgrind (1:3.22.0-0ubuntu2)
See 'snap info <snapname>' for additional versions.
virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrid --tool=memcheck --leak-check=yes ./maxmin
WARNING:root:could not open file '/etc/apt/sources.list': [Errno 13] Permission denied: '/etc/apt/sources.list'

Command 'valgrid' not found, did you mean:
  command 'valgrind' from snap valgrind (3.26.0)
  command 'valgrind' from deb valgrind (1:3.22.0-0ubuntu2)
See 'snap info <snapname>' for additional versions.
virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrind --tool=memcheck --leak check=yes ./maxmin
valgrind: check=yes: command not found
virginwh@kr-h5:~/D07T04.ID_1577485-1$ valgrind --tool=memcheck --leak-check=yes ./maxmin
==622036== Memcheck, a memory error detector
==622036== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==622036== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==622036== Command: ./maxmin
==622036== 
  тут он как-будто ждёт ввода, нужно что-то ввводить?
