
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mpc_c.h"
#include "mpc_callbacks.h"
#include "listBox.h"
#include "bus.h"
#include "schedule.h"
#include "controller.h"
#include "helpers.h"

void initMainWindow(Window *mainWindow, ListBox *busListBox, Bus **busList, int *busLength) {

    *mainWindow = initWindow({0, 0}, {APP_LINES, APP_COLUMNS});

    *busLength = 0;
    *busList = initBusList();
    if (readFile(*busList, busLength) == 0) {
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
        addPreExistentBus(*busList, busLength);
    }

    changeCloseButton(mainWindow, "Close [[X]]", mainWindow->startPosition, mainWindow->endPosition);


    initBusListBox(busListBox, *busLength, *busList);


}

void initBusListBox(ListBox *busListBox, int busLength, Bus *busList) {

    char **nameList = (char **) malloc(200);
    for (int i = 0; i < busLength; i++) {
        nameList[i] = busList[i].name;
    }
    *busListBox = newListBox({LIST_BOX_START_LIN, LIST_BOX_START_COL},
                             {LIST_BOX_END_LIN, LIST_BOX_END_COL}, nameList, busLength);

    changePadding(busListBox, LIST_BOX_LIN_PADDING, LIST_BOX_COL_PADDING);
    changeScroll(busListBox, SCROLL_SIZE, SCROLL_DESLOCATION_LIN, SCROLL_DESLOCATION_COL);
    setTitle(busListBox, "Lista de Onibus");
}

void drawMainWindow(Window *mainWindow, ListBox *busListBox) {

    drawWindow(mainWindow, BLUE_1);
    drawListBox(busListBox, WHITE);
    drawCloseButton(mainWindow);
}

void initScheduleWindow(Window *scheduleWindow, ListBox *scheduleListBox, Schedule *scheduleList, int scheduleLength) {

    *scheduleWindow = initWindow({SCHEDULE_WINDOW_START_LIN, SCHEDULE_WINDOW_START_COL},
                                 {SCHEDULE_WINDOW_END_LIN, SCHEDULE_WINDOW_END_COL});


    initScheduleListBox(scheduleListBox, scheduleLength, scheduleList);

    changeCloseButton(scheduleWindow, "Close [[X]]", scheduleWindow->startPosition, scheduleWindow->endPosition);


}

void initScheduleListBox(ListBox *scheduleListBox, int scheduleLength, Schedule *scheduleList) {

    char **nameList;
    if (scheduleListBox->nameList != NULL) {
        free(scheduleListBox->nameList);
        scheduleListBox->nameList = NULL;
    }

    nameList = (char **) malloc(200);
    if (nameList == NULL) {
        printf("IMPOSSIVEL ALOCAR MEMORIA");
        exit(0);
        return;
    }


    for (int i = 0; i < scheduleLength; i++) {
        nameList[i] = scheduleList[i].hour;
    }


    *scheduleListBox = newListBox({SCHEDULE_LIST_BOX_START_LIN, SCHEDULE_LIST_BOX_START_COL},
                                  {SCHEDULE_LIST_BOX_END_LIN, SCHEDULE_LIST_BOX_END_COL}, nameList, scheduleLength);

    changePadding(scheduleListBox, LIST_BOX_LIN_PADDING, LIST_BOX_COL_PADDING);
    changeScroll(scheduleListBox, SCROLL_SIZE, SCROLL_DESLOCATION_LIN, SCROLL_DESLOCATION_COL);
    setTitle(scheduleListBox, "Lista de Horarios");
}


void drawScheduleWindow(Window *scheduleWindow, ListBox *scheduleListBox) {

    drawWindow(scheduleWindow, BLUE_1);
    drawListBox(scheduleListBox, BLUE_1);
    drawCloseButton(scheduleWindow);
}

void initSeatsWindow(Window *seatsWindow, Seat *seats, int seatsLength) {

    *seatsWindow = initWindow({SEATS_WINDOW_START_LIN, SEATS_WINDOW_START_COL},
                              {SEATS_WINDOW_END_LIN, SEATS_WINDOW_END_COL});


    changeCloseButton(seatsWindow, "Close [[X]]", seatsWindow->startPosition, seatsWindow->endPosition);

}

void drawSeatsWindow(Window *seatsWindow, Seat *seats, int seatsLength) {

    drawWindow(seatsWindow, ORANGE_1);
    drawSeats({ seatsWindow->closeButtonStart.lin +2, seatsWindow->startPosition.col + 1}, seatsWindow->endPosition,seats, seatsLength);
    drawCloseButton(seatsWindow);
}

void drawSeats(Position startPosition, Position endPosition, Seat *seats, int seatsLength) {
    int i, currentCol, currentLin;
    currentCol = startPosition.col;
    currentLin = startPosition.lin;
    for (i = 0; i < seatsLength; i++) {
        if(currentCol >= endPosition.col){
            currentLin += SEAT_BOX_SIZE_LIN;
            currentCol = startPosition.col;
        }

        if(currentLin >= endPosition.lin){
            break;
        }

        if(seats[i].reserved == 1){
            mpcSetChar(currentLin, currentCol, '*',F_STD,WHITE, RED_1,1);
        }else{
            mpcSetChar(currentLin, currentCol, '0',F_STD,WHITE, GREEN_2,1);
        }
        currentCol += SEAT_BOX_SIZE_COL;
    }

}
