#include "s21_brickGame.h"

int kbhit() {
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

int s21_input_check(Figure *figure, int matrix[FIELD_ROWS][FIELD_COLS],
                    int *speed) {
  char key;
  int gameEnd = 0;
  if (kbhit()) key = getchar();
  switch (key) {
    case 'w':
      s21_rotate_figure(figure, matrix);
      break;
    case 'a':
      if (s21_possibility_left__turn(*figure, matrix) == 0) {
        for (int i = 0; i < 4; i++) {
          figure->y[i]--;
        }
      }
      break;
    case 's':
      *speed /= 2;
      break;
    case 'd':
      if (s21_possibility_right__turn(*figure, matrix) == 0) {
        for (int i = 0; i < 4; i++) {
          figure->y[i]++;
        }
      }
      break;
    case 'q':
      key = 'o';
      while (key != 'q') {
        if (kbhit()) {
          key = getchar();
        }
      }
      break;
    case 27:
      gameEnd = 1;
      break;
  }
  return gameEnd;
}
