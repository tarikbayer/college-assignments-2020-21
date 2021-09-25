/* Dateiname: Myclasses.cpp:
Enthält den Code der Methoden der Klassen POINT, LINE und CIRCLE

AD-Praktikum SoSe 2021
Gruppe: 20
Schmidt, Nicole, Mat.-Nr.: 11148335
Bayer, Tarik, Mat.-Nr.: 11149643
Abgabe am: 27.5.21
Praktikumsblatt: 1.1
Compiler Flags: -
Linker libraries/options: -
*/
#include <math.h>
#include <iostream>
#include "Myclasses.h"

#define Epsilon 0.00001

using namespace std;

POINT::POINT(){
    this->X = 0;
    this->Y = 0;
}

POINT::POINT(double X, double Y):X(X), Y(Y){
    //this->X = X;
    //this->Y = Y;
}

//Copy-Konstruktor
POINT::POINT(POINT &p){
    X = p.getX();
    Y = p.getY();
}

double POINT::distanceTo(const POINT &p){
    if(&p) return sqrt(pow((X -  p.getXconst()),2) + pow((Y - p.getYconst()),2));
    else return -1;
}

double POINT::getX(){
    return X;
}

double POINT::getY(){
    return Y;
}

//Wir mussten die get Methoden wegen const Correctness anpassen, da wir sonst nicht innerhalb zB der distanceTo Methode auf die get Methoden zugreifen konten
double POINT::getXconst() const{
    return X;
}

double POINT::getYconst() const{
    return Y;
}

void POINT::setX(double X){
    this->X = X;
}

void POINT::setY(double Y){
    this->Y = Y;
}

POINT & POINT::operator = (const POINT &p){
    this->setX(p.getXconst());
    this->setY(p.getYconst());
}

POINT & POINT::operator + (const POINT &p){
    double a = X + p.getXconst();
    double b = Y + p.getYconst();
    POINT * erg = new POINT(a, b);
    return *erg;
}

POINT & POINT::operator - (const POINT &p){
    double a = X - p.getXconst();
    double b = Y - p.getYconst();
    POINT * erg = new POINT(a, b);
    return *erg;
}

POINT & POINT::operator * (double c){
    double a = X * c;
    double b = Y * c;
    POINT * erg = new POINT(a, b);
    return *erg;
}

void POINT::show(){
    cout << "( " << X << " | " << Y << " )" << endl;
}

POINT::~POINT(){
    this->X = 0;
    this->Y = 0;
}

LINE::LINE(POINT *P1, POINT *P2):POINT(*P1){
    this->P2 = P2;
    A = P1->getY() - P2->getY();
    B = P1->getX() - P2->getX();
    C = P1->getX() * P2->getY() - P2->getX() * P1->getY();
    //normalize();
}

void LINE::normalize(void){
    A = A / sqrt(A*A + B*B);
    B = B / sqrt(A*A + B*B);
    C = C / sqrt(A*A + B*B);
}

POINT * LINE::meets(const LINE *L){
    //Koordinate X des Schnittpunktes berechnen
    double Xs = (L->B * C - L->C * B) / (L->A * B - A * L->B);
    //Variable Y des Schnittpunktes berechnen
    double Ys = (L->C * A - L->A * C) / (A * L->B - L->A * B);
    //Die berechneten Koordinaten als POINT deklarieren und zurückgeben
    POINT * p = new POINT(Xs, Ys);
    return p;
}

bool LINE::parallelTo(const LINE *L){
    if(abs(L->A * B - A * L->B) < Epsilon)
        return true;
    else
        return false;
}

void LINE::show(){
    //cout << "( " << B + P2->getX() << " | " << A + P2->getY() << " ), ( " << P2->getX() << " | " << P2->getY() << " )" << endl;
    cout << "( " << POINT::getX() << " | " << POINT::getY() << " ), ( " << P2->getX() << " | " << P2->getY() << " )" << endl;
}

LINE::~LINE(){
    delete P2;
    A = 0;
    B = 0;
    C = 0;
    //POINT::~POINT();
}

CIRCLE::CIRCLE(POINT *M, double R):POINT(*M){
    this->Radius = R;
}

CIRCLE::CIRCLE(POINT *P1,POINT *P2,POINT *P3){

}

CIRCLE * CIRCLE::createCircle(POINT *P1,POINT *P2,POINT *P3){
    POINT *S1, *S2, *S3, *S4, *S5, *S6, *MP, *DP;
    CIRCLE *C1, *C2, *C3, *FC;
    LINE *L1, *L2, *L3;
    int anzahl;
    double abstand;

    //Schritt 3: Konstruktion von Hilfskreisen mit geeigneten Radien
    if(P1->distanceTo(*P2) > P1->distanceTo(*P3)) abstand = P1->distanceTo(*P2);
    else abstand = P1->distanceTo(*P3);
    C1 = new CIRCLE(P1, abstand / 1.5);
    C2 = new CIRCLE(P2, abstand / 1.5);
    C3 = new CIRCLE(P3, abstand / 1.5);

    //Schritt 3.5: Ermittlung der Schnittpunkte der Hilfskreise
    C1->meetsOther(C2, anzahl, &S1, &S2);
    C1->meetsOther(C3, anzahl, &S3, &S4);
    C2->meetsOther(C3, anzahl, &S5, &S6);

    //Schritt 4: Ermittlung der Geraden, welche durch die Schnittpunkte verlaufen
    L1 = new LINE(S1, S2);
    L2 = new LINE(S3, S4);
    L3 = new LINE(S5, S6);

    //Schritt 5: Überprüfen ob die Geraden parallel sind
    if(L1->parallelTo(L2) || L1->parallelTo(L3) || L2->parallelTo(L3)){
        DP = new POINT(0, 0);
        FC = new CIRCLE(DP, 0);
        cout << "Es konnte kein Kreis mit den eingegebenen Punkten erstellt werden!" << endl;
        return FC;
    }

    //Schritt 6 & 7: Mittelpunkt und Radius bestimmen und Kreis erstellen
    else{
        MP = new POINT(*L1->meets(L2));
        FC = new CIRCLE(MP, MP->distanceTo(*P1));

        //Schritt 8: Ausgabe des Mittelpunkts und Radius
        FC->show();

        return FC;
    }
}

double CIRCLE::skPro(POINT &P1, POINT &P2){
    return P1.getX() * P2.getX() + P1.getY() * P2.getY();
}

POINT * CIRCLE::getMiddle(){
    double a = POINT::getX();
    double b = POINT::getY();
    POINT * p = new POINT(a, b);
    return p;
}

bool CIRCLE::isInCircle(const POINT &p){
    if(POINT::distanceTo(p) <= Radius)
        return true;
    else
        return false;
}

void CIRCLE::meetsOther(CIRCLE *C, int &Anzahl, POINT **S1, POINT **S2){
    if((POINT::getX() == 0 && POINT::getY() == 0 && Radius == 0) || ((*C->getMiddle()).getX() == 0 && (*C->getMiddle()).getY() == 0 && C->Radius == 0)){}

    else{
        double D, SR, Dx, Dy, a, h;
        D = POINT::distanceTo(*C->getMiddle());
        SR = Radius + C->Radius;

        Dx = (*C->getMiddle()).getX() - POINT::getX();
        Dy = (*C->getMiddle()).getY() - POINT::getY();

        a = (Radius * Radius - C->Radius * C->Radius + D * D) / (2 * D);

        h = sqrt(Radius * Radius - a * a);

        //Kreise berühren sich nicht
        if (D > SR)
            Anzahl = 0;

        //Kreise schneiden sich
        else if(D < SR){
            Anzahl = 2;
            //Schnittpunkt berechnen
            double S1x, S1y, S2x, S2y;

            S1x = POINT::getX() + (a/D) * Dx - (h/D) * Dy;
            S1y = POINT::getY() + (a/D) * Dy + (h/D) * Dx;

            S2x = POINT::getX() + (a/D) * Dx + (h/D) * Dy;
            S2y = POINT::getY() + (a/D) * Dy - (h/D) * Dx;

            *S1 = new POINT(S1x, S1y);
            *S2 = new POINT(S2x, S2y);
        }

        //Kreise berühren sich
        else{
            Anzahl = 1;
            //Berührpunkt berechnen
            double S1x, S1y;

            S1x = POINT::getX() + (a/D) * Dx - (h/D) * Dy;
            S1y = POINT::getY() + (a/D) * Dy + (h/D) * Dx;

            *S1 = new POINT(S1x, S1y);
        }
    }
}

void CIRCLE::show(){
    POINT * p = new POINT(*this->getMiddle());
    cout << "M: ( " << p->getX() << " | " << p->getY() << " ), R: " << Radius << endl;
}

CIRCLE::~CIRCLE(){
    Radius = 0;
}
