

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mpc_c.h"
#include "helpers.h"


void mostraTexto(int l, int startCol, int endCol, char *msg,int rT,int gT,int bT,int rB, int gB,int bB)
{
   for (int cont = 0; cont < strlen(msg); cont++){
    if(startCol+cont < endCol){
        mpcSetChar(l, startCol + cont, msg[cont], F_STD, rT,gT,bT,rB,gB,bB, 1 );
    }else if(endCol == OVERLAP){
        mpcSetChar(l, startCol + cont, msg[cont], F_STD, rT,gT,bT,rB,gB,bB, 1 );
    }
}
}


int linToY(int lin){
    return lin * CHARACTER_HEIGHT;
}

int colToX(int col){
    return col * CHARACTER_WIDTH;
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


void clearScreen(Position startPosition, Position endPosition){
     int i, j;
    for (i = startPosition.lin; i <  endPosition.lin; i++)
    {
        for (j =  startPosition.col; j <  endPosition.col; j++)
        {
            mpcSetChar(i, j, ' ', F_STD, WHITE, TRANSP, 1);
        }
   }
}




