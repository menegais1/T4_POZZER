#include "mpc_c.h"
#include "listBox.h"
#include "helpers.h"
#include <stdio.h>
#include <string.h>
#include "window.h"


void drawCloseButton(Window *window) {

    mostraTexto(window->closeButtonStart.lin, window->closeButtonStart.col, window->closeButtonEnd.col,
                window->closeButton, WHITE, ORANGE_1);

}


int detectCloseButtonClick(Window *window, int lin, int col) {

    if (lin == window->closeButtonStart.lin) {
        if (col >= window->closeButtonStart.col && col <= window->closeButtonEnd.col) {
            return 1;
        }
    }

    return 0;

}

void changeCloseButton(Window *window, char *closeButton, Position startPosition, Position endPosition) {
    strcpy(window->closeButton, closeButton);
    window->closeButtonStart.lin = startPosition.lin;
    window->closeButtonStart.col = endPosition.col - strlen(closeButton);
    window->closeButtonEnd.lin = startPosition.lin;
    window->closeButtonEnd.col = endPosition.col;


}


Window initWindow(Position startPosition, Position endPosition) {
    Window window;
    window.startPosition = startPosition;
    window.endPosition = endPosition;
    window.status = INACTIVE;
    return window;
}

void drawWindow(Window *window, int r, int g, int b) {

    int startX, endX, startY, endY;
    startX = colToX(window->startPosition.col);
    endX = colToX(window->endPosition.col);
    startY = linToY(window->startPosition.lin);
    endY = linToY(window->endPosition.lin);

    clearScreen(window);

    mpcVLine(startX, startY, endY, r, g, b, 1);
    mpcVLine(endX, startY, endY, r, g, b, 1);
    mpcHLine(startY, startX, endX, r, g, b, 1);
    mpcHLine(endY, startX, endX, r, g, b, 1);


}


void clearScreen(Window *window) {
    int i, j;
    for (i = window->startPosition.lin; i < window->endPosition.lin; i++) {
        for (j = window->startPosition.col; j < window->endPosition.col; j++) {
            mpcSetChar(i, j, ' ', F_STD, WHITE, TRANSP, 1);
        }
    }
}
