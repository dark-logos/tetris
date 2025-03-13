#include "s21_brickGame.h"

int s21_possibility_of_rotate(Figure *figure, int matrix[ROWS][COLS]){
    int middleX = figure->x[2];
    int middleY = figure->y[2];
    int poss = 0;
    for(int i = middleX - 1; i < middleX +1; i++){
        for(int j = middleY - 1; j < middleY +1; j++){
            if (matrix[i][j] == 1 || i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                poss = 1;
            }
        }
    }
    return poss;
}   
int s21_extra_check_for_rotate_type_0(Figure *figure, int matrix[ROWS][COLS]){
    int middleX = figure->x[2];
    int middleY = figure->y[2];
    int poss = 0;
    if (matrix[middleX][middleY +2] == 1 || matrix[middleX +2][middleY] == 1 || middleY + 2 >= COLS || middleX + 2 >= ROWS) {
        poss = 1;
    }
    return poss;
}
int s21_is_it_end(int matrix[ROWS][COLS]){
    int gameEnd = 0;
    for(int j= 3; j < 7; j++){
        if (matrix[1][j] == 1) {
            gameEnd = 1;
        }
    }
    return gameEnd;
}
int s21_possibility_left__turn(Figure figure, int matrix[ROWS][COLS]){
    int poss = 0;
        for (int i = 0; i < 4; i++) {
            if (figure.y[i] -1 < 0 || matrix[figure.x[i]][figure.y[i] - 1] == 1) {
                poss = 1;
            }
        }
   
    return poss;
}
int s21_possibility_right__turn(Figure figure, int matrix[ROWS][COLS]){
    int poss = 0;
    for (int i = 0; i < 4; i++) {
        if (figure.y[i] +1 >= COLS || matrix[figure.x[i]][figure.y[i] +1] == 1) {
            poss = 1;
        }
    }
    return poss;
}

int s21_possibility_move_dawn(Figure figure, int matrix[ROWS][COLS]){
    int poss = 0;
    for (int i = 0; i < 4; i++) {
        if (figure.x[i] + 1 >= ROWS || matrix[figure.x[i] + 1][figure.y[i]] == 1) {
            poss = 1;
        }
    }
    return poss;
}

void s21_moving_dawn(Figure *figure, int matrix[ROWS][COLS]){
    for (int i = 0; i < 4; i++) {
        figure->x[i]++;
    }
}