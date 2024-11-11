#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int *snakeX, *snakeY;
int snake_lenght = 5;
int *apple = NULL;
int directionX = 0, directionY = 0;
int *size = NULL;

void gameIni() {
  snake_lenght = 5;

  snakeX = (int *)malloc(sizeof(int) * snake_lenght);
  snakeY = (int *)malloc(sizeof(int) * snake_lenght);

  if (snakeX == NULL || snakeY == NULL) {
    printf("Błąd przy alokacji pamięci.\n");
    exit(1);
  }

  snakeX[0] = size[0];
  snakeY[0] = size[1];
}

void gameLoop() {
  disableBuffering();

  spawnApple();
  int isRunning = 1;

  while (isRunning) {
    system("clear");
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

int main(int argc, char *argv[]) {
  srand(time(0));
  getWindowSize();
  gameIni();
  gameLoop();

  return 0;
}
