
#include <iostream>
#include <string>
#include "EVKD.h"
#include "QUEUE.h"

using namespace std;

int main()
{
    char nochmal = 'y';
    char * queueOut;
    string name, vorname;
    QUEUE * FIFO = new QUEUE();

    do{
        int auswahl;

        cout << "Moechten Sie:" << endl;
        cout << "1) Warteschlange erstellen" << endl;
        cout << "2) Verkette Liste anzeigen" << endl;
        cout << "3) Neues Element in Warteschlange einfuegen" << endl;
        cout << "4) Element aus der Warteschlange entfernen" << endl;
        cout << "5) Liste sortieren" << endl;
        cout << "12) Ende" << endl;
        cin >> auswahl;

        switch(auswahl){
            case 1 : {
                     char * Name[] = {"Schmitz, Josef","Mueller, Josi","Schmitz, Anna","Mueller, Josef","Schmitz, Josi","Mueller, Anna","Meier, Josef","Zacher, Josi","Anker, Anna"};
                     for(int i = 0; i < 9; i++){
                            //cout << Name[i] << endl;
                            FIFO->queueIn(Name[i]);
                     }
                     break;
                 }

            case 2 : FIFO->zeigDich(); break;

            case 3 : {
                     cout << endl << "Name: ";
                     cin >> name;
                     cout << "Vorname: ";
                     cin >> vorname;
                     name.append(", ");
                     name.append(vorname);
                     cout << endl << name << endl << endl;
                     char * fertigerName = &name[0];
                     FIFO->queueIn(fertigerName);
                     break;
            }

             case 4 : queueOut = FIFO->queueOut();
                      if(queueOut == NULL) cout << endl << "Die Warteschlange ist leer." << endl << endl;
                      else cout << endl << queueOut << endl << endl;
                      break;

             case 5 : FIFO->iSort(); break;

             case 12 : nochmal = 'n'; break;
        }

    }while(nochmal == 'y');

    return 0;
}
