#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int *snakeX, *snakeY;
int snake_lenght;
int *apple;
int directionX = 0, directionY = 0;
int size[2];

void gameIni() {
  snake_lenght = 1;

  apple = (int *)malloc(sizeof(int) * 2);

  snakeX = (int *)malloc(sizeof(int) * snake_lenght);
  snakeY = (int *)malloc(sizeof(int) * snake_lenght);

  if (snakeX == NULL || snakeY == NULL || apple == NULL) {
    printf("Memory allocation problem.\n");
    exit(1);
  }

  getWindowSize();

  snakeX[0] = size[1] / 2;
  snakeY[0] = size[0] / 2;

  spawnApple();
}

void gameLoop() {
  disableBuffering();

  int isRunning = 1;

  while (isRunning) {
    printf("\033[H\033[J");
    printGameArea();

    int inputChar = getchar();
    if (inputChar != EOF) {
      changeDirection(inputChar);
    }

    moveSnake();
    checkEVERYTHING(&isRunning);

    if (checkWin()) {
      isRunning = 0;
      printf("You won! :D");
    }

    usleep(100000);
  }
}

void releaseResources() {
  free(snakeX);
  free(snakeY);
  free(apple);
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  gameIni();
  gameLoop();
  releaseResources();

  return 0;
}
