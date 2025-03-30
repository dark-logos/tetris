#include "tetris/s21_brickGame.h"

int main() {
  GameState state = {0};
  s21_ui_init();
  s21_draw_start_menu(&state);
  s21_game_cycle(&state);
  s21_ui_draw_game_over();
  napms(2000);
  s21_ui_shutdown();
  return 0;
}
