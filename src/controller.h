
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "window.h"
void initMainWindow(Window *mainWindow, ListBox *busListBox, Bus **busList, int *busLength);

void initBusListBox(ListBox *busListBox, int busLength, Bus *busList);

void drawMainWindow(Window *mainWindow, ListBox *busListBox);

void initScheduleWindow(Window *scheduleWindow, ListBox *scheduleListBox, Schedule *scheduleList, int scheduleLength);

void initScheduleListBox(ListBox *scheduleListBox, int scheduleLength, Schedule *scheduleList);

void drawScheduleWindow(Window *scheduleWindow, ListBox *scheduleListBox);


void drawSeats(Position startPosition, Position endPosition, Seat *seats, int seatsLength);

void drawSeatsWindow(Window *seatsWindow, Seat *seats, int seatsLength);

void initSeatsWindow(Window *seatsWindow, Seat *seats, int seatsLength);
#endif // CONTROLLER_H
