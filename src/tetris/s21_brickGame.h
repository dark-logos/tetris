#ifndef S21_BRICKGAME_H
#define S21_BRICKGAME_H

#define FIELD_COLS 10
#define FIELD_ROWS 20
#define DEFAULT_SPEED 600

typedef struct {
    int x[4];
    int y[4];
    int type;
    int rotate;
} Figure;

typedef struct {                             
    Figure next_figure;                    
    int score;   
    int speed;
    int gameEnd;                            
    int level;  
    int maxScore;                               
} GameState;

// figure move and rotation
int s21_createFigure(Figure *figure, int type);
int s21_rotate_figure(Figure *figure, int matrix[FIELD_ROWS][FIELD_COLS]);
int s21_possibility_of_rotate(Figure *figure, int matrix[FIELD_ROWS][FIELD_COLS]);
int s21_possibility_right__turn(Figure figure, int matrix[FIELD_ROWS][FIELD_COLS]);
int s21_possibility_left__turn(Figure figure, int matrix[FIELD_ROWS][FIELD_COLS]);
int s21_possibility_move_dawn(Figure figure, int matrix[FIELD_ROWS][FIELD_COLS]);
void s21_moving_dawn(Figure *figure);
void s21_separating_figure_from_matrix(Figure figure, int matrix[FIELD_ROWS][FIELD_COLS], int isFigureNowField);

void s21_rotate_figure_type_0(Figure *figure);
void s21_rotate_figure_type_1(Figure *figure);
void s21_rotate_figure_type_2(Figure *figure);
void s21_rotate_figure_type_3(Figure *figure);
void s21_rotate_figure_type_4(Figure *figure);
void s21_rotate_figure_type_5(Figure *figure);
void s21_rotate_figure_type_6(Figure *figure);

// Работа с игровым полем и его состоянием
int s21_is_it_end(int matrix[FIELD_ROWS][FIELD_COLS]);
int s21_find_full_rows(int rows_to_clear[FIELD_ROWS], int matrix[FIELD_ROWS][FIELD_COLS]);
void s21_zeroing_out_rows(int rows_to_clear[], int count, int matrix[FIELD_ROWS][FIELD_COLS]);
void s21_falling_blocks(int rows_to_clear[], int count, int matrix[FIELD_ROWS][FIELD_COLS]);


int s21_extra_check_for_rotate_type_0(Figure *figure, int matrix[FIELD_ROWS][FIELD_COLS]);

void s21_load_maxScore(GameState *state);
void s21_save_maxScore(GameState *state);
void s21_update_maxScore(GameState *state);

void s21_game_cycle(GameState *state);

// input processing
int kbhit();
int s21_input_check(Figure *figure, int matrix[FIELD_ROWS][FIELD_COLS], int *speed);



#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <ncurses.h>
#include <check.h>
#include "../gui/cli/s21_graphics.h"

#endif
