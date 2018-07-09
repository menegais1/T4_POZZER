

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




