#include <asm-generic/ioctls.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

int snakeX[100], snakeY[100];
int snake_lenght = 1;
int apple[2];

int directionX = 1, directionY = 0;

int size[2];

void getWindowSize() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  size[0] = w.ws_row;
  size[1] = w.ws_col;
}

void spawnApple() {
  apple[0] = (rand() % (size[0] - 1)) + 1;
  apple[1] = (rand() % (size[1] - 1)) + 1;
}

void gameIni() {
  snakeX[0] = size[0] / 2;
  snakeY[0] = size[1] / 2;

  spawnApple();
}

void moveSnake() {
  for (int i = snake_lenght - 1; i > 0; i++) {
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

void disableBuffering() {
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~ICANON;
  t.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);

  fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

void gameLoop() {
  disableBuffering();

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
