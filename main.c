#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int snakeX[100], snakeY[100];
int snake_lenght = 1;
int apple[2];

int size[2];

void getWindowSize() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  size[0] = w.ws_row;
  size[1] = w.ws_col;
}

void spawnApple() {
  apple[0] = rand() % size[0];
  apple[1] = rand() % size[1];
}

void gameIni() {
  snakeX[0] = size[0] / 2;
  snakeY[0] = size[1] / 2;

  spawnApple();
}

void printGameArea(int width, int height) {}

int main(int argc, char *argv[]) { return 1; }
