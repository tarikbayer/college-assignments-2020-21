
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

        //If 1 entered the user was allowed to create 2 circles
        if(auswahl == 1){
            cout << endl << "Bitte Mittelpunkt (x|y) und den Radius von Kreis 1 eingeben: " << endl;
            cout << "x: ";
            cin >> Mx1;
            cout << "y: ";
            cin >> My1;
            cout << "R: ";
            cin >> R1;

            //Create circle 1 using the center point and radius and then output it on the screen
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

            //Create circle 2 using the center point and radius and then output it on the screen
            P2 = new POINT(Mx2, My2);
            c2 = new CIRCLE(P2, R2);

            c2->show();

            //cout << endl << "Distance between the centers:" << P1->distanceTo(*P2) << endl;

            //Using the meetsOther method, check whether the circles intersect, touch or not touch
            c1->meetsOther(c2, anzahl, &P3, &P4);

            //The variable number determines what is communicated to the user
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
        //If the 2 entered, the user was allowed to enter 6 coordinates for 3 points
        //Step 1: Reading in the coordinates of points A, B & C
        else if(auswahl == 2){
            //1st circle
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

            //Step 2: Back to the menu if 2 or more items are the same
            if(A1->distanceTo(*B1) == 0 || A1->distanceTo(*C1) == 0 || B1->distanceTo(*C1) == 0 || A2->distanceTo(*B2) == 0 || A2->distanceTo(*C2) == 0 || B2->distanceTo(*C2) == 0){
                cout << endl << "2 oder mehr der eingebenen Punkte sing gleich!" << endl << endl;

            }
            //Otherwise continue with the program
            else{
                cA = cA->createCircle(A1, B1, C1);
                cB = cB->createCircle(A2, B2, C2);

                //Using the meetsOther method, check whether the circles intersect, touch or not touch
                cA->meetsOther(cB, anzahl, &P3, &P4);

                //The variable number determines what is communicated to the user
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

        //Ask the user if the program should be run again (only the letter n terminates the program, all others run it again)
        cout << "Moechten Sie das Programm erneut ausfuehren? (y/n) ";
        cin >> nochmal;
        cout << endl;

    }while(nochmal != 'n');
    return 0;
}
