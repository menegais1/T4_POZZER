
#ifndef BUS_H
#define BUS_H

#include "schedule.h"
#include "helpers.h"


struct _Bus{
    char name[BUS_NAME_SIZE];
    Schedule schedules[SCHEDULE_SIZE];
    int schedules_length;
    int exists;
};


typedef struct _Bus Bus;

Bus* initBusList();

Bus initBus();

int addPreExistentBus(Bus busList[],int* length);

int writeFile(Bus busList[]);

int readFile(Bus busList[], int* busLength);

void drawBusWindow(Bus *bus);

#endif // BUS_H
