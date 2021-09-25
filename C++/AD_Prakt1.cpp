/* Dateiname: AD_Prakt1.cpp:
Enthält das Hauptprogramm laut Aufgabenstellung

AD-Praktikum SoSe 2021
Gruppe: 20
Schmidt, Nicole, Mat.-Nr.: 11148335
Bayer, Tarik, Mat.-Nr.: 11149643
Abgabe am: 27.5.21
Praktikumsblatt: 1.1
Compiler Flags: -
Linker libraries/options: -
*/
#include <iostream>
#include "Myclasses.h"

using namespace std;

int main()
{
    char nochmal = 'y';

    do{
        int auswahl, anzahl;
        double Mx1, My1, R1, Mx2, My2, R2;
        double A1x, A1y, B1x, B1y, C1x, C1y;
        double A2x, A2y, B2x, B2y, C2x, C2y;
        POINT *P1, *P2, *P3, *P4, *A1, *B1, *C1, *A2, *B2, *C2;
        //LINE *L1, *L2;
        CIRCLE *c1, *c2, *cA, *cB;

        cout << "Moechten Sie:" << endl;
        cout << "1) Zwei Kreise je mit Mittelpunkt und Radius erstellen" << endl;
        cout << "2) Zwei Kreise mit Hilfe von je 3 Punkten erstellen" << endl;
        cin >> auswahl;

        //Falls die 1 eingeben wurde den Nutzer 2 Kreise erstellen lassen
        if(auswahl == 1){
            cout << endl << "Bitte Mittelpunkt (x|y) und den Radius von Kreis 1 eingeben: " << endl;
            cout << "x: ";
            cin >> Mx1;
            cout << "y: ";
            cin >> My1;
            cout << "R: ";
            cin >> R1;

            //Kreis 1 mithilfe des Mittelpunkts und Radius erstellen und anschließen auf den Bildschirm ausgeben
            P1 = new POINT(Mx1, My1);
            c1 = new CIRCLE(P1, R1);

            c1->show();

            cout << endl << "Bitte Mittelpunkt (x|y) und den Radius von Kreis 2 eingeben: " << endl;
            cout << "x: ";
            cin >> Mx2;
            cout << "y: ";
            cin >> My2;
            cout << "R: ";
            cin >> R2;

            //Kreis 2 mithilfe des Mittelpunkts und Radius erstellen und anschließen auf den Bildschirm ausgeben
            P2 = new POINT(Mx2, My2);
            c2 = new CIRCLE(P2, R2);

            c2->show();

            //cout << endl << "Abstand der Mittelpunkte: " << P1->distanceTo(*P2) << endl;

            //Mithilfe der Methode meetsOther prüfen ob die Kreise sich schneiden, berühren oder nicht berühren
            c1->meetsOther(c2, anzahl, &P3, &P4);

            //Die Variable anzahl bestimmt was dem Nutzer mitgeteilt wird
            switch(anzahl){
                case 0 : cout << "Die Kreise beruehren sich nicht" << endl;
                         break;

                case 1 : cout << "Die Kreise beruehren sich im Punkt: ";
                         P3->show();
                         break;

                case 2 : cout << "Die Kreise schneiden sich in den Punkten: " << endl;
                         P3->show();
                         P4->show();
                         break;

                default : cout << "Fehler: switch default" << endl;
                          break;
            }
        }
        //Falls die 2 eingeben wurde den Nutzer 6 Koordinaten für 3 Punkte eingeben lassen
        //Schritt 1: Einlesen der Koordinaten der Punkte A, B & C
        else if(auswahl == 2){
            //1. Kreis
            cout << endl << "1. Kreis: Bitte Koordinaten fuer Punkt A eingeben: " << endl;
            cout << "x: ";
            cin >> A1x;
            cout << "y: ";
            cin >> A1y;

            A1 = new POINT(A1x, A1y);

            cout << endl << "1. Kreis: Bitte Koordinaten fuer Punkt B eingeben: " << endl;
            cout << "x: ";
            cin >> B1x;
            cout << "y: ";
            cin >> B1y;

            B1 = new POINT(B1x, B1y);

            cout << endl << "1. Kreis: Bitte Koordinaten fuer Punkt C eingeben: " << endl;
            cout << "x: ";
            cin >> C1x;
            cout << "y: ";
            cin >> C1y;

            C1 = new POINT(C1x, C1y);

            //2. Kreis
            cout << endl << "2. Kreis: Bitte Koordinaten fuer Punkt A eingeben: " << endl;
            cout << "x: ";
            cin >> A2x;
            cout << "y: ";
            cin >> A2y;

            A2 = new POINT(A2x, A2y);

            cout << endl << "2. Kreis: Bitte Koordinaten fuer Punkt B eingeben: " << endl;
            cout << "x: ";
            cin >> B2x;
            cout << "y: ";
            cin >> B2y;

            B2 = new POINT(B2x, B2y);

            cout << endl << "2 Kreis: Bitte Koordinaten fuer Punkt C eingeben: " << endl;
            cout << "x: ";
            cin >> C2x;
            cout << "y: ";
            cin >> C2y;

            C2 = new POINT(C2x, C2y);

            //Schritt 2: Zurück ins Menü, wenn 2 oder mehr Punkte gleich sind
            if(A1->distanceTo(*B1) == 0 || A1->distanceTo(*C1) == 0 || B1->distanceTo(*C1) == 0 || A2->distanceTo(*B2) == 0 || A2->distanceTo(*C2) == 0 || B2->distanceTo(*C2) == 0){
                cout << endl << "2 oder mehr der eingebenen Punkte sing gleich!" << endl << endl;

            }
            //Ansonsten mit dem Programm fortfahren
            else{
                cA = cA->createCircle(A1, B1, C1);
                cB = cB->createCircle(A2, B2, C2);

                //Mithilfe der Methode meetsOther prüfen ob die Kreise sich schneiden, berühren oder nicht berühren
                cA->meetsOther(cB, anzahl, &P3, &P4);

                //Die Variable anzahl bestimmt was dem Nutzer mitgeteilt wird
                switch(anzahl){
                    case 0 : cout << "Die Kreise beruehren sich nicht" << endl;
                             break;

                    case 1 : cout << "Die Kreise beruehren sich im Punkt: ";
                             P3->show();
                             break;

                    case 2 : cout << "Die Kreise schneiden sich in den Punkten: " << endl;
                             P3->show();
                             P4->show();
                             break;

                    default : cout << "Fehler: switch default" << endl;
                              break;
                }
            }

        }

        //Den Nutzer fragen ob das Programm erneut ausgeführt werden soll (nur der Buchstabe n beendet das Programm, alle anderen führen es erneut aus)
        cout << "Moechten Sie das Programm erneut ausfuehren? (y/n) ";
        cin >> nochmal;
        cout << endl;

    }while(nochmal != 'n');
    return 0;
}
