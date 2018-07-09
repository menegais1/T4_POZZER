/*
    Roberto Menegais

    Arquivo que contém funções relacionadas aos horários de um onibus,
    implementa funções de criação, remoção e listagem de horário, as funções usadas
    tem seu protótipos declarados no arquivo "schedule.h", assim como a estrutura "schedule"

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"
#include "schedule.h"

void initScheduleList(Schedule scheduleList[]){

    int i;
    for(i=0;i<SCHEDULE_SIZE;i++){
        scheduleList[i].exists = 0;
    }

}

Schedule initSchedule(){
    Schedule schedule;
    schedule.exists = 1;
    initSeatList(schedule.seats);
    strcpy(schedule.hour, "");

    return schedule;
}

int addPreExistentSchedules(Schedule scheduleList[], int* length){
    char hour1[HOUR_SIZE] = "12:30";
    char hour2[HOUR_SIZE] = "14:45";
    char hour3[HOUR_SIZE] = "22:00";

    Schedule schedule = initSchedule();
    strcpy(schedule.hour, hour1);
    *length += 1;
    scheduleList[*length - 1] = schedule;

    schedule = initSchedule();
    strcpy(schedule.hour, hour2);
    *length += 1;
    scheduleList[*length - 1] = schedule;

    schedule = initSchedule();
    strcpy(schedule.hour, hour3);
    *length += 1;
    scheduleList[*length - 1] = schedule;

    return *length;
}


