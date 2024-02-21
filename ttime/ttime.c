#include <stdio.h>
#include <time.h>

#define ESC "\033"
#define SET_BACK_COLOR ESC"[48;5;%dm"

int main(void) {
  time_t current_time;
  char* c_time_string;
  current_time = time(NULL);
  c_time_string = ctime(&current_time);

  int color_code = 4; // Blue background

  printf(SET_BACK_COLOR, color_code);
  printf(c_time_string);
  printf(ESC"[0m"); // Reset colors to default

  return 0;
}

