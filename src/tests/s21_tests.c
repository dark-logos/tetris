#include "../tetris/s21_brickGame.h"  // Подключаем файл с функциями

// Функция для инициализации ncurses в тестах
void setup() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  start_color();
}

// Функция для закрытия ncurses после тестов
void teardown() { endwin(); }

// Тесты для разных типов фигур

START_TEST(test_rotate_figure_type_0) {
  Figure figure = {
      .x = {5, 5, 5, 5}, .y = {5, 5, 5, 5}, .rotate = 0, .type = 0};

  s21_rotate_figure_type_0(&figure);

  ck_assert_int_eq(figure.x[0], 4);
  ck_assert_int_eq(figure.x[1], 5);
  ck_assert_int_eq(figure.x[2], 6);
  ck_assert_int_eq(figure.x[3], 7);

  ck_assert_int_eq(figure.y[0], 5);
  ck_assert_int_eq(figure.y[1], 5);
  ck_assert_int_eq(figure.y[2], 5);
  ck_assert_int_eq(figure.y[3], 5);

  ck_assert_int_eq(figure.rotate, 1);
  s21_rotate_figure_type_0(&figure);
  ck_assert_int_eq(figure.x[0], 6);
  ck_assert_int_eq(figure.x[1], 6);
  ck_assert_int_eq(figure.x[2], 6);
  ck_assert_int_eq(figure.x[3], 6);

  ck_assert_int_eq(figure.y[0], 4);
  ck_assert_int_eq(figure.y[1], 5);
  ck_assert_int_eq(figure.y[2], 6);
  ck_assert_int_eq(figure.y[3], 7);
}
END_TEST

START_TEST(test_s21_extra_check_for_rotate_type_0) {
  Figure figure = {
      .x = {1, 2, 3, 4}, .y = {20, 20, 20, 20}, .rotate = 0, .type = 0};
  int matrix[FIELD_ROWS][FIELD_COLS] = {0};
  int result = s21_extra_check_for_rotate_type_0(&figure, matrix);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_rotate_figure_type_1) {
  Figure figure = {
      .x = {5, 5, 5, 5}, .y = {5, 5, 5, 5}, .rotate = 0, .type = 1};

  s21_rotate_figure_type_1(&figure);
  ck_assert_int_eq(figure.x[0], 4);  // middleX - 1
  ck_assert_int_eq(figure.x[1], 5);
  ck_assert_int_eq(figure.x[2], 6);  // middleX + 1
  ck_assert_int_eq(figure.x[3], 4);  // middleX - 1

  ck_assert_int_eq(figure.y[0], 5);
  ck_assert_int_eq(figure.y[1], 5);
  ck_assert_int_eq(figure.y[2], 5);
  ck_assert_int_eq(figure.y[3], 6);  // middleY + 1

  ck_assert_int_eq(figure.rotate, 1);

  s21_rotate_figure_type_1(&figure);
  ck_assert_int_eq(figure.x[0], 6);
  ck_assert_int_eq(figure.x[1], 6);
  ck_assert_int_eq(figure.x[2], 6);
  ck_assert_int_eq(figure.x[3], 7);

  ck_assert_int_eq(figure.y[0], 4);
  ck_assert_int_eq(figure.y[1], 5);
  ck_assert_int_eq(figure.y[2], 6);
  ck_assert_int_eq(figure.y[3], 6);

  ck_assert_int_eq(figure.rotate, 2);

  s21_rotate_figure_type_1(&figure);
  ck_assert_int_eq(figure.x[0], 7);
  ck_assert_int_eq(figure.x[1], 6);
  ck_assert_int_eq(figure.x[2], 5);
  ck_assert_int_eq(figure.x[3], 7);

  ck_assert_int_eq(figure.y[0], 6);
  ck_assert_int_eq(figure.y[1], 6);
  ck_assert_int_eq(figure.y[2], 6);
  ck_assert_int_eq(figure.y[3], 5);

  ck_assert_int_eq(figure.rotate, 3);

  s21_rotate_figure_type_1(&figure);

  ck_assert_int_eq(figure.x[0], 5);
  ck_assert_int_eq(figure.x[1], 5);
  ck_assert_int_eq(figure.x[2], 5);
  ck_assert_int_eq(figure.x[3], 4);

  ck_assert_int_eq(figure.y[0], 5);
  ck_assert_int_eq(figure.y[1], 6);
  ck_assert_int_eq(figure.y[2], 7);
  ck_assert_int_eq(figure.y[3], 5);

  ck_assert_int_eq(figure.rotate, 0);
}
END_TEST

START_TEST(test_rotate_figure_type_2) {
  Figure figure = {
      .x = {5, 5, 6, 6}, .y = {5, 6, 6, 7}, .rotate = 0, .type = 2};

  s21_rotate_figure_type_2(&figure);
  ck_assert_int_eq(figure.rotate, 1);

  ck_assert_int_eq(figure.x[0], 7);
  ck_assert_int_eq(figure.y[0], 6);

  ck_assert_int_eq(figure.x[1], 6);
  ck_assert_int_eq(figure.y[1], 6);

  ck_assert_int_eq(figure.x[2], 6);
  ck_assert_int_eq(figure.y[2], 5);

  ck_assert_int_eq(figure.x[3], 5);
  ck_assert_int_eq(figure.y[3], 5);

  s21_rotate_figure_type_2(&figure);
  ck_assert_int_eq(figure.rotate, 2);

  ck_assert_int_eq(figure.x[0], 6);
  ck_assert_int_eq(figure.y[0], 7);

  ck_assert_int_eq(figure.x[1], 6);
  ck_assert_int_eq(figure.y[1], 6);

  ck_assert_int_eq(figure.x[2], 7);
  ck_assert_int_eq(figure.y[2], 6);

  ck_assert_int_eq(figure.x[3], 7);
  ck_assert_int_eq(figure.y[3], 5);

  s21_rotate_figure_type_2(&figure);
  ck_assert_int_eq(figure.rotate, 3);

  ck_assert_int_eq(figure.x[0], 5);
  ck_assert_int_eq(figure.y[0], 6);

  ck_assert_int_eq(figure.x[1], 6);
  ck_assert_int_eq(figure.y[1], 6);

  ck_assert_int_eq(figure.x[2], 6);
  ck_assert_int_eq(figure.y[2], 7);

  ck_assert_int_eq(figure.x[3], 7);
  ck_assert_int_eq(figure.y[3], 7);

  s21_rotate_figure_type_2(&figure);
  ck_assert_int_eq(figure.rotate, 0);

  ck_assert_int_eq(figure.x[0], 6);
  ck_assert_int_eq(figure.y[0], 5);

  ck_assert_int_eq(figure.x[1], 6);
  ck_assert_int_eq(figure.y[1], 6);

  ck_assert_int_eq(figure.x[2], 5);
  ck_assert_int_eq(figure.y[2], 6);

  ck_assert_int_eq(figure.x[3], 5);
  ck_assert_int_eq(figure.y[3], 7);
}
END_TEST

START_TEST(test_rotate_figure_type_4) {
  Figure figure = {
      .x = {1, 2, 3, 4}, .y = {5, 5, 5, 6}, .rotate = 0, .type = 4};

  s21_rotate_figure_type_4(&figure);

  ck_assert_int_eq(figure.x[0], 0);
  ck_assert_int_eq(figure.x[1], 1);
  ck_assert_int_eq(figure.x[2], 2);
  ck_assert_int_eq(figure.x[3], 3);

  ck_assert_int_eq(figure.y[0], 4);
  ck_assert_int_eq(figure.y[1], 5);
  ck_assert_int_eq(figure.y[2], 6);
  ck_assert_int_eq(figure.y[3], 6);

  ck_assert_int_eq(figure.rotate, 1);
}
END_TEST

START_TEST(test_rotate_figure_type_5) {
  Figure figure = {
      .x = {1, 2, 3, 4}, .y = {5, 5, 5, 6}, .rotate = 0, .type = 5};

  s21_rotate_figure_type_5(&figure);

  ck_assert_int_eq(figure.x[0], 0);
  ck_assert_int_eq(figure.x[1], 1);
  ck_assert_int_eq(figure.x[2], 2);
  ck_assert_int_eq(figure.x[3], 3);

  ck_assert_int_eq(figure.y[0], 5);
  ck_assert_int_eq(figure.y[1], 5);
  ck_assert_int_eq(figure.y[2], 5);
  ck_assert_int_eq(figure.y[3], 6);

  ck_assert_int_eq(figure.rotate, 1);
}
END_TEST

START_TEST(test_rotate_figure_type_6) {
  Figure figure = {
      .x = {5, 5, 5, 5}, .y = {5, 5, 5, 5}, .rotate = 0, .type = 6};

  printf("Before rotation:\n");
  for (int i = 0; i < 4; i++) {
    printf("x[%d] = %d, y[%d] = %d\n", i, figure.x[i], i, figure.y[i]);
  }

  s21_rotate_figure_type_6(&figure);

  printf("After rotation:\n");
  for (int i = 0; i < 4; i++) {
    printf("x[%d] = %d, y[%d] = %d\n", i, figure.x[i], i, figure.y[i]);
  }

  ck_assert_int_eq(figure.x[0], 4);
  ck_assert_int_eq(figure.x[1], 5);
  ck_assert_int_eq(figure.x[2], 6);
  ck_assert_int_eq(figure.x[3], 7);

  ck_assert_int_eq(figure.y[0], 5);
  ck_assert_int_eq(figure.y[1], 5);
  ck_assert_int_eq(figure.y[2], 5);
  ck_assert_int_eq(figure.y[3], 5);

  ck_assert_int_eq(figure.rotate, 1);

  s21_rotate_figure_type_6(&figure);
  // Повторный вывод для проверки
  printf("After second rotation:\n");
  for (int i = 0; i < 4; i++) {
    printf("x[%d] = %d, y[%d] = %d\n", i, figure.x[i], i, figure.y[i]);
  }

  ck_assert_int_eq(figure.x[0], 5);
  ck_assert_int_eq(figure.x[1], 5);
  ck_assert_int_eq(figure.x[2], 5);
  ck_assert_int_eq(figure.x[3], 5);

  ck_assert_int_eq(figure.y[0], 4);
  ck_assert_int_eq(figure.y[1], 5);
  ck_assert_int_eq(figure.y[2], 6);
  ck_assert_int_eq(figure.y[3], 7);

  ck_assert_int_eq(figure.rotate, 2);

  // // Rotate 2 ➜ 3
  // s21_rotate_figure_type_6(&figure);
  // ck_assert_int_eq(figure.rotate, 3);

  // ck_assert_int_eq(figure.x[0], 4);
  // ck_assert_int_eq(figure.y[0], 6);

  // ck_assert_int_eq(figure.x[1], 5);
  // ck_assert_int_eq(figure.y[1], 6);

  // ck_assert_int_eq(figure.x[2], 6);
  // ck_assert_int_eq(figure.y[2], 6);

  // ck_assert_int_eq(figure.x[3], 6);
  // ck_assert_int_eq(figure.y[3], 7);

  // // Rotate 3 ➜ 0 (вернуться в исходное состояние)
  // s21_rotate_figure_type_6(&figure);
  // ck_assert_int_eq(figure.rotate, 0);

  // ck_assert_int_eq(figure.x[0], 5);
  // ck_assert_int_eq(figure.y[0], 5);

  // ck_assert_int_eq(figure.x[1], 5);
  // ck_assert_int_eq(figure.y[1], 6);

  // ck_assert_int_eq(figure.x[2], 5);
  // ck_assert_int_eq(figure.y[2], 7);

  // ck_assert_int_eq(figure.x[3], 6);
  // ck_assert_int_eq(figure.y[3], 7);
}
END_TEST

START_TEST(test_rotate_figure) {
  int matrix[FIELD_ROWS][FIELD_COLS] = {0};

  Figure figure = {
      .x = {1, 2, 3, 4}, .y = {5, 5, 5, 5}, .rotate = 0, .type = 0};

  s21_rotate_figure(&figure, matrix);

  ck_assert_int_eq(figure.x[0], 0);
  ck_assert_int_eq(figure.x[1], 1);
  ck_assert_int_eq(figure.x[2], 2);
  ck_assert_int_eq(figure.x[3], 3);

  ck_assert_int_eq(figure.y[0], 5);
  ck_assert_int_eq(figure.y[1], 5);
  ck_assert_int_eq(figure.y[2], 5);
  ck_assert_int_eq(figure.y[3], 5);
}
END_TEST

START_TEST(test_load_maxScore) {
  GameState state;
  state.maxScore = 100;

  s21_save_maxScore(&state);

  state.maxScore = 0;
  s21_load_maxScore(&state);

  ck_assert_int_eq(state.maxScore, 100);
}
END_TEST

START_TEST(test_update_maxScore) {
  GameState state;
  state.score = 150;
  state.maxScore = 100;

  s21_update_maxScore(&state);

  ck_assert_int_eq(state.maxScore, 150);
}
END_TEST

START_TEST(test_zeroing_out_rows) {
  int matrix[FIELD_ROWS][FIELD_COLS] = {{0}};
  int rows_to_clear[FIELD_ROWS] = {2};
  matrix[17][1] = 1;
  for (int i = 0; i < FIELD_COLS; i++) {
    matrix[18][i] = 1;
  }
  int count = s21_find_full_rows(rows_to_clear, matrix);
  ck_assert_int_eq(count, 1);
  // Очищаем строку
  s21_zeroing_out_rows(rows_to_clear, 1, matrix);

  // Проверка, что строка очищена
  for (int i = 0; i < FIELD_COLS; i++) {
    ck_assert_int_eq(matrix[18][i], 0);
  }
  s21_falling_blocks(rows_to_clear, 1, matrix);
  ck_assert_int_eq(matrix[18][1], 1);
}
END_TEST

START_TEST(test_s21_game_cycle) {
  GameState state = {{{0}, {0}, 0, 0}, 300, 100, 0, 0, 300};

  ck_assert_int_eq(state.gameEnd, 1);
  ck_assert_int_eq(state.speed, 500);
}
END_TEST

START_TEST(test_create_figure) {
  Figure figure;
  s21_createFigure(&figure, 0);

  // Проверка, что фигура типа 0 была создана корректно
  ck_assert_int_eq(figure.x[0], 0);
  ck_assert_int_eq(figure.y[0], 3);

  s21_createFigure(&figure, 1);

  // Проверка, что фигура типа 1 была создана корректно
  ck_assert_int_eq(figure.x[0], -1);
  ck_assert_int_eq(figure.y[0], 3);

  s21_createFigure(&figure, 2);

  ck_assert_int_eq(figure.x[0], 0);
  ck_assert_int_eq(figure.y[0], 4);

  s21_createFigure(&figure, 3);

  ck_assert_int_eq(figure.x[0], -1);
  ck_assert_int_eq(figure.y[0], 4);

  s21_createFigure(&figure, 4);

  ck_assert_int_eq(figure.x[0], 0);
  ck_assert_int_eq(figure.y[0], 3);

  s21_createFigure(&figure, 5);

  ck_assert_int_eq(figure.x[0], 0);
  ck_assert_int_eq(figure.y[0], 3);

  s21_createFigure(&figure, 6);

  ck_assert_int_eq(figure.x[0], -1);
  ck_assert_int_eq(figure.y[0], 3);
}
END_TEST

START_TEST(test_separating_figure_from_matrix) {
  int matrix[FIELD_ROWS][FIELD_COLS] = {{0}};
  Figure figure = {.x = {1, 1, 1, 1}, .y = {3, 4, 5, 6}};

  // Разделим фигуру от матрицы
  s21_separating_figure_from_matrix(figure, matrix, 1);

  // Проверка, что элементы матрицы изменились
  ck_assert_int_eq(matrix[1][3], 1);
  ck_assert_int_eq(matrix[1][4], 1);
  ck_assert_int_eq(matrix[1][5], 1);
  ck_assert_int_eq(matrix[1][6], 1);
}
END_TEST

START_TEST(test_possibility_of_rotate) {
  Figure figure = {.x = {1, 1, 1, 1}, .y = {3, 4, 5, 6}};
  int matrix[FIELD_ROWS][FIELD_COLS] = {{0}};

  // Проверяем, что поворот возможен
  int result = s21_possibility_of_rotate(&figure, matrix);
  ck_assert_int_eq(result, 0);  // Ожидаем 0, что поворот возможен
}
END_TEST

START_TEST(test_possibility_left_turn) {
  Figure figure = {.x = {1, 1, 1, 1}, .y = {3, 4, 5, 6}};
  int matrix[FIELD_ROWS][FIELD_COLS] = {{0}};

  // Проверка, что поворот влево возможен
  int result = s21_possibility_left__turn(figure, matrix);
  ck_assert_int_eq(result, 0);  // Ожидаем 0, что поворот влево возможен
  result = s21_possibility_right__turn(figure, matrix);
  ck_assert_int_eq(result, 0);  // Ожидаем 0, что поворот влево возможен
  result = s21_possibility_move_dawn(figure, matrix);
  ck_assert_int_eq(result, 0);  // Ожидаем 0, что поворот влево возможен
                                // s21_moving_dawn(&figure);
                                // ck_assert_int_eq(matrix[2][3], 1);
                                // ck_assert_int_eq(matrix[2][4], 1);
                                // ck_assert_int_eq(matrix[2][5], 1);
                                // ck_assert_int_eq(matrix[2][6], 1);
}
END_TEST

START_TEST(test_is_it_end) {
  int matrix[FIELD_ROWS][FIELD_COLS] = {{0}};

  // Размещение блока в строке, чтобы игра завершилась
  matrix[1][3] = 1;
  matrix[1][4] = 1;
  matrix[1][5] = 1;
  matrix[1][6] = 1;

  // Проверка, что игра закончена
  int result = s21_is_it_end(matrix);
  ck_assert_int_eq(result, 1);  // Ожидаем, что игра закончена
}
END_TEST

// Главная функция для запуска тестов
int main(void) {
  // Инициализация
  setup();

  // Создание набора тестов
  Suite *s = suite_create("Tetris Tests");
  TCase *tc_core = tcase_create("Core");

  // Добавление тестов в набор
  tcase_add_test(tc_core, test_rotate_figure_type_0);
  tcase_add_test(tc_core, test_rotate_figure_type_1);
  tcase_add_test(tc_core, test_rotate_figure_type_2);
  tcase_add_test(tc_core, test_rotate_figure_type_4);
  tcase_add_test(tc_core, test_rotate_figure_type_5);
  tcase_add_test(tc_core, test_rotate_figure_type_6);
  tcase_add_test(tc_core, test_rotate_figure);
  tcase_add_test(tc_core, test_load_maxScore);
  tcase_add_test(tc_core, test_update_maxScore);
  tcase_add_test(tc_core, test_zeroing_out_rows);
  tcase_add_test(tc_core, test_s21_extra_check_for_rotate_type_0);
  tcase_add_test(tc_core, test_create_figure);
  tcase_add_test(tc_core, test_separating_figure_from_matrix);
  tcase_add_test(tc_core, test_possibility_of_rotate);
  tcase_add_test(tc_core, test_possibility_left_turn);
  tcase_add_test(tc_core, test_is_it_end);
  tcase_add_test(tc_core, test_s21_game_cycle);
  // Добавление набора тестов в общий набор
  suite_add_tcase(s, tc_core);

  // Запуск тестов
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);

  // Очистка после тестов
  srunner_free(sr);
  teardown();

  return 0;
}
