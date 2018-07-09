
#ifndef SEAT_H
#define SEAT_H


#include "helpers.h"

struct _Seat{
    char name[SEAT_NAME_SIZE];
    int age, reserved;
};

typedef struct _Seat Seat;

void initSeatList(Seat seatList[]);

int reserveSeat(Seat* seat, int reserve);

Seat* selectSeat(Seat seatList[],int reservedOnly);
int listSeats(Seat seatList[],int reservedOnly);

#endif // SEAT_H