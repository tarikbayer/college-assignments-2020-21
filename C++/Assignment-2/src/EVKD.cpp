
#include "EVKD.h"
#include <string.h>
#include <iostream>

EVKD::EVKD(){}

//Constructor
EVKD::EVKD(char * LPSZDaten, EVKD * N){
    //Delete '\ 0' from the char array
    Anz = strlen(LPSZDaten);
    Daten = new char[Anz];
    for(int i = 0; i < Anz; i++){
        Daten[i] = LPSZDaten[i];
    }
    Next = N;
}

//Return data and append '\ 0' using the length of the array
char * EVKD::getDaten() const{
    char * help;
    help = Daten;
    int len = strlen(help);
    help[len] = '\0';
    return help;
}

//Return next list item
EVKD * EVKD::getNext(){
    return Next;
}

//Set next list element
void EVKD::setNext(EVKD * N){
    this->Next = N;
}

//Overloaded> operator; Compare 2 strings using strcmp
bool EVKD::operator > (EVKD &e){

    char * S1 = this->getDaten();
    char * S2 = e.getDaten();

    return (strcmp(S1, S2) < 0);
}

//Overloaded == operator; again compare 2 strings using strcmp
bool EVKD::operator == (EVKD &e){

    char * S1 = this->getDaten();
    char * S2 = e.getDaten();

    return (strcmp(S1, S2) == 0);
}

EVKD::~EVKD(){
    delete Daten;
    delete Next;
}
