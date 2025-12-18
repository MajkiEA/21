virginwh@kr-h3:~/D03T03.ID_1577483-1$ touch char_decode.c
virginwh@kr-h3:~/D03T03.ID_1577483-1$ clang-format -n src/char_decode.c 
2025/12/18 22:18:10.852860 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
virginwh@kr-h3:~/D03T03.ID_1577483-1$ clang-format -i src/char_decode.c 
2025/12/18 22:18:31.116112 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
virginwh@kr-h3:~/D03T03.ID_1577483-1$ clang-format -n src/char_decode.c 
2025/12/18 22:18:33.159049 cmd_run.go:1415: WARNING: will not expose Kerberos tickets' path: Unsupported KRB5CCNAME: KEYRING:persistent:1010037
