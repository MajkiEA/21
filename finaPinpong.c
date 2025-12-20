bash: .src/pong: No such file or directory
virginwh@kr-h3:~/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1$ gcc -Wall -Wextra -Werror src/pong.c -o pong
src/pong.c: In function ‘PrintPole’:
src/pong.c:224:41: error: unused parameter ‘GoalLeft’ [-Werror=unused-parameter]
  224 |               int XBall, int YBall, int GoalLeft, int ScoreRight) {
      |                                     ~~~~^~~~~~~~
src/pong.c:224:55: error: unused parameter ‘ScoreRight’ [-Werror=unused-parameter]
  224 |               int XBall, int YBall, int GoalLeft, int ScoreRight) {
      |                                                   ~~~~^~~~~~~~~~
cc1: all warnings being treated as errors
virginwh@kr-h3:~/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1$ /.pong
bash: /.pong: No such file or directory
virginwh@kr-h3:~/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1$ gcc -Wall -Werror -Wextra src/pong.c -o pong
src/pong.c: In function ‘PrintPole’:
src/pong.c:224:41: error: unused parameter ‘GoalLeft’ [-Werror=unused-parameter]
  224 |               int XBall, int YBall, int GoalLeft, int ScoreRight) {
      |                                     ~~~~^~~~~~~~
src/pong.c:224:55: error: unused parameter ‘ScoreRight’ [-Werror=unused-parameter]
  224 |               int XBall, int YBall, int GoalLeft, int ScoreRight) {
      |                                                   ~~~~^~~~~~~~~~
cc1: all warnings being treated as errors
virginwh@kr-h3:~/D05P01.ID_1577484-Team_TL_shinoher.17f8fbf6_a34c_4a3f-1$ /.pong
bash: /.pong: No such file or directory
