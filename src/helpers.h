#ifndef HELPERS_H
#define HELPERS_H

#define MAX_SCHEDULE_INDEX_SIZE 5
#define SCHEDULE_SIZE 30
#define HOUR_SIZE 7

#define MAX_SEAT_INDEX_SIZE 4
#define SEATS_SIZE 30
#define SEAT_NAME_SIZE 100
#define SEAT_AGE_SIZE 5

#define BUS_NAME_SIZE 100
#define MAX_INDEX_SIZE 5
#define BUS_SIZE 100

#define OVERLAP -1

#define KEY_UP 101
#define KEY_DOWN 103

#define SCHEDULE_WINDOW_START_LIN 5
#define SCHEDULE_WINDOW_END_LIN 30
#define SCHEDULE_WINDOW_START_COL 10
#define SCHEDULE_WINDOW_END_COL 90

static const int APP_LINES = 35;
static const int APP_COLUMNS = 100;


typedef struct {
    int lin, col;
} Position;

typedef struct {
    Position startPosition, endPosition;
    int status;
    char closeButton[30];
    Position closeButtonStart, closeButtonEnd;
} Window;

enum {
    ACTIVE, INACTIVE
}WindowStatusEnum;

int linToY(int lin);

int colToX(int col);

void mostraTexto(int l, int startCol, int endCol, char *msg,int rT,int gT,int bT,int rB, int gB,int bB);

Window initWindow(Position startPosition, Position endPosition);

void drawWindow(Window *window, int r, int g, int b);

void clearScreen();

void clearScreen(Window *window);

void clearScreen(Position startPosition, Position endPosition);

#endif // HELPERS_H
