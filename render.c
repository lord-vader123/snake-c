#include "game.h"
#include <stdio.h>

void printGameArea() {
  for (int y = 0; y < size[0]; y++) {
    for (int x = 0; x < size[1]; x++) {
      if (x == snakeX[0] && y == snakeY[0]) {
        printf("O");
      } else if (x == apple[1] && y == apple[0]) {
        printf("A");
      } else if (y == 1 || y == size[0] - 1) {
        printf("-");
      } else if (x == 0 || x == size[1] - 1) {
        printf("|");
      } else {
        int isBody = 0;
        for (int i = 1; i < snake_lenght; i++) {
          if (x == snakeX[i] && y == snakeY[i]) {
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
