#ifndef GAME_H
#define GAME_H

extern int *snakeX, *snakeY;
extern int snake_lenght;
extern int *apple;
extern int directionX, directionY;
extern int size[2];

void getWindowSize();
void spawnApple();
void gameIni();
void moveSnake();
void changeDirection(char direction);
void printGameArea();
void eatApple();
void checkCollision(int *isRunning);
int checkCollisionSelf();
int checkCollisionBorder();
void disableBuffering();
void checkEVERYTHING(int *isRunning);
int getPlayableSize();
int checkWin();
#endif
