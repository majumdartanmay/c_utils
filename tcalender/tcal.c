#include <stdlib.h>
#include "tcal.h"
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h> 

const unsigned short TITLE_MARGIN = 4;

const char *months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

const char *week_days[] = {
    "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"
};

int total_days(struct tm *local_time) 
{ 
  
    DWORD days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    const int current_month = local_time-> tm_mon;

    // Check for leap year (if February has 29 days)
    if (current_month == 1 &&
        ((local_time->tm_year % 4 == 0 
        && local_time->tm_year % 100 != 0) || local_time->tm_year % 400 == 0)) {

        days_in_month[1] = 29;
    }

    return days_in_month[current_month];
} 
void print_cal(TDate* current_date) {

    for (int i = 0; i < TITLE_MARGIN ; i++) {
        printf(" ");
    }

    printf("%s %d\n", months[current_date->month], current_date->year);

    for (unsigned short week_day = 0; week_day < 7; week_day++) {
        printf("%s ", week_days[week_day]); 
    }

    printf("\n"); 

    const unsigned short offset = current_date->week_day;

    int total_counter = 0;
    for (int i = 0; i < current_date->total_days + offset; ++i) {

        total_counter++;

        if (i < offset) {
            printf("   ");
            continue;
        }
        
        const int day = i - offset + 1;
        if (day < 10) {
            dump_to_console(day, current_date->day == day);
        }else {
            dump_to_console(day, current_date->day == day);
        }

        if (total_counter % 7 == 0) {
            printf("\n");
        }
    } 
}

void dump_to_console(int day, bool is_current_day) {
   if (is_current_day) {
        printf("\033[3;42;30m");
   }
    if (day < 10) {
        printf(" %d ", (day));
    }else {
        printf("%d ", (day));
    }

   if (is_current_day) {
        printf("\033[0m"); // Reset color to default
   }
}

TDate create_context() {

    time_t current_time;
    struct tm *local_time;

    // Get the current time
    time(&current_time);
    // Convert to local time structure
    local_time = localtime(&current_time);

    const TDate temp_tdate = 
        {   
            .total_days = total_days(local_time),
            .month = local_time->tm_mon ,
            .year = local_time->tm_year + 1900,
            .week_day = local_time->tm_wday,
            .day = local_time->tm_mday 
        };
    
    return temp_tdate;
}

int main( void ) {

    TDate t_date = create_context();
    print_cal(&t_date);

    return 0;
}
