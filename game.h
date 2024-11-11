#ifndef GAME_H
#define GAME_H

extern int snakeX[], snakeY[];
extern int snake_lenght;
extern int apple[];
extern int directionX, directionY;
extern int size[];

void getWindowSize();
void spawnApple();
void gameIni();
void moveSnake();
void changeDirection(char direction);
void printGameArea();
void eatApple();
void checkCollision(int *isRunning);
void disableBuffering();

#endif
