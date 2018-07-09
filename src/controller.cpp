
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
    }

    strcpy(mainWindow->closeButton, "Close [[X]]");
    mainWindow->closeButtonStart.lin = mainWindow->startPosition.lin;
    mainWindow->closeButtonStart.col = mainWindow->endPosition.col - strlen(mainWindow->closeButton);
    mainWindow->closeButtonEnd.lin = mainWindow->startPosition.lin;
    mainWindow->closeButtonEnd.col = mainWindow->endPosition.col;

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

void initScheduleWindow(Window *scheduleWindow, ListBox *scheduleListBox, Schedule *scheduleList, int *scheduleLength) {

    *scheduleWindow = initWindow({SCHEDULE_WINDOW_START_LIN, SCHEDULE_WINDOW_START_COL},
                                 {SCHEDULE_WINDOW_END_LIN, SCHEDULE_WINDOW_END_COL});


    initScheduleListBox(scheduleListBox, *scheduleLength, scheduleList);

    strcpy(scheduleWindow->closeButton, "Close [[X]]");
    scheduleWindow->closeButtonStart.lin = scheduleWindow->startPosition.lin;
    scheduleWindow->closeButtonStart.col = scheduleWindow->endPosition.col - strlen(scheduleWindow->closeButton);
    scheduleWindow->closeButtonEnd.lin = scheduleWindow->startPosition.lin;
    scheduleWindow->closeButtonEnd.col = scheduleWindow->endPosition.col;

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

void drawCloseButton(Window *window) {

    mostraTexto(window->closeButtonStart.lin, window->closeButtonStart.col, window->closeButtonEnd.col,
                window->closeButton, WHITE, ORANGE_1);

}

void drawScheduleWindow(Window *scheduleWindow, ListBox *scheduleListBox) {

    drawWindow(scheduleWindow, BLUE_1);
    drawListBox(scheduleListBox, BLUE_1);
    drawCloseButton(scheduleWindow);
}


int detectCloseButtonClick(Window *window, int lin, int col) {

    if (lin == window->closeButtonStart.lin) {
        if (col >= window->closeButtonStart.col && col <= window->closeButtonEnd.col) {
            return 1;
        }
    }

    return 0;

}
