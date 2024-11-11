#include "game.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

void getWindowSize() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  size[0] = w.ws_row;
  size[1] = w.ws_col;
}

void disableBuffering() {
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~ICANON;
  t.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);

  fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}
