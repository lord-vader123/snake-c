#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <time.h>
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

void printGameArea() {
  for (int y = 0; y < size[0]; y++) {
    for (int x = 0; x < size[1]; x++) {
      if (x == snakeX[0] && y == snakeY[0]) { // Pozycja węża
        printf("O");
      } else if (x == apple[1] && y == apple[0]) { // Pozycja jabłka
        printf("A");
      } else if (y == 0 || y == size[0] - 1) { // Górna i dolna ramka
        printf("-");
      } else if (x == 0 || x == size[1] - 1) { // Boczne ramki
        printf("|");
      } else { // Puste pole
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  srand(time(0));
  getWindowSize();
  gameIni();
  printGameArea();

  return 0;
}
