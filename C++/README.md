Programming in C ++
01. Assignment-1
* In this internship, a program is to be developed in order to be able to determine the position of circles in relation to one another. The circles should be able to be specified by different possibilities, on the one hand by their center and a radius, on the other hand by construction from three points. Adhere to the following procedure: Design the classes POINT for points in the Cartesian plane, LINE to represent straight lines and CIRCLE for the representation of circles. POINT has the private attributes double X and double Y, an initialization constructor, a copy constructor, the "distanceTo" method for the distance between two points and the get and set methods for the attributes. 
* LINE inherits a point on the straight line from POINT, so it needs another as an attribute to determine the straight line. Again, use the initialization constructor with the initialization list for the attributes and the inherited class. CIRCLE also inherits from POINT, this should be the center of a circle object. The radius is required as a further attribute. Use the initialization constructor and the copy constructor using the initialization list! Create the "isInCircle" method to determine whether a point transferred in the parameter list lies within the circle and the "meetsOther" method, which returns the number of intersection points for another circle transferred in the parameter list (second parameter) and, if applicable, pointer to these intersections! Note that MeetsOther can also be used to cut circles that have different radii! Use the ones presented in the exercise
* Formulas, among other things, for determining the intersection points. Note that pointers are returned to the calling program to return the intersection points, i.e. the data type POINT * * must be used in the signature for the pointers of the intersection points in accordance with the rules for Call by Reference!

 Tasks
* Develop a program based on the classes POINT, LINE and CIRCLE with the following menu:
1.) Specify any two circles, each with a center point and radius, and make them intersect. Specify the ratio of the circles to each other and, if necessary, show the point of contact or intersection points.
2.) Construct two circles with the help of any three points and make them cut. Specify the ratio of the circles to each other and, if necessary, show the point of contact or intersection points.
9.) End of program
The construction of a circle with the help of three points is as follows:
For three points of the x-y plane read in from the keyboard with the help of the streams “cin” and “cout”, a circle is to be constructed, on the circumference of which these three points are located. Use the following template to construct circles:
1. Reading in the coordinates of points A, B, C and creating the POINT objects;
2. Message and return to the menu if two of the items are the same;
3. Construction of four auxiliary circles with the centers A, B, C in such a way that two neighboring circles intersect; (Choose the radii appropriately!)
4. Determination of the straight lines that are defined by the intersection points of the neighboring circles;
5. Abort if the straight lines are parallel;
6. Determination of the intersection of the straight lines as the center of the circle to be constructed;
7. Determination of the radius as the distance between the center and one of the points A, B or C and creating a CIRCLE object with it;
8. Output of the center and the radius of the constructed circle with cout!
Use the code in the files provided to create a Code :: Blocks project. The signatures of the specified methods may not be changed, you may create other methods (for example to determine intermediate results ...)
Use Code :: Blocks version 20.03 with the compiler gcc8.1.0 for Windows, unicode, 32 bit
