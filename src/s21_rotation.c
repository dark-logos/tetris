#include "s21_brickGame.h"
void s21_rotate_figure_type_0(Figure *figure){
     if(figure->rotate == 0){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        //тут нужно просто дать проверку на middle x + 2
        *figure = (Figure){ .x = {middleX - 1, middleX, middleX + 1, middleX + 2}, .y = {middleY, middleY, middleY, middleY} };
        figure->rotate = 1;
    } else if (figure->rotate == 1){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        //
        *figure = (Figure){ .x = {middleX, middleX, middleX, middleX}, .y = {middleY -1, middleY, middleY+1, middleY+2} };
    }
}
void s21_rotate_figure_type_1(Figure *figure){
   if(figure->rotate == 0){ //work
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX - 1, middleX, middleX + 1, middleX - 1}, 
        .y = {middleY, middleY, middleY, middleY + 1}, .type = 1, .rotate =1 };
    } else if (figure->rotate == 1){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX, middleX +1}, 
        .y = {middleY-1 , middleY , middleY+1, middleY + 1}, .type = 1, .rotate = 2 };
    } else if (figure->rotate == 2){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX+1, middleX, middleX -1, middleX +1}, 
        .y = {middleY , middleY, middleY, middleY -1}, .type = 1, .rotate = 3 };
        
    } else if (figure->rotate == 3){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX, middleX -1}, 
        .y = {middleY -1, middleY , middleY+1, middleY-1 }, .type = 1, .rotate = 0 };
    }
}
void s21_rotate_figure_type_2(Figure *figure){
   if(figure->rotate == 0){ //work
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX - 1, middleX, middleX + 1, middleX +1 }, 
        .y = {middleY-1, middleY-1, middleY-1, middleY}, .type = 2, .rotate =1 };
    } else if (figure->rotate == 1){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX, middleX +1}, 
        .y = {middleY-1 , middleY , middleY+1, middleY - 1}, .type = 2, .rotate = 2 };
    } else if (figure->rotate == 2){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX+1, middleX, middleX -1, middleX -1}, 
        .y = {middleY , middleY, middleY, middleY -1}, .type = 2, .rotate = 3 };
        
    } else if (figure->rotate == 3){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX, middleX -1}, 
        .y = {middleY -2, middleY -1, middleY, middleY }, .type = 2, .rotate = 0 };
    }
}
void s21_rotate_figure_type_4(Figure *figure){
   if(figure->rotate == 0){ //test
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX - 1, middleX, middleX, middleX +1 }, 
        .y = {middleY-1, middleY -1, middleY, middleY }, .type = 4, .rotate =1 };
    } else if (figure->rotate == 1){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX -1, middleX -1}, 
        .y = {middleY -1 , middleY , middleY, middleY +1}, .type = 4, .rotate = 2 };
    } else if (figure->rotate == 2){ 
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX - 1, middleX, middleX, middleX +1 }, 
        .y = {middleY-1, middleY -1, middleY, middleY }, .type = 4, .rotate =3 };
        
    } else if (figure->rotate == 3){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX -1, middleX -1}, 
        .y = {middleY -1 , middleY , middleY, middleY +1}, .type = 4, .rotate = 0 };
    }
}
void s21_rotate_figure_type_5(Figure *figure){
  if(figure->rotate == 0){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX - 1, middleX, middleX + 1, middleX}, 
        .y = {middleY, middleY, middleY, middleY + 1}, .type = 5, .rotate =1 };
    } else if (figure->rotate == 1){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX, middleX +1}, 
        .y = {middleY-1 , middleY , middleY+1, middleY}, .type = 5, .rotate = 2 };
    } else if (figure->rotate == 2){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX+1, middleX, middleX -1, middleX}, 
        .y = {middleY, middleY, middleY, middleY -1}, .type = 5, .rotate = 3 };
    } else if (figure->rotate == 3){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX, middleX -1}, 
        .y = {middleY -1, middleY , middleY +1, middleY }, .type =5, .rotate = 0 };
    }
}
void s21_rotate_figure_type_6(Figure *figure){
   if(figure->rotate == 0){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
            *figure = (Figure){ .x = {middleX - 1, middleX, middleX, middleX +1 }, 
        .y = {middleY +1, middleY +1, middleY , middleY}, .type = 6, .rotate =1 };
    } else if (figure->rotate == 1){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX -1, middleX -1}, 
        .y = {middleY +1 , middleY , middleY, middleY -1}, .type = 6, .rotate = 2 };
    } else if (figure->rotate == 2){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX - 1, middleX, middleX, middleX +1 }, 
        .y = {middleY +1, middleY +1, middleY , middleY}, .type = 6, .rotate =3 };
    } else if (figure->rotate == 3){
        int middleX = figure->x[2];
        int middleY = figure->y[2];
        *figure = (Figure){ .x = {middleX, middleX, middleX -1, middleX -1}, 
        .y = {middleY +1 , middleY , middleY, middleY -1}, .type = 6, .rotate = 0 };
    }
}
int s21_rotate_figure(Figure *figure, int matrix[ROWS][COLS]){
     switch (figure->type) {
        case 0: 
            if(s21_possibility_of_rotate(figure, matrix) == 0 && s21_extra_check_for_rotate_type_0(figure, matrix) == 0){
                s21_rotate_figure_type_0(figure);
            }
            break;
        case 1:
            if(s21_possibility_of_rotate(figure, matrix) == 0){
                s21_rotate_figure_type_1(figure);
            }
            break;
        case 2:
            if(s21_possibility_of_rotate(figure, matrix) == 0){
                s21_rotate_figure_type_2(figure);
            }
            break;
        case 3: //квадрат необязательно ротейтить
            break;
        case 4:
            if(s21_possibility_of_rotate(figure, matrix) == 0){
                s21_rotate_figure_type_4(figure);
            }
            break;
        case 5:
            if(s21_possibility_of_rotate(figure, matrix) == 0){
                s21_rotate_figure_type_5(figure);
            }
            break;
        case 6:
            if(s21_possibility_of_rotate(figure, matrix) == 0){
                s21_rotate_figure_type_6(figure);
            }
            break;
        default:
            break;
    }
    return 0;
}