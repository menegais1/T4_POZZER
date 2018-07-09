
#ifndef CONTROLLER_H
#define CONTROLLER_H

void initMainWindow(Window *mainWindow, ListBox *busListBox, Bus **busList, int *busLength);

void initBusListBox(ListBox *busListBox, int busLength, Bus *busList);

void drawMainWindow(Window *mainWindow, ListBox *busListBox);

void initScheduleWindow(Window *scheduleWindow, ListBox *scheduleListBox, Schedule *scheduleList, int *scheduleLength);

void initScheduleListBox(ListBox *scheduleListBox, int scheduleLength, Schedule *scheduleList);

void drawScheduleWindow(Window *scheduleWindow, ListBox *scheduleListBox);

void drawCloseButton(Window *window);

int detectCloseButtonClick(Window *window, int lin, int col);

#endif // CONTROLLER_H
