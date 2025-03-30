#include "../../tetris/s21_brickGame.h"

const char *text[] = {
    "                                                                     7#P  "
    "                          ",
    "     ~BP.                            ~BP.                          "
    "YB#@@BG:                         ",
    "     !@&.                            7@#.                          "
    "~!5@&7!.                         ",
    "   75G@#.            ^5555:        75G@#.            ~PJ  J555?      :7~  "
    "                          ",
    "   Y@@@#.            !@@@@PY!      5@@@#           7YG@@55@@@@G      ^Y?  "
    "           ~YY5Y.         ",
    " ?JB@@@&YJJY~      ~JJJY@@@@Y    ?JB@@@&YJJY~   .?J#@@@&YYYJB@G    !JP@#  "
    "    :JJJJJJG@&YY.         ",
    " J5#@@@&P55P7    !7B@P .&@@@Y   .Y5#@@@&P55P!   .Y5#@@@B    !5? .7?#@@@B  "
    "  ~75@@P555B@B            ",
    "   Y@@@#.       .#@@@B!7PPPP7      5@@@#           5@@@B.       .5P&@@@B  "
    "  5@@@#    ~PY            ",
    "   Y@@@#.       .B@@@&GP           5@@@#.          P@@@B.          P@@@B  "
    "  Y@@@&7~~~:              ",
    "   Y@@@#. :^^~^ .B@@@P             5@@@#. :^^~^    P@@@B.          P@@@B  "
    "  ?BBBBBB&@5^^            ",
    "   Y@@@#. P@&#P .#@@@P    :^^^:    5@@@#. G@&#5    P@@@B           P@@@B  "
    "    .::  G@@@B            ",
    "   Y@@@&^.P@J . .G&@@P.:::P###P    5@@@#:.G@? .    P@@@#:.       "
    "..P@@@B:.    !@#. P@@@B            ",
    "   Y@@@@&&!..    ..5@&####!....    5@@@@&&~..      5@@@@##^     "
    ".B#&@@@@##^   7@&: G@@@G            ",
    "   .:7@@@@~        .::::::         .:?@@@@~        .:?@#^:       "
    "::P@@@#^:  J&&@@##&@5::            ",
    "     .^^^^.                          .^^^^.          .^:           ::J@B  "
    "  Y@G^^^^^^.              ",
    "                                                                     .~^  "
    "  :~^                    "};

// Определяем формы фигур
const int FIGURES[1][4][4] = {
    // I-фигура
    {{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
};

void draw_figure(int x, int y, int color, int figure_type) {
  attron(COLOR_PAIR(color));

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (FIGURES[figure_type][i][j]) {
        mvprintw(y + i, x + j * 2, "[]");
      }
    }
  }
  attroff(COLOR_PAIR(color));
}
void s21_ui_init() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  start_color();

  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_YELLOW, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(8, COLOR_BLACK, COLOR_WHITE);
}

int draw_blur(int step, int *input) {
  int y;
  unsigned long int x;
  int rows = sizeof(text) / sizeof(text[0]);

  clear();

  for (y = 0; y < rows; y++) {
    move(y, 10);  // Смещение по координатам
    for (x = 0; x < strlen(text[y]); x++) {
      char c = text[y][x];
      if (c == ' ') {
        addch(' ');  // Пустоты оставляем пустыми
      } else {
        int noise_chance = rand() % (BLUR_STEPS - step + 1);
        if (noise_chance > 1) {
          // Шумовой символ для размытия
          char noise_chars[] = {'.', ',', '`', '\'', '-', '~'};
          char noise =
              noise_chars[rand() % (sizeof(noise_chars) / sizeof(char))];
          addch(noise);
        } else {
          addch(c);
        }
        *input = getch();
        if (*input == 'f' || *input == 27) {
          return 1;
        }
      }
    }
  }

  move(rows + 1,
       90);  // Позиция под основным текстом (по вертикали и горизонтали)
  printw("by inzhener");
  refresh();
  usleep(500000);
  return 0;
}

void s21_animate_falling_figure(int *animation_finished) {
  int start_y = 1;
  int start_x = 10;
  int figure_type = 0;
  int color = 2;
  int prev_y = start_y;

  for (int y = start_y; y < FIELD_ROWS - 4; y++) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (FIGURES[figure_type][i][j]) {
          mvprintw(prev_y + i, start_x + j * 2, "  ");
        }
      }
    }

    draw_figure(start_x, y, color, figure_type);

    refresh();       // Обновляем экран
    usleep(200000);  // Задержка 100 мс

    prev_y = y;  // Сохраняем текущую позицию как предыдущую
  }

  // Фигура достигла нижней границы
  *animation_finished = 1;  // Устанавливаем флаг завершения анимации
}

void s21_draw_start_menu(GameState *state) {
  int exit_menu = 0;
  int animation_finished = 0;

  clear();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  timeout(0);
  while (!exit_menu) {
    if (!animation_finished) {
      s21_animate_falling_figure(&animation_finished);
    } else {
      clear();
      int input;
      if (draw_blur(0, &input) == 1) {
        break;
      }
      for (int i = 1; i <= BLUR_STEPS; i++) {
        if (draw_blur(i, &input) == 1) {
          break;
        }
      }

      refresh();
      // input = getch();
      switch (input) {
        case 'f':
          exit_menu = 1;
          break;
        case 27:  // ESC
          state->gameEnd = 1;
          exit_menu = 1;
          break;
        default:
          break;
      }
    }
  }
}
void s21_ui_shutdown() { endwin(); }

void s21_ui_draw_game(GameState *state, int matrix[FIELD_ROWS][FIELD_COLS]) {
  clear();
  mvprintw(0, FIELD_COLS + 12, "SCORE: %d", state->score);
  mvprintw(1, FIELD_COLS + 12, "MAX SCORE: %d", state->maxScore);
  mvprintw(2, FIELD_COLS + 12, "LVL: %d", state->level);
  mvprintw(4, FIELD_COLS + 12, "Next:");
  for (int y = 0; y < FIELD_ROWS; y++) {
    for (int x = 0; x < FIELD_COLS; x++) {
      int cell = matrix[y][x];

      if (cell) {
        attron(COLOR_PAIR(cell % 8 + 1));
        mvprintw(y + 1, x * 2, "[]");
        attroff(COLOR_PAIR(cell % 8 + 1));
      } else {
        mvprintw(y + 1, x * 2, "  ");
      }
    }
  }
  for (int y = 0; y <= FIELD_ROWS; y++) {
    mvprintw(y, FIELD_COLS * 2, "|");
  }
  for (int i = 0; i <= FIELD_ROWS; i++) {
    mvprintw(FIELD_ROWS + 1, i, "-");
  }
  for (int i = 0; i < 4; i++) {
    int next_x = state->next_figure.x[i];
    int next_y = state->next_figure.y[i];
    attron(COLOR_PAIR(state->next_figure.type % 8 + 1));
    mvprintw(3 + next_y, FIELD_COLS + 15 + next_x * 2, "[]");
    attroff(COLOR_PAIR(state->next_figure.type % 8 + 1));
  }
  int top_start_y = 5;
  int top_start_x = FIELD_COLS + 29;
  mvprintw(top_start_y - 4, top_start_x,
           "      .     .    .  +   . .  *  .        . / |");
  mvprintw(top_start_y - 3, top_start_x, "           . + .  .  .  .. +  .");
  mvprintw(top_start_y - 2, top_start_x,
           ".  .  .  .  *   .  *  . +..  .            *");
  mvprintw(top_start_y - 1, top_start_x,
           " .  .   . .   .   .   . .  +   .    .            +");
  mvprintw(top_start_y, top_start_x,
           "             +   .                .   . .     .  .");
  mvprintw(top_start_y + 1, top_start_x,
           "               .                    .       .     *");
  mvprintw(top_start_y + 2, top_start_x,
           "       *                        . . . .  .   .  + .");
  mvprintw(top_start_y + 3, top_start_x,
           "        \"You Are Here\"            .   .  +  . . .");
  mvprintw(top_start_y + 4, top_start_x,
           ".             |             .  .   .    .    . .");
  mvprintw(top_start_y + 5, top_start_x,
           "              |           .     .     . +.    +  .");
  mvprintw(top_start_y + 6, top_start_x,
           "             \\|/            .       .   . .");
  mvprintw(top_start_y + 7, top_start_x,
           "    . .       V          .    * . . .  .  +   .");
  mvprintw(top_start_y + 8, top_start_x,
           "       +      .           .   .      +");
  mvprintw(top_start_y + 9, top_start_x,
           "                        .       . +  .+. .");
  mvprintw(top_start_y + 10, top_start_x,
           "                     .     . + .  . .     .      .");
  mvprintw(top_start_y + 11, top_start_x,
           "       .      .    .     . .   . . .         ! /");
  mvprintw(top_start_y + 12, top_start_x,
           "   *             .    . .  +    .  .       - O -");
  mvprintw(top_start_y + 13, top_start_x,
           "      .     .    .  +   . .  *  .        . / |");
  mvprintw(top_start_y + 14, top_start_x, "           . + .  .  .  .. +  .");
  mvprintw(top_start_y + 15, top_start_x,
           ".  .  .  .  *   .  *  . +..  .            *");
  mvprintw(top_start_y + 16, top_start_x,
           " .  .   . .   .   .   . .  +   .    .            +");
  s21_draw_galaxy(top_start_y, top_start_x);
}
void s21_draw_galaxy(int top_start_y, int top_start_x) {
  int right_start_y =
      top_start_y - 5;  // Начинаем с той же строки, что и первый арт
  int right_start_x = top_start_x + 54;  // Смещаем вправо от первого арта

  mvprintw(right_start_y, right_start_x,
           "   : | ||  :       :  |  |+|: | : : :|   .                      .");
  mvprintw(
      right_start_y + 1, right_start_x,
      ": | :|  ||  |:  :      |  | :| : | : |:   |  .                    :");
  mvprintw(
      right_start_y + 2, right_start_x,
      " .' ':  ||  |:  |  '        || | : | |: : |   .             .   :.");
  mvprintw(
      right_start_y + 3, right_start_x,
      "        '  ||  |  ' |   *     : | | :| |*|  :   :               :|");
  mvprintw(
      right_start_y + 4, right_start_x,
      "     *         |  : :  |  .       ' :| | :| . : :         *   :.||");
  mvprintw(
      right_start_y + 5, right_start_x,
      "     .            | |  |  : .:|        | || | : |: |          | ||");
  mvprintw(
      right_start_y + 6, right_start_x,
      "      '  .         +   |  :  .: .         '| | : :| :    .   |:| ||");
  mvprintw(right_start_y + 7, right_start_x,
           " .                 .     *|  || :           | | :| | :      |:| |");
  mvprintw(right_start_y + 8, right_start_x,
           " .        .          .        || |.: *          | || : :     :|||");
  mvprintw(right_start_y + 9, right_start_x,
           ".            .   . *    .   .   |||.  +        + '| |||  .  ||");
  mvprintw(right_start_y + 10, right_start_x,
           "           *              .     +:|!             . ||||  :.||");
  mvprintw(right_start_y + 11, right_start_x,
           " +              .                ..!|*          . | :||+ |||");
  mvprintw(right_start_y + 12, right_start_x,
           "                       +      : |||        .| :| | | |.| ||     .");
  mvprintw(right_start_y + 13, right_start_x,
           "     +   '               +  :|| |     :.+. || || | |:|| ");
  mvprintw(right_start_y + 14, right_start_x,
           "                    .      .|| .    ..|| | |: ' | | |  +");
  mvprintw(right_start_y + 15, right_start_x,
           "  +++                      ||        !|!:        :| |");
  mvprintw(
      right_start_y + 16, right_start_x,
      "      +         .      .    | .      |||.:      .||    .      .    ");
  mvprintw(right_start_y + 17, right_start_x,
           "  '                           |.   .  :|||   + ||'     ");
  mvprintw(right_start_y + 18, right_start_x,
           "+      *                         '       '|.    :");
  mvprintw(right_start_y + 19, right_start_x,
           "      .     .    .  +   . .  *  .        . / |");
  mvprintw(right_start_y + 20, right_start_x,
           ".  .  .  .  *   .  *  . +..  .            *");
  mvprintw(right_start_y + 21, right_start_x,
           " .  .   . .   .   .   . .  +   .    .            +");
  refresh();
}
void s21_ui_draw_game_over() {
  clear();
  mvprintw(FIELD_ROWS / 2, FIELD_COLS, "Maybe next time... my warrior");
  refresh();
}