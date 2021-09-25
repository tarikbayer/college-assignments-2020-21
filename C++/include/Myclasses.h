/* Dateiname: Myclasses.h:
Achtung: Signaturen dürfen nicht geändert werden!

AD-Praktikum SoSe 2021
Gruppe: 20
Schmidt, Nicole, Mat.-Nr.: 11148335
Bayer, Tarik, Mat.-Nr.: 11149643
Abgabe am: 27.5.21
Praktikumsblatt: 1.1
Compiler Flags: -
Linker libraries/options: -
*/
#ifndef MYCLASSES_H
#define MYCLASSES_H
//#define bugs
#define Epsilon 0.00001

using namespace std;

class POINT{
   private:
       double X;
       double Y;

   protected:
      void setX(double);
      void setY(double);

   public :
      POINT();  //Standardkonstruktor, Nutzung eventuell nicht erforderlich!
      POINT(double X, double Y); //Initialisierungskonstruktor
      POINT(POINT &); //Copy-Konstruktor
      double distanceTo(const POINT &);  // Abstand zweier POINT-Objekte

      double getX();
      double getY();

      //Wir mussten die get Methoden wegen const Correctness anpassen, da wir sonst nicht innerhalb zB der distanceTo Methode auf die get Methoden zugreifen konten
      double getXconst() const;
      double getYconst() const;

      POINT & operator = (const POINT &); // Überladener Zuweisungsoperator
      POINT & operator + (const POINT &); // Überladener Additionsoperator
      POINT & operator - (const POINT &); // Überladener Subtraktionsoperator
      POINT & operator * (double );  // Überladener Multiplikationsoperator, POINT * Skalar
      virtual void show(); // Ausgabe der Koordinaten in der Form ( x | y )
      virtual ~POINT(); // Virtueller Destruktor, wird automatisch aufgerufen durch die Destruktoren von LINE und CIRCLE

};  //Ende class POINT

class LINE : private POINT{
   private:
      POINT * P2;   //pointer auf zweites POINT-Objekt für die Gerade
      double A,B,C; //Werte für die Parameterdarstellung der  Geraden
      void normalize(void); //Normalisierung nach Euklid, Verwendung im Konstruktor, kann weggelassen werden
   public :
      LINE (POINT *P1, POINT *P2); //Initialisierungskonstruktor
      POINT * meets (const LINE *L);  //Schnittpunkt für zwei Geraden
      bool parallelTo(const LINE *L); //Feststellen, ob zwei Geraden parallel sind
      void show(); //Überschriebene Methode show: Ausgabe der Koordinaten in der Form ( x1 | y1 ), ( x2 | y2 )
      ~LINE();

}; //class LINE

class CIRCLE : private POINT{
   private:
      double Radius;
      double skPro(POINT &, POINT &); //Hilfsfunktion um das Skalarprodukt zweier Vektoren zu bestimmen
   public:
      CIRCLE (POINT *M, double R); //Initialisierungskonstruktor 1
      CIRCLE (POINT *,POINT *,POINT *); //Initialisierungskonstruktor 2
      CIRCLE * createCircle(POINT *,POINT *,POINT *);
      POINT * getMiddle();
      void show(); //Überschriebene Methode show: Ausgabe des Mittelpunktes und des Radius
      bool isInCircle(const POINT &);
      void meetsOther(CIRCLE *C, int &Anzahl, POINT **S1, POINT **S2); //C wird übergeben, Anzahl, S1 udn S2 kommen zurück
      ~CIRCLE();
};  //class CIRCLE

#endif // MYCLASSES_H
