#include "days.h"


void main() {
    printf("Print Monday \n");
    printDay(Monday);
    printf("Random Indexes \n");
    initRandom();
    printRandomIndexes();
    int weekCount = 4;
    int dayCount = 7;
    days month[weekCount][dayCount];
    fillDays(weekCount, dayCount, month);
    printMonth(weekCount, dayCount, month);
    int date = 27;
    printf("The %d of the month is ", date);
    getDayOfDate(weekCount, dayCount, date, month);

    printf("Calendar with Random Start Date \n");
    fillDaysWithRandomStart(weekCount,dayCount,month);
    printMonth(weekCount,dayCount,month);
    printf("The %d of the month is ", date);
    getDayOfDate(weekCount, dayCount, date, month);
}


