#include "s21_brickGame.h"

void s21_game_cycle(GameState *state) {
  state->speed = 500;
  s21_load_maxScore(state);
  Figure figure;
  int matrix[FIELD_ROWS][FIELD_COLS] = {0}, nextFigure = 0, type = 0;
  while (!(state->gameEnd)) {
    s21_createFigure(&figure, type);
    s21_createFigure(&state->next_figure, (type + 1) % 7);
    type = (type + 1) % 7;
    nextFigure = 0;
    while (!nextFigure) {
      s21_separating_figure_from_matrix(figure, matrix, 0);

      if (s21_input_check(&figure, matrix, &state->speed) == 1) {
        state->gameEnd = 1;
        nextFigure = 2;  // выход из цикла + игнорирование функций для поиска
                         // заполненных строк
      }
      flushinp();  // очищает буффер
      if (s21_possibility_move_dawn(figure, matrix) == 0) {
        s21_moving_dawn(&figure);
      } else {
        nextFigure = 1;
      }
      s21_separating_figure_from_matrix(figure, matrix, 1);
      if (nextFigure == 1) {
        int rows_to_clear[FIELD_ROWS];
        int cleared_count = s21_find_full_rows(rows_to_clear, matrix);

        if (cleared_count > 0) {
          s21_zeroing_out_rows(rows_to_clear, cleared_count, matrix);
          s21_falling_blocks(rows_to_clear, cleared_count, matrix);
          state->score += 100 * cleared_count * cleared_count;
          state->level = state->score / 600;
          state->level = (state->level > 10) ? 10 : state->level;
          s21_update_maxScore(state);
        }
      }
      s21_ui_draw_game(state, matrix);
      napms(state->speed);
      state->speed = DEFAULT_SPEED - state->level * 20;
    }
    state->gameEnd += s21_is_it_end(matrix);
  }
}
