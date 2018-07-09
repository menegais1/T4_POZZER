

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"
#include "bus.h"
#include "schedule.h"
#include "mpc_c.h"

Bus* initBusList(){
    Bus* busList = (Bus*) malloc(BUS_SIZE * sizeof(Bus));
    if(busList == NULL){
        printf("ERRO AO ALOCAR MEMORIA");
        return NULL;
    }
    int i;
    for(i=0;i<BUS_SIZE;i++){
        busList[i].exists = 0;
    }
    return busList;
}

Bus initBus(){
    Bus bus;
    bus.exists = 1;
    bus.schedules_length = 0;
    initScheduleList(bus.schedules);

    return bus;
}

int addPreExistentBus(Bus busList[], int *length){
    Bus bus = initBus();
    char str[50];
    sprintf(str,"Porto Alegre %d", *length);
    strcpy(bus.name,str);
    addPreExistentSchedules(bus.schedules, &bus.schedules_length);
    *length += 1;
    busList[*length - 1] = bus;
    return *length;
}

int writeFile(Bus busList[]){

    FILE* fileptr;

    fileptr = fopen("diskInfo.bin","wb");
    if(fileptr == NULL){
        printf("Não foi Possivel Carregar o arquivo do disco, as informacoes nao serao salvas");
        return 0;
    }

    fwrite(busList,sizeof(Bus),BUS_SIZE,fileptr);
    fclose(fileptr);


    return 1;


}

int readFile(Bus busList[], int* busLength){

    FILE* fileptr;

    fileptr = fopen("diskInfo.bin","rb");
    if(fileptr == NULL){
        return 0;
    }
    fread(busList,sizeof(Bus),BUS_SIZE,fileptr);
    fclose(fileptr);

    int i;
    for(i =0;i<BUS_SIZE;i++){
        if(busList[i].exists == 1){
            *busLength += 1;
        }
    }

    return 1;

}

void drawBusWindow(Bus *bus){

    printf("%s",bus->name);
}
