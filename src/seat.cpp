/*
    Roberto Menegais

    Arquivo que contém funções relacionadas aos assentos de um horário de um onibus especifico,
    implementa funções de reserva, remoção da reserva, listagem de assentos e informações do passageiro
    que reservou o assento, as funções usadas tem seu protótipos declarados no arquivo "seat.h",
    assim como a estrutura "seat"

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seat.h"
#include "helpers.h"


void initSeatList(Seat seatList[]){
    int i;
    for(i=0;i<SEATS_SIZE;i++){
        seatList[i].reserved = 0;
        seatList[i].age = 0;
        strcpy(seatList[i].name,"");
    }

}

