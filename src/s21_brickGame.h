#ifndef S21_BRICKGAME_H
#define S21_BRICKGAME_H

#include <unistd.h> 

#define ROWS 20
#define COLS 10
#define DEFAULT_SPEED 600000

typedef struct {
    int x[4];
    int y[4];
    int type;
    int rotate;
} Figure;

typedef struct {
    int matrix[ROWS][COLS];   // Игровое поле: 0 - пусто, >0 - цвет/тип блока
    Figure figure;                  // Текущая падающая фигура
    int current_x;                          // Позиция фигуры по X
    int current_y;                          // Позиция фигуры по Y
    Figure next_figure;                     // Следующая фигура
    int score;                              // Очки игрока
    int lines_cleared;                      // Очищенные линии
    int level;                              // Уровень сложности (скорость падения)
    int game_over;                          // Флаг конца игры
    int paused;                             // Флаг паузы
} GameState;

int s21_rotate_figure(Figure *figure, int matrix[ROWS][COLS]);
int createFigure(Figure *figure, int type);
void clearFullRows(int matrix[ROWS][COLS]);
int s21_possibility_of_rotate(Figure *figure, int matrix[ROWS][COLS]);
int s21_extra_check_for_rotate_type_0(Figure *figure, int matrix[ROWS][COLS]);
int s21_is_it_end(int matrix[ROWS][COLS]);
int s21_possibility_right__turn(Figure figure, int matrix[ROWS][COLS]);
int s21_possibility_left__turn(Figure figure, int matrix[ROWS][COLS]);
void s21_input_check(Figure *figure, int matrix[ROWS][COLS], int *speed);
int s21_possibility_move_dawn(Figure figure, int matrix[ROWS][COLS]);
void s21_moving_dawn(Figure *figure, int matrix[ROWS][COLS]);

void s21_falling_blocks(int rows_to_clear[], int count, int matrix[ROWS][COLS]);
int s21_find_full_rows(int rows_to_clear[ROWS], int matrix[ROWS][COLS]);
void s21_zeroing_out_rows(int rows_to_clear[], int count, int matrix[ROWS][COLS]);
// int s21_find_full_rows(int rowToDelete[ROWS], int matrix[ROWS][COLS]);
// void s21_zeroing_out_raws(int rowToDelete[ROWS], int matrix[ROWS][COLS]);
// void s21_falling_because_zeroing(int rowToDelete[ROWS], int matrix[ROWS][COLS]);
void s21_separating_figure_from_matrix(Figure figure, int matrix[ROWS][COLS], int isFigureNowField);
int kbhit();

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#endif