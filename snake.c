#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void moveSnake() {
  if (snake_lenght <= 1)
    return;

  for (int i = snake_lenght - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  snakeX[0] += directionX;
  snakeY[0] += directionY;
}

void changeDirection(char direction) {
  switch (direction) {
  case 'w':
    directionX = 0;
    directionY = -1;
    break;
  case 's':
    directionX = 0;
    directionY = 1;
    break;
  case 'a':
    directionX = -1;
    directionY = 0;
    break;
  case 'd':
    directionX = 1;
    directionY = 0;
    break;
  default:
    break;
  }
}

void eatApple() {
  if (snakeX[0] == apple[1] && snakeY[0] == apple[0]) {
    snake_lenght++;
    spawnApple();
  }
}

void checkCollision(int *isRunning) {
  if (snakeY[0] == 1 || snakeY[0] == size[0] - 1 || snakeX[0] == 0 ||
      snakeX[0] == size[1] - 1) {
    *isRunning = 0;
    printf("Game ended, you lost :(");
  }
}

void spawnApple() {
  apple[0] = (rand() % (size[0] - 1)) + 1;
  apple[1] = (rand() % (size[1] - 1)) + 1;
}
