#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void getWindowSize(int size[2]) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  size[0] = w.ws_row;
  size[1] = w.ws_col;
}

int main(int argc, char *argv[]) {
  int playing = 1;
  int size[2];
  getWindowSize(size);

  printf("Szerokość okna: %d, Wysokość %d\n", size[1], size[0]);

  return 1;
}
