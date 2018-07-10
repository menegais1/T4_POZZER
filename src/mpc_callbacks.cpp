
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mpc_c.h"
#include "mpc_callbacks.h"
#include "listBox.h"
#include "bus.h"
#include "controller.h"

Window g_mainWindow;
Window g_schedulesWindow;
Window g_seatsWindow;

ListBox g_busListBox;
ListBox g_scheduleListBox;
int g_busLength;
Bus *g_busList;

void initMpc(void) {

    mpcSetSize(APP_LINES, APP_COLUMNS);
    mpcSetMouseFunc(cbMouse);
    mpcSetUpdateFunc(cbUpdate);
    mpcSetKeyboardFunc(cbKeyboard);
    mpcAbout();

    //INICIALIZAÇÃO DOS COMPONENTES

    initMainWindow(&g_mainWindow, &g_busListBox, &g_busList, &g_busLength);
    g_schedulesWindow.status = INACTIVE;
}

void displayApp(void) {

    drawMainWindow(&g_mainWindow, &g_busListBox);
    if (g_schedulesWindow.status == ACTIVE) {
        drawScheduleWindow(&g_schedulesWindow, &g_scheduleListBox);
    }
    if (g_seatsWindow.status == ACTIVE) {
        drawSeatsWindow(&g_seatsWindow,
                        g_busList[g_busListBox.currentItemIndex].schedules[g_scheduleListBox.currentItemIndex].seats,
                        SEATS_SIZE);
    }

}


void leftButtonClick(int lin, int col) {
    if (g_schedulesWindow.status == ACTIVE) {
        detectMouseClickListBox(&g_scheduleListBox, lin, col);
        if (detectCloseButtonClick(&g_schedulesWindow, lin, col) == 1) {
            g_schedulesWindow.status = INACTIVE;
            g_seatsWindow.status = INACTIVE;
            g_busListBox.currentItemIndex = -1;
        }
    } else {
        detectMouseClickListBox(&g_busListBox, lin, col);
        if (detectCloseButtonClick(&g_mainWindow, lin, col) == 1) {
            exit(0);
            return;
        }
    }

    if (g_seatsWindow.status == ACTIVE) {
        if (detectCloseButtonClick(&g_seatsWindow, lin, col) == 1) {
            g_seatsWindow.status = INACTIVE;
            g_scheduleListBox.currentItemIndex = -1;
        }
    }

}

void cbMouse(int lin, int col, int button, int state) {
    if (button == 0 && state == 0) {
        leftButtonClick(lin, col);
    }
}

void cbKeyboard(int key, int modifier, bool special, bool up) {
    if (special) {
        printf("%d", key);
        if (up) {
            switch (key) {
                case KEY_UP:

                    break;
                case KEY_DOWN:

                    break;
            }
        }
    }
}

void cbUpdate(void) {

    if (g_busListBox.currentItemIndex != -1 && g_schedulesWindow.status == INACTIVE) {
        initScheduleWindow(&g_schedulesWindow,
                           &g_scheduleListBox, g_busList[g_busListBox.currentItemIndex].schedules,
                           g_busList[g_busListBox.currentItemIndex].schedules_length);
        g_schedulesWindow.status = ACTIVE;
    }

    if (g_scheduleListBox.currentItemIndex != -1 && g_schedulesWindow.status == ACTIVE) {
        initSeatsWindow(&g_seatsWindow,
                        g_busList[g_busListBox.currentItemIndex].schedules[g_scheduleListBox.currentItemIndex].seats,
                        SEATS_SIZE);
        g_seatsWindow.status = ACTIVE;
    }

    displayApp();
}
