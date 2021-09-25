
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

//We had to adapt the get methods because of const correctness, otherwise we wouldn't be able to access the get methods within the distanceTo method, for example
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
    //Calculate the X coordinate of the intersection
    double Xs = (L->B * C - L->C * B) / (L->A * B - A * L->B);
    //Calculate variable Y of the intersection point
    double Ys = (L->C * A - L->A * C) / (A * L->B - L->A * B);
    //Declare the calculated coordinates as POINT and return them
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

    //Step 3: Construction of auxiliary circles with suitable radii
    if(P1->distanceTo(*P2) > P1->distanceTo(*P3)) abstand = P1->distanceTo(*P2);
    else abstand = P1->distanceTo(*P3);
    C1 = new CIRCLE(P1, abstand / 1.5);
    C2 = new CIRCLE(P2, abstand / 1.5);
    C3 = new CIRCLE(P3, abstand / 1.5);

    //Step 3.5: Determine the intersection of the auxiliary circles
    C1->meetsOther(C2, anzahl, &S1, &S2);
    C1->meetsOther(C3, anzahl, &S3, &S4);
    C2->meetsOther(C3, anzahl, &S5, &S6);

    //Step 4: Determination of the straight lines that run through the intersection points
    L1 = new LINE(S1, S2);
    L2 = new LINE(S3, S4);
    L3 = new LINE(S5, S6);

    //Step 5: Check whether the straight lines are parallel
    if(L1->parallelTo(L2) || L1->parallelTo(L3) || L2->parallelTo(L3)){
        DP = new POINT(0, 0);
        FC = new CIRCLE(DP, 0);
        cout << "Es konnte kein Kreis mit den eingegebenen Punkten erstellt werden!" << endl;
        return FC;
    }

    //Step 6 & 7: Determine the center point and radius and create a circle
    else{
        MP = new POINT(*L1->meets(L2));
        FC = new CIRCLE(MP, MP->distanceTo(*P1));

        //Step 8: output the center point and radius
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

        //Circles do not touch
        if (D > SR)
            Anzahl = 0;

        //Circles intersect
        else if(D < SR){
            Anzahl = 2;
            //Calculate point of intersection
            double S1x, S1y, S2x, S2y;

            S1x = POINT::getX() + (a/D) * Dx - (h/D) * Dy;
            S1y = POINT::getY() + (a/D) * Dy + (h/D) * Dx;

            S2x = POINT::getX() + (a/D) * Dx + (h/D) * Dy;
            S2y = POINT::getY() + (a/D) * Dy - (h/D) * Dx;

            *S1 = new POINT(S1x, S1y);
            *S2 = new POINT(S2x, S2y);
        }

        //Circles touch
        else{
            Anzahl = 1;
            //Calculate the point of contact
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
