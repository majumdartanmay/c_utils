#ifndef TCAL_H
#define TCAL_H
#include <stdbool.h>

typedef struct {
  unsigned short month;  // Values from 1 to 12
  unsigned short year;   // Values from 0 to 65535 (assuming unsigned short is 16 bits)
  unsigned short week_day; // Current week day
  unsigned short total_days; // total days in a month
  unsigned short day; // today
} TDate;

void print_cal(TDate* date);
TDate init_context();
void dump_to_console(int day, bool is_current_day);

#endif
