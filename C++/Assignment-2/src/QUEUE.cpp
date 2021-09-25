/* Dateiname: QUEUE.cpp:
Enthält das Hauptprogramm laut Aufgabenstellung

AD-Praktikum SoSe 2021
Gruppe: 20
Schmidt, Nicole, Mat.-Nr.: 11148335
Bayer, Tarik, Mat.-Nr.: 11149643
Abgabe am: 21.6.21
Praktikumsblatt: 2.1
Compiler Flags: -
Linker libraries/options: -
*/
#include "QUEUE.h"
#include <iostream>
using namespace std;

//Konstruktor
QUEUE::QUEUE(){
    Enter = nullptr;
    Anz = 0;
}

void QUEUE::queueIn(char * InText){
    //Neues Listenelement erstellen
    EVKD * E = new EVKD(InText, nullptr);
    EVKD * temp = Enter;

    //Prüfen ob Elemente in der Liste vorhanden sind
    if(temp != nullptr){
        //Zum Ender der Liste gehen
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
        }
        //Das vorherige letzte Element auf das neue Element zeigen lassen
        temp->setNext(E);
    }
    //Ansosnten neues Element als Anfang setzen
    else{
        Enter = E;
    }
    Anz++;
}

char * QUEUE::queueOut(){
    //Nichts tun falls die Queue leer ist
    if(Anz == 0) return NULL;
    else{
        Anz--;
        //Das erste Element der Queue in einer Hilfsvariablen abspeichern
        EVKD * help = Enter;
        //Enter pointer auf das Element an nächster Stelle der Queue setzen
        Enter = help->getNext();
        //Das alte erste Element zurückgeben
        return help->getDaten();
    }
}

void QUEUE::einfuegeSortiert(EVKD * In, int Max){
    EVKD * help;

    //Überprüfen ob der Pointer auf den sortierten Listenanfang = null ist, oder ob In an den sortierten Listenanfang gehört
    if(sorted == NULL || *In > *sorted || *In == *sorted){
        In->setNext(sorted);
        sorted = In;
    }
    //Ansonsten vom Anfang die Liste durchlaufen und so In an der richtigen Stelle einfügen
    else{
        help = sorted;

        //Liste durchlaufen, bis In größer ist oder das Ende der Liste erreicht wurde
        while(help->getNext() != NULL && *help->getNext() > *In){
            help = help->getNext();
        }
        //In einsetzen
        In->setNext(help->getNext());
        help->setNext(In);
    }
}

void QUEUE::iSort(){
    EVKD * current = Enter;
    sorted = NULL;
    int i = 0;

    //Warteschlange bis zum Ende durchlaufen
    while(current != NULL){
            EVKD * next = current->getNext();
            //Mithilfe der einfuegeSortiert Methode die richtige Stelle für das jetzige Element der Warteschlange finden
            einfuegeSortiert(current, ++i);
            //Weiter zum nächsten Element
            current = next;
    }
    //Nachdem alle Elemente sortiert wurden, Enter wieder auf das erste Element setzen
    Enter = sorted;
}

EVKD * QUEUE::loesche(int Pos){
    EVKD * help = Enter;
    EVKD * help2;

    //Überprüfen ob das zu löschende Element an erster Stelle ist
    if(Pos == 1){
        //Falls ja, dann Enter auf das Element an nächster Stelle setzen
        help2 = Enter;
        Enter = help->getNext();
        Anz--;
        //Das entfernte Element zurückliefern
        return help2;
    }
    else if(Pos > Anz); //do nothing

    //Ansonsten die Warteschlange mithilfe einer for-Schleife bis zu einer Stelle vor der übergebenen Position durchlaufen
    else{
        for(int i = 1; i < Pos-1; i++){
            help = help->getNext();
        }
        //Dann den Pointer auf das ünernächste Element setzen und so das Element an der gewünschten Position aus der verketten Liste nehmen
        EVKD * help2 = help->getNext();
        help->setNext(help2->getNext());
        Anz--;
        //Schließlich das entfernte Element zurückliefern
        return help2;
    }
}

//Methode zum Anzeigen der Liste
void QUEUE::zeigDich(){
    EVKD * help = Enter;
    //Spezialfall um die richtige Adresse des ersten Elements anzuzeigen
    cout << "Daten: " << help->getDaten() << " | Adresse: " << Enter << endl;

    //Den Rest der Liste bis ein Element einen nullptr besitzt durchlaufen
    while(help != NULL && help->getNext() != nullptr){
        //Das Element mit richtiger Adresse auf die Konsole ausgeben
        cout << "Daten: " << help->getNext()->getDaten() << " | Adresse: " << help->getNext() << endl;
        help = help->getNext();
    }
    //Be pretty
    cout << endl;
}

QUEUE::~QUEUE()
{
    //dtor
}
