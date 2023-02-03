// Please convert this header file with proper implementation to be able to run calendar.c file properly.

#ifndef DAYS_WRONG_H
#define DAYS_WRONG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_H
typedef enum {
    // Carry Sunday to the last if your calendar starts with Monday
    Sunday,Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
} days;

void printDay(days day) {
    if (day == Monday) {
        printf("Monday");
    } else if (day == Tuesday) {
        printf("Tuesday");
    } else if (day == Wednesday) {
        printf("Wednesday");
    } else if (day == Thursday) {
        printf("Thursday");
    } else if (day == Friday) {
        printf("Friday");
    } else if (day == Saturday) {
        printf("Saturday");
    } else if (day == Sunday) {
        printf("Sunday");
    } else {
        printf("Undefined Enum ! \n");
    }
}

void initRandom() {
    srand(time(NULL));
}

void fillDays(int weekCount, int dayCount, days month[weekCount][dayCount]) {
    for (int week = 0; week < weekCount; week++) {
        for (int day = 0; day < dayCount; day++) {
            month[week][day] = day;
        }
    }
}

void printMonth(int weekCount, int dayCount, days month[weekCount][dayCount]) {
    printf("Month \n");
    for (int week = 0; week < weekCount; week++) {
        for (int day = 0; day < dayCount; day++) {
            printDay(month[week][day]);
            printf(" | ");
        }
        printf("\n");
    }
    printf("\n");
}

void fillDaysWithRandomStart(int weekCount, int dayCount, days month[weekCount][dayCount]) {
    int startDay = rand()%dayCount;
    for (int week = 0; week < weekCount; week++) {
        for (int day = 0; day < dayCount; day++) {
            month[week][day] = startDay % dayCount;
            startDay++;
        }
    }
}

void getDayOfDate(int weekCount, int dayCount, int date, days month[weekCount][dayCount]) {
    int week = date / weekCount;
    int day = date % dayCount;
    if (week != 0) {
        week--;
    }
    if (day != 0) {
        day--;
    }
    printDay(month[week][day]);
    printf("\n");
}

void printRandomIndexes() {
    int rowCount = rand() % 10 + 1;
    int columnCount = rand() % 10 + 1;
    printf("%d-%d Indexes \n", rowCount, columnCount);
    for (int row = 0; row < rowCount; row++) {
        for (int column = 0; column < columnCount; column++) {
            printf("[%d%d]", row, column);
        }
        printf("\n");
    }
}

#endif
