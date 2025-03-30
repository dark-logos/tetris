#ifndef S21_GRAPHICS_H
#define S21_GRAPHICS_H

#include "../../tetris/s21_brickGame.h"
#include <ncurses.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <math.h> 
#define BLUR_STEPS 10
#define DELAY 50000 

// Инициализация и завершение ncurses
void s21_ui_init();
void s21_ui_shutdown();

// Основные функции отрисовки
void s21_draw_start_menu(GameState *state);
void draw_figure(int x, int y, int color, int figure_type);
void s21_ui_draw_game(GameState* state, int matrix[FIELD_ROWS][FIELD_COLS]);
void s21_ui_draw_pause();
void s21_ui_draw_game_over();
void s21_ui_draw_next_figure(const Figure* next);
void s21_ui_draw_score(int score);
void draw_retro_text();
void s21_animate_falling_figure(int *animation_finished);
void s21_draw_earth_galaxy();
void s21_draw_galaxy(int top_start_y, int top_start_x);
void fade_in_effect();
void draw_typing_effect();
int draw_blur(int step, int * input);
void draw_text_with_effects();
#endif