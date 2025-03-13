#include "s21_brickGame.h"

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



int main() {
    Figure figure;
    int matrix[ROWS][COLS] = {0}, nextFigure = 0, gameEnd = 0, speed = 600000,type = 0;
    while(!s21_is_it_end(matrix)){
        createFigure(&figure, type);
        if(type < 6){
            type++;
        } else {
            type = 0;
        }
        nextFigure = 0;
        while (!nextFigure) {
            s21_separating_figure_from_matrix(figure, matrix, 0);
            s21_input_check(&figure, matrix,&speed);
            if(s21_possibility_move_dawn(figure, matrix) == 0){
                s21_moving_dawn(&figure, matrix);
            } else {
                nextFigure = 1;
            }
            s21_separating_figure_from_matrix(figure, matrix, 1);
            usleep(speed);
            if(nextFigure == 1){
               int rows_to_clear[ROWS];
                int cleared_count = s21_find_full_rows(rows_to_clear, matrix);
                
                if (cleared_count > 0) {
                    s21_zeroing_out_rows(rows_to_clear, cleared_count, matrix);
                    s21_falling_blocks(rows_to_clear, cleared_count, matrix);
                    //score += 100 * cleared_count * cleared_count;
                }
            }
            speed = DEFAULT_SPEED;
            printMatrix(matrix);
        }
    }    
    return 0;
}
