#include "mpc_c.h"
#include "listBox.h"
#include "helpers.h"
#include <stdio.h>
#include <string.h>

void drawListBox(ListBox *listBox, int r, int g, int b)
{

    drawListBoxInterior(listBox, r, g, b);
    drawScrollBar(listBox);
    fillListBox(listBox);
}

void drawListBoxInterior(ListBox *listBox, int r, int g, int b)
{
    int startX, endX, startY, endY, yPadding, xPaddingLeft, xPaddingRight;

    startX = colToX(listBox->startPosition.col);
    endX = colToX(listBox->endPosition.col);
    startY = linToY(listBox->startPosition.lin);
    endY = linToY(listBox->endPosition.lin);

    yPadding = linToY(listBox->linPadding);
    xPaddingLeft = colToX(listBox->colPadding);
    xPaddingRight = colToX(listBox->colPadding + listBox->scrollSize + listBox->scrollDeslocCol);

    clearScreen(listBox->startPosition, listBox->endPosition);
    mpcVLine(startX, startY, endY, r, g, b, 1);
    mpcVLine(endX, startY, endY, r, g, b, 1);
    mpcHLine(startY, startX, endX, r, g, b, 1);
    mpcHLine(endY, startX, endX, r, g, b, 1);

    mpcVLine(startX - xPaddingLeft, startY - yPadding, endY + yPadding, r, g, b, 1);
    mpcVLine(endX + xPaddingRight, startY - yPadding, endY + yPadding, r, g, b, 1);
    mpcHLine(startY - yPadding - TITLE_SIZE, startX - xPaddingLeft, endX + xPaddingRight, r, g, b, 1);
    mpcHLine(endY + yPadding, startX - xPaddingLeft, endX + xPaddingRight, r, g, b, 1);

    mostraTexto(listBox->startPosition.lin - TITLE_SIZE,
                 listBox->startPosition.col,
                  listBox->endPosition.col,listBox->title, WHITE,BLACK);
}

void drawScrollBar(ListBox *listBox)
{
    int i;
    for (i = 0; i < listBox->scrollSize; i++)
    {
        mpcSetChar(listBox->upScroll.lin, listBox->upScroll.col + i, '<', F_STD, WHITE, BLACK, 1);
        mpcSetChar(listBox->downScroll.lin, listBox->downScroll.col + i, '>', F_STD, WHITE, BLACK, 1);
    }
}

void detectMouseClickListBox(ListBox *listBox, int lin, int col)
{

    if (lin == listBox->upScroll.lin &&
        col >= listBox->upScroll.col && col <= listBox->upScroll.col + listBox->scrollSize)
    {
        listBoxScroll(listBox, 1);
    }
    else if (lin == listBox->downScroll.lin &&
             col >= listBox->downScroll.col && col <= listBox->downScroll.col + listBox->scrollSize)
    {
        listBoxScroll(listBox, 0);
    }
    else
    {
        int i;
        if (col >= listBox->startPosition.col &&
            col <= listBox->endPosition.col &&
            lin >= listBox->startPosition.lin + CONTENT_DESLOCATION_LIN &&
            lin <= listBox->endPosition.lin)
        {
            if(lin - (listBox->startPosition.lin + CONTENT_DESLOCATION_LIN) + listBox->scrollOffset < listBox->listLength)
                listBox->currentItemIndex =  lin - (listBox->startPosition.lin + CONTENT_DESLOCATION_LIN) + listBox->scrollOffset;
        }
    }
}

void listBoxScroll(ListBox *listBox, char up)
{
    if (up == 1)
    {
        if (listBox->scrollOffset > 0){
            listBox->scrollOffset--;
            if(listBox->currentItemIndex > listBox->scrollOffset + listBox->maxItens - 1 && listBox->currentItemIndex != -1){
                listBox->currentItemIndex = listBox->scrollOffset + listBox->maxItens - 1;
            }
        }
    }
    else
    {
        if (listBox->scrollOffset + listBox->maxItens < listBox->listLength){
            listBox->scrollOffset++;
            if(listBox->currentItemIndex <= listBox->scrollOffset && listBox->currentItemIndex != -1){
                listBox->currentItemIndex = listBox->scrollOffset;
            }
        }
    }
}

void fillListBox(ListBox *listBox)
{
    for (int i = 0; i < listBox->maxItens; i++)
    {

        if (listBox->currentItemIndex == i + listBox->scrollOffset)
        {
            mostraTexto(listBox->startPosition.lin + i + CONTENT_DESLOCATION_LIN, listBox->startPosition.col + CONTENT_DESLOCATION_COL,
                        OVERLAP, listBox->nameList[i + listBox->scrollOffset], WHITE, ORANGE_1);
        }
        else
        {
            mostraTexto(listBox->startPosition.lin + i + CONTENT_DESLOCATION_LIN, listBox->startPosition.col + CONTENT_DESLOCATION_COL,
                        listBox->endPosition.col, listBox->nameList[i + listBox->scrollOffset], WHITE, BLACK);
        }
    }
}

ListBox newListBox(Position startPosition, Position endPosition, char **nameList, int listLength)
{
    ListBox listBox;
    listBox.startPosition.col = startPosition.col;
    listBox.endPosition.col = endPosition.col;
    listBox.startPosition.lin = startPosition.lin;
    listBox.endPosition.lin = endPosition.lin;
    listBox.currentItemIndex = -1;
    listBox.scrollOffset = 0;
    listBox.maxItens = 0;
    setTitle(&listBox, " ");
    int i;
    for (i = 0; i < listLength; i++)
    {
        if (listBox.startPosition.lin + i + CONTENT_DESLOCATION_LIN >= listBox.endPosition.lin)
        {
            break;
        }
        listBox.maxItens++;
    }
    listBox.nameList = nameList;
    listBox.listLength = listLength;
    return listBox;
}

void changePadding(ListBox *listBox, int linPadding, int colPadding)
{
    listBox->linPadding = linPadding;
    listBox->colPadding = colPadding;
}

void changeScroll(ListBox *listBox, int scrollSize, int deslocationLin, int deslocationCol)
{
    Position upScroll = {listBox->startPosition.lin, listBox->endPosition.col + deslocationCol};
    Position downScroll = {listBox->endPosition.lin - deslocationLin,
                           listBox->endPosition.col + deslocationCol};

    listBox->upScroll = upScroll;
    listBox->downScroll = downScroll;
    listBox->scrollSize = scrollSize;
    listBox->scrollDeslocLin = deslocationLin;
    listBox->scrollDeslocCol = deslocationCol;
}

void setTitle(ListBox *listBox,char *title){
    strcpy(listBox->title, title);
}

