#include "s21_brickGame.h"

int s21_find_full_rows(int rows_to_clear[ROWS], int matrix[ROWS][COLS]) {
    int count = 0;
    for (int i = ROWS - 1; i >= 0; i--) {
        int is_full = 1;
        
        for (int j = 0; j < COLS; j++) {
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

void s21_zeroing_out_rows(int rows_to_clear[], int count, int matrix[ROWS][COLS]) {
    for (int i = 0; i < count; i++) {
        int row = rows_to_clear[i];
        for (int j = 0; j < COLS; j++) {
            matrix[row][j] = 0;
        }
    }
}

void s21_falling_blocks(int rows_to_clear[], int count, int matrix[ROWS][COLS]) {
    int write_ptr = ROWS - 1; // Указатель записи
    
    // Строим новую матрицу снизу вверх
    for (int read_ptr = ROWS - 1; read_ptr >= 0; read_ptr--) {
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
            for (int j = 0; j < COLS; j++) {
                matrix[write_ptr][j] = matrix[read_ptr][j];
            }
            write_ptr--;
        }
    }
    
    // Заполняем оставшиеся верхние строки нулями
    while (write_ptr >= 0) {
        for (int j = 0; j < COLS; j++) {
            matrix[write_ptr][j] = 0;
        }
        write_ptr--;
    }
}

// int s21_find_full_rows(int rowToDelete[ROWS], int matrix[ROWS][COLS]){
//     int y = 0;
//     rowToDelete[0] = -1;
//      for (int i = ROWS; i >= 0; i--) {
//         for (int j = 0; j < COLS; j++) {
//             if (matrix[i][j] == 0) {
//                 i--;
//                 j = 0;
//             } else if (j == COLS - 1 && matrix[i][j] == 1) {
//                 rowToDelete[y] = i;
//                 y++;
//             }
//         }
//     }
//     rowToDelete[y] = -1;
//     return rowToDelete[0];
// }

// void s21_zeroing_out_raws(int rowToDelete[ROWS], int matrix[ROWS][COLS]){
//     for (int z = 0; rowToDelete[z] != -1; z++) {
//         for (int j = 0; j < COLS; j++) {
//             matrix[rowToDelete[z]][j] = 0;
//             // +100 очков
//         }
//     }
// }
// void s21_falling_because_zeroing(int rowToDelete[ROWS], int matrix[ROWS][COLS]){
//      for (int z = 0; rowToDelete[z] != -1; z++) {
//         for (int i = rowToDelete[z]; i > rowToDelete[z + 1]; i--) { 
//             for (int j = 0; j < COLS; j++) {
//                 if (matrix[i][j] == 1) {
//                     matrix[i][j] = 0;
//                     matrix[i + 1][j] = 1;
//                 }
//             }
//         }
//     }
// }