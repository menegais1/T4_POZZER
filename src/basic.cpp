
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mpc_c.h"
#include "basic.h"
#include "listBox.h"
#include "bus.h"
char matrizDeCaracteres[APP_LINES][APP_COLUMNS];

int cursorLine, cursorColumn;

ListBox busListBox;
int busLength;
Bus *busList;

void initMpc(void)
{

    mpcSetSize(APP_LINES, APP_COLUMNS);

    memset(matrizDeCaracteres, ' ', APP_LINES * APP_COLUMNS);

     busLength = 0;
     busList = initBusList();
    if (readFile(busList, &busLength) == 0)
    {
        addPreExistentBus(busList, &busLength);
        addPreExistentBus(busList, &busLength);
        addPreExistentBus(busList, &busLength);
        addPreExistentBus(busList, &busLength);
        addPreExistentBus(busList, &busLength);
        addPreExistentBus(busList, &busLength);
    }

    char **nameList= (char **)malloc(200);
    for(int i=0;i<busLength;i++){
        nameList[i] = busList[i].name;
    }

    busListBox = newListBox({LIST_BOX_START_LIN, LIST_BOX_START_COL},
                         {LIST_BOX_END_LIN, LIST_BOX_END_COL}, nameList, busLength);

    changePadding(&busListBox, LIST_BOX_LIN_PADDING, LIST_BOX_COL_PADDING);
    changeScroll(&busListBox, SCROLL_SIZE, SCROLL_DESLOCATION_LIN, SCROLL_DESLOCATION_COL);
    setTitle(&busListBox, "Lista de Onibus");

    mpcSetMouseFunc(cbMouse);
    mpcSetUpdateFunc(cbUpdate);
    mpcSetKeyboardFunc(cbKeyboard);

    mpcAbout();
}

void displayApp(void)
{
    clearScreen();

    drawListBox(&busListBox, WHITE);
    if(busListBox.currentItemIndex != -1){
        drawBusWindow(&busList[busListBox.currentItemIndex]);
    }
}

void clearScreen(){
    int i, j;
    for (i = 0; i < APP_LINES; i++)
    {
        for (j = 0; j < APP_COLUMNS; j++)
        {
            mpcSetChar(i, j, ' ', F_STD, WHITE, TRANSP, 1);
        }
    }
}

void leftButtonClick(int lin, int col)
{
   detectMouseClick(&busListBox,lin,col);

}

void cbMouse(int lin, int col, int button, int state)
{
    if (button == 0 && state == 0)
    {
        leftButtonClick(lin, col);
    }
}

void cbKeyboard(int key, int modifier, bool special, bool up)
{
    if (special)
    {
        printf("%d", key);
        if (up)
        {
            switch (key)
            {
            case KEY_UP:

                break;
            case KEY_DOWN:

                break;
            }
        }
    }
}

void cbUpdate(void)
{
    displayApp();
}
