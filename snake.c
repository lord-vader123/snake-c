#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void moveSnake() {
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
  if (snakeX[0] == apple[0] && snakeY[0] == apple[1]) {
    snake_lenght++;
    snakeX = realloc(snakeX, sizeof(int) * snake_lenght);
    snakeY = realloc(snakeY, sizeof(int) * snake_lenght);

    if (snakeX == NULL || snakeY == NULL) {
      printf("Memory allocation problem");
      exit(1);
    }
    spawnApple();
  }
}

int checkCollisionSelf() {
  if (snake_lenght < 1) {
    return 0;
  }
  for (int i = 1; i < snake_lenght; i++) {
    if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
      printf("You hit yourself, dum dum D:");
      return 1;
    }
  }
  return 0;
}

int checkCollisionBorder() {
  if (snakeY[0] == 1 || snakeY[0] == size[0] - 1 || snakeX[0] == 0 ||
      snakeX[0] == size[1] - 1) {
    printf("You hit the wall!");
    return 1;
  }
  return 0;
}

void checkCollision(int *isRunning) {
  if (checkCollisionBorder() || checkCollisionSelf()) {
    *isRunning = 0;
    printf("Game ended, you lost :(");
  }
  return;
}

void spawnApple() {
  apple[0] = (rand() % (size[0] - 1)) + 1;
  apple[1] = (rand() % (size[1] - 1)) + 1;
}
