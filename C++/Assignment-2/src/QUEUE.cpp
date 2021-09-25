
#include "QUEUE.h"
#include <iostream>
using namespace std;

//Constructor
QUEUE::QUEUE(){
    Enter = nullptr;
    Anz = 0;
}

void QUEUE::queueIn(char * InText){
    //Create new list item
    EVKD * E = new EVKD(InText, nullptr);
    EVKD * temp = Enter;

    //Check whether there are elements in the list
    if(temp != nullptr){
        //Go to the bottom of the list
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
        }
        //Let the previous last element point to the new element
        temp->setNext(E);
    }
    //Otherwise set a new element as the beginning
    else{
        Enter = E;
    }
    Anz++;
}

char * QUEUE::queueOut(){
    //Do nothing if the queue is empty
    if(Anz == 0) return NULL;
    else{
        Anz--;
        //Save the first element of the queue in an auxiliary variable
        EVKD * help = Enter;
        //Set the Enter pointer to the element at the next position in the queue
        Enter = help->getNext();
        //Return the old first item
        return help->getDaten();
    }
}

void QUEUE::einfuegeSortiert(EVKD * In, int Max){
    EVKD * help;

    //Check whether the pointer to the sorted beginning of the list = zero, or whether In belongs to the sorted beginning of the list
    if(sorted == NULL || *In > *sorted || *In == *sorted){
        In->setNext(sorted);
        sorted = In;
    }
    //Otherwise, go through the list from the beginning and insert In in the right place
    else{
        help = sorted;

        //Scroll through the list until In is greater or the end of the list has been reached
        while(help->getNext() != NULL && *help->getNext() > *In){
            help = help->getNext();
        }
        //Insert In
        In->setNext(help->getNext());
        help->setNext(In);
    }
}

void QUEUE::iSort(){
    EVKD * current = Enter;
    sorted = NULL;
    int i = 0;

    //Go through the queue to the end
    while(current != NULL){
            EVKD * next = current->getNext();
            //Use the einfuegeSortiert  method to find the right place for the current element of the queue
            einfuegeSortiert(current, ++i);
            //Move on to the next element
            current = next;
    }
    //After all elements have been sorted, put Enter back on the first element
    Enter = sorted;
}

EVKD * QUEUE::loesche(int Pos){
    EVKD * help = Enter;
    EVKD * help2;

    //Check whether the element to be deleted is in the first place
    if(Pos == 1){
        //If so, then set Enter on the element in the next position
        help2 = Enter;
        Enter = help->getNext();
        Anz--;
        //Return the removed item
        return help2;
    }
    else if(Pos > Anz); //do nothing

    //Otherwise, run through the queue using a for loop up to a point before the transferred position
    else{
        for(int i = 1; i < Pos-1; i++){
            help = help->getNext();
        }
        //Then set the pointer to the next element and remove the element from the linked list at the desired position
        EVKD * help2 = help->getNext();
        help->setNext(help2->getNext());
        Anz--;
        //Finally, return the removed item
        return help2;
    }
}

//Method of viewing the list
void QUEUE::zeigDich(){
    EVKD * help = Enter;
    //Special case to display the correct address of the first element
    cout << "Daten: " << help->getDaten() << " | Adresse: " << Enter << endl;

    //Iterate through the rest of the list until one element has a nullptr
    while(help != NULL && help->getNext() != nullptr){
        //Output the element with the correct address to the console
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
