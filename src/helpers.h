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

typedef struct {
    int lin, col;
} Position;

int linToY(int lin);

int colToX(int col);

void mostraTexto(int l, int startCol, int endCol, char *msg,int rT,int gT,int bT,int rB, int gB,int bB);

#endif // HELPERS_H
