
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
      POINT();  //Standard constructor, usage may not be required!
      POINT(double X, double Y); //Initialization constructor
      POINT(POINT &); //Copy constructor
      double distanceTo(const POINT &);  //Distance between two POINT objects
      double getX();
      double getY();

      //We had to adapt the get methods because of const correctness, otherwise we wouldn't be able to access the get methods within the distanceTo method, for example
      double getXconst() const;
      double getYconst() const;

      POINT & operator = (const POINT &); // Overloaded assignment operator
      POINT & operator + (const POINT &); // Overloaded addition operator
      POINT & operator - (const POINT &); // Overloaded subtraction operator
      POINT & operator * (double );  // Overloaded multiplication operator, POINT * scalar
      virtual void show(); // Output of the coordinates in the form (x | y)
      virtual ~POINT(); // Virtual destructor, is called automatically by the destructors of LINE and CIRCLE

};  //End of the class POINT

class LINE : private POINT{
   private:
      POINT * P2;   //pointer auf zweites POINT-Objekt für die Gerade
      double A,B,C; //Values for the parametric representation of the straight line
      void normalize(void); //Normalization according to Euclid, used in the constructor, can be omitted
   public :
      LINE (POINT *P1, POINT *P2); //Initialisierungskonstruktor
      POINT * meets (const LINE *L);  //Schnittpunkt für zwei Geraden
      bool parallelTo(const LINE *L); //Determine if two lines are parallel
      void show(); //Overridden method show: Output of the coordinates in the form (x1 | y1), (x2 | y2)
      ~LINE();

}; //class LINE

class CIRCLE : private POINT{
   private:
      double Radius;
      double skPro(POINT &, POINT &); //Auxiliary function to determine the scalar product of two vectors
   public:
      CIRCLE (POINT *M, double R); //Initialization of constructor 1
      CIRCLE (POINT *,POINT *,POINT *); //Initialization of constructor 2
      CIRCLE * createCircle(POINT *,POINT *,POINT *);
      POINT * getMiddle();
      void show(); //Overridden method show: Output of the center point and the radius
      bool isInCircle(const POINT &);
      void meetsOther(CIRCLE *C, int &Anzahl, POINT **S1, POINT **S2); //C is passed. number, S1 and S2 come back
      ~CIRCLE();
};  //class CIRCLE

#endif // MYCLASSES_H
