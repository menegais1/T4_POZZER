

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "seat.h"
#include "helpers.h"

struct _Schedule{
    char hour[HOUR_SIZE];
    Seat seats[SEATS_SIZE];
    int exists;
};


typedef struct _Schedule Schedule;

void initScheduleList(Schedule scheduleList[]);

Schedule initSchedule();

int addPreExistentSchedules(Schedule scheduleList[], int* length);

int newSchedule(Schedule scheduleList[], int* length);

int removeSchedule(Schedule scheduleList[], int* length);

void listSchedule(Schedule scheduleList[], int length);

Schedule* selectSchedule(Schedule scheduleList[], int length);

#endif // SCHEDULE_H
