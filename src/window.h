#ifndef WINDOW_H
#define WINDOW_H


#include "helpers.h"
#include "bus.h"

#define SCHEDULE_WINDOW_START_LIN 5
#define SCHEDULE_WINDOW_END_LIN 30
#define SCHEDULE_WINDOW_START_COL 10
#define SCHEDULE_WINDOW_END_COL 90

#define SEATS_WINDOW_START_LIN 10
#define SEATS_WINDOW_END_LIN 25
#define SEATS_WINDOW_START_COL 40
#define SEATS_WINDOW_END_COL 80


typedef struct {
    Position startPosition, endPosition;
    int status;
    char closeButton[30];
    Position closeButtonStart, closeButtonEnd;
} Window;

enum {
    ACTIVE, INACTIVE
} WindowStatusEnum;


Window initWindow(Position startPosition, Position endPosition);

void drawWindow(Window *window, int r, int g, int b);

void drawCloseButton(Window *window);

int detectCloseButtonClick(Window *window, int lin, int col);

void changeCloseButton(Window *window, char *closeButton, Position startPosition, Position endPosition);

void clearScreen(Window *window);

#endif // WINDOW_H
