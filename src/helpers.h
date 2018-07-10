#ifndef HELPERS_H
#define HELPERS_H

#define MAX_SCHEDULE_INDEX_SIZE 5
#define SCHEDULE_SIZE 30
#define HOUR_SIZE 7

#define MAX_SEAT_INDEX_SIZE 4
#define SEATS_SIZE 100
#define SEAT_NAME_SIZE 100
#define SEAT_AGE_SIZE 5

#define BUS_NAME_SIZE 100
#define MAX_INDEX_SIZE 5
#define BUS_SIZE 100

#define OVERLAP -1

#define KEY_UP 101
#define KEY_DOWN 103

#define SEAT_BOX_SIZE_COL 2
#define SEAT_BOX_SIZE_LIN 2

static const int APP_LINES = 35;
static const int APP_COLUMNS = 100;


typedef struct {
    int lin, col;
} Position;


int linToY(int lin);

int colToX(int col);

void mostraTexto(int l, int startCol, int endCol, char *msg,int rT,int gT,int bT,int rB, int gB,int bB);

void clearScreen();

void clearScreen(Position startPosition, Position endPosition);

#endif // HELPERS_H
