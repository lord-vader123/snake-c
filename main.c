#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int *snakeX, *snakeY;
int snake_lenght = 5;
int *apple;
int directionX = 0, directionY = 0;
int size[2];

void gameIni() {
  snake_lenght = 5;

  apple = (int *)malloc(sizeof(int) * 2);

  snakeX = (int *)malloc(sizeof(int) * snake_lenght);
  snakeY = (int *)malloc(sizeof(int) * snake_lenght);

  if (snakeX == NULL || snakeY == NULL || apple == NULL) {
    printf("Memory allocation problem.\n");
    exit(1);
  }

  getWindowSize();

  snakeX[0] = size[0] / 2;
  snakeY[0] = size[1] / 2;
}

void gameLoop() {
  disableBuffering();

  spawnApple();
  int isRunning = 1;

  changeDirection(getchar());
  moveSnake();

  while (isRunning) {
    printGameArea();

    int inputChar = getchar();
    if (inputChar != EOF) {
      changeDirection(inputChar);
    }

    moveSnake();
    checkCollision(&isRunning);

    usleep(100000);
  }
}

void releaseResources() {
  free(snakeX);
  free(snakeY);
  free(apple);
}

int main(int argc, char *argv[]) {
  srand(time(0));
  getWindowSize();
  gameIni();
  gameLoop();
  releaseResources();

  return 0;
}
