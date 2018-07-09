#ifndef LIST_BOX_H
#define LIST_BOX_H

#define LIST_BOX_LIN_PADDING 1
#define LIST_BOX_COL_PADDING 2
#define LIST_BOX_START_LIN 10
#define LIST_BOX_START_COL 5
#define LIST_BOX_END_LIN 30
#define LIST_BOX_END_COL 25
#define SCROLL_SIZE 2
#define SCROLL_DESLOCATION_LIN 1
#define SCROLL_DESLOCATION_COL 1
#define CONTENT_DESLOCATION_LIN 1
#define CONTENT_DESLOCATION_COL 1
#define TITLE_SIZE 1

#include "helpers.h"
#include "bus.h"

typedef struct {
    Position startPosition,endPosition;
    int linPadding, colPadding;
    Position upScroll, downScroll;
    int scrollSize, scrollDeslocCol, scrollDeslocLin;
    char **nameList;
    int listLength;
    int currentItemIndex, maxItens;
    int scrollOffset;
    char title[100];
} ListBox;

void setTitle(ListBox *listBox,char *title);

ListBox newListBox(Position startPosition, Position endPosition, char **nameList, int listLength);

void changePadding(ListBox *listBox, int linPadding, int colPadding);

void changeScroll(ListBox *listBox, int scrollSize, int deslocationLin, int deslocationCol);

void drawScrollBar(ListBox *listBox);

void drawListBoxInterior(ListBox *listBox, int r, int g, int b);

void drawListBox(ListBox *listBox, int r,int g, int b);

void listBoxScroll(ListBox *listBox, char up);

void fillListBox(ListBox *listBox);

void detectMouseClick(ListBox *listBox, int lin, int col);

#endif // LIST_BOX_H
