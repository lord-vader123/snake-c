#include "game.h"
#include <stdio.h>

void printGameArea() {
  for (int row = 0; row < size[0]; row++) {
    for (int column = 0; column < size[1]; column++) {
      if (column == snakeX[0] && row == snakeY[0]) {
        printf("O");
      } else if (column == apple[0] && row == apple[1]) {
        printf("A");
      } else if (row == 1 || row == size[0] - 1) {
        printf("-");
      } else if (column == 0 || column == size[1] - 1) {
        printf("|");
      } else {
        int isBody = 0;
        for (int i = 1; i < snake_lenght; i++) {
          if (column == snakeX[i] && row == snakeY[i]) {
            printf("o");
            isBody = 1;
            break;
          }
        }
        if (!isBody)
          printf(" ");
      }
    }
    printf("\n");
  }
}
