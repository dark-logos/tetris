#include "s21_brickGame.h"

int s21_createFigure(Figure *figure, int type) {
  switch (type) {
    case 0:
      *figure = (Figure){.x = {0, 0, 0, 0}, .y = {3, 4, 5, 6}, .type = 0};
      break;
    case 1:
      *figure = (Figure){.x = {-1, 0, 0, 0}, .y = {3, 3, 4, 5}, .type = 1};
      break;
    case 2:
      *figure = (Figure){.x = {0, 0, 0, -1}, .y = {4, 5, 6, 6}, .type = 2};
      break;
    case 3:
      *figure = (Figure){.x = {-1, 0, 0, -1}, .y = {4, 4, 5, 5}, .type = 3};
      break;
    case 4:
      *figure = (Figure){.x = {0, 0, -1, -1}, .y = {3, 4, 4, 5}, .type = 4};
      break;
    case 5:
      *figure = (Figure){.x = {0, 0, -1, 0}, .y = {3, 4, 4, 5}, .type = 5};
      break;
    case 6:
      *figure = (Figure){.x = {-1, -1, 0, 0}, .y = {3, 4, 4, 5}, .type = 6};
      break;
  }
  return 0;
}

void s21_separating_figure_from_matrix(Figure figure,
                                       int matrix[FIELD_ROWS][FIELD_COLS],
                                       int isFigureNowField) {
  for (int i = 0; i < 4; i++) {
    matrix[figure.x[i]][figure.y[i]] = isFigureNowField;
  }
}
