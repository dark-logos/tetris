#include "s21_brickGame.h"

void s21_save_maxScore(GameState *state) {
  FILE *file = fopen("maxScore.txt", "w");
  if (file) {
    fprintf(file, "%d", state->maxScore);
    fclose(file);
  }
}

void s21_load_maxScore(GameState *state) {
  FILE *file = fopen("maxScore.txt", "r");
  if (file) {
    fscanf(file, "%d", &state->maxScore);
    fclose(file);
  } else {
    state->maxScore = 0;
  }
}
void s21_update_maxScore(GameState *state) {
  if (state->score > state->maxScore) {
    state->maxScore = state->score;
    s21_save_maxScore(state);
  }
}

int s21_find_full_rows(int rows_to_clear[FIELD_ROWS],
                       int matrix[FIELD_ROWS][FIELD_COLS]) {
  int count = 0;
  for (int i = FIELD_ROWS - 1; i >= 0; i--) {
    int is_full = 1;

    for (int j = 0; j < FIELD_COLS; j++) {
      if (matrix[i][j] == 0) {
        is_full = 0;
      }
    }

    if (is_full) {
      rows_to_clear[count++] = i;
    }
  }

  return count;
}

void s21_zeroing_out_rows(int rows_to_clear[], int count,
                          int matrix[FIELD_ROWS][FIELD_COLS]) {
  for (int i = 0; i < count; i++) {
    int row = rows_to_clear[i];
    for (int j = 0; j < FIELD_COLS; j++) {
      matrix[row][j] = 0;
    }
  }
}

void s21_falling_blocks(int rows_to_clear[], int count,
                        int matrix[FIELD_ROWS][FIELD_COLS]) {
  int write_ptr = FIELD_ROWS - 1;  // Указатель записи

  // Строим новую матрицу снизу вверх
  for (int read_ptr = FIELD_ROWS - 1; read_ptr >= 0; read_ptr--) {
    // Пропускаем удаленные строки
    int is_cleared = 0;
    for (int i = 0; i < count; i++) {
      if (read_ptr == rows_to_clear[i]) {
        is_cleared = 1;
        break;
      }
    }

    if (!is_cleared) {
      // Копируем строку
      for (int j = 0; j < FIELD_COLS; j++) {
        matrix[write_ptr][j] = matrix[read_ptr][j];
      }
      write_ptr--;
    }
  }

  while (write_ptr >= 0) {
    for (int j = 0; j < FIELD_COLS; j++) {
      matrix[write_ptr][j] = 0;
    }
    write_ptr--;
  }
}