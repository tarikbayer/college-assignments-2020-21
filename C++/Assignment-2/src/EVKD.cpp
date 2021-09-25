/* Dateiname: EVKD.cpp:
Enth�lt das Hauptprogramm laut Aufgabenstellung

AD-Praktikum SoSe 2021
Gruppe: 20
Schmidt, Nicole, Mat.-Nr.: 11148335
Bayer, Tarik, Mat.-Nr.: 11149643
Abgabe am: 21.6.21
Praktikumsblatt: 2.1
Compiler Flags: -
Linker libraries/options: -
*/
#include "EVKD.h"
#include <string.h>
#include <iostream>

EVKD::EVKD(){}

//Konstruktor
EVKD::EVKD(char * LPSZDaten, EVKD * N){
    //'\0' aus dem char Array l�schen
    Anz = strlen(LPSZDaten);
    Daten = new char[Anz];
    for(int i = 0; i < Anz; i++){
        Daten[i] = LPSZDaten[i];
    }
    Next = N;
}

//Daten zur�ckgeben und '\0' mithilfe der L�nge des Arrays anh�ngen
char * EVKD::getDaten() const{
    char * help;
    help = Daten;
    int len = strlen(help);
    help[len] = '\0';
    return help;
}

//N�chstes Listenelement zur�ckgeben
EVKD * EVKD::getNext(){
    return Next;
}

//N�chstes Listenelement setzen
void EVKD::setNext(EVKD * N){
    this->Next = N;
}

//�berladener > Operator; 2 Strings vergleichen mithilfe von strcmp
bool EVKD::operator > (EVKD &e){

    char * S1 = this->getDaten();
    char * S2 = e.getDaten();

    return (strcmp(S1, S2) < 0);
}

//�berladener == Operator; wieder 2 Strings mithilfe von strcmp vergleichen
bool EVKD::operator == (EVKD &e){

    char * S1 = this->getDaten();
    char * S2 = e.getDaten();

    return (strcmp(S1, S2) == 0);
}

EVKD::~EVKD(){
    delete Daten;
    delete Next;
}
