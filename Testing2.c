                // Координат для отрисовки мяча XBall, YBall
                XBall += speedX;
                YBall += speedY;

                if (XBall == XLeftRocket + 1) {  // мяч коснулся левой рокетки
                    // если мяч коснулся верха платформы то меняем направление на
                    // противоположное мяч отлетает в обратную сторону
                    if (YBall == YLeftRocket) {
                        if (speedY <= 0) {
                            speedY = 1;
                        } else {
                            speedY = -1 * speedY;
                        }
                        speedX = -1 * speedX;
                    }
                    // Если нижней части платформы то меняем по X а по Y оставляем как есть
                    if (YBall == YLeftRocket + 1) {
                        speedX = -1 * speedX;
                    }
                    // Если нижней части платформы то меняем по X а по Y оставляем как есть
                    if (YBall == YLeftRocket + 1) {
                        speedX = -1 * speedX;
                        speedY = 0;
                    }
                }

                // мячо коснулся правой рокетки
                if (XBall == XRightRocket - 1) {
                    if (YBall == YRightRocket) {
                        speedX = -1 * speedX;
                        if (speedY <= 0) {
                            speedY = 1;
                        } else {
                            speedY = -1 * speedY;
                        }
                    }
                    // Если нижней части платформы то меняем по X а по Y оставляем как есть
                    if (YBall == YRightRocket + 1) {
                        speedX = -1 * speedX;
                    }
                    // Если нижней части платформы то меняем по X а по Y оставляем как есть
                    if (YBall == YRightRocket + 1) {
                        speedX = -1 * speedX;
                        speedY = 0;
                    }
                }
                // если мяч коснулся низа поля меняем направление движения по Y чтобы он полетеле вверх
                if (YBall >= ScreenY - 1) {
                    speedY = -1 * speedY;
                }
                // если мяч коснулся верх поля меняем направление движения по Y чтобы он полетеле вниз
                if (YBall <= 1) {
                    speedY = -1 * speedY;
                }
                // }
                // Выводим счёт
                PrintScore(ScreenX, GoalLeft, GoalRight);
                // перерисовывем поле
                PrintPole(ScreenX, ScreenY, YLeftRocket, XLeftRocket, YRightRocket, XRightRocket, XBall,
                          YBall, GoalLeft, GoalRight);
                // Выводим подсказку какой игрок ходит
                if (Player == 0) {
                    printf("    \033[1m!! Ход \x1b[36m синего \x1b[0m игрока !!\033[0m \n");
                } else {
                    printf("%*s%s \033[1m !! Ход \x1b[31m красного \x1b[0m игрока \033[1m !!\033[0m \n",
                           ScreenX / 2, " ", " ");
                }
        }
    }
