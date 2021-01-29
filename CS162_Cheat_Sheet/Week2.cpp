#include <iostream>
#include <cmath>
#include "Circle2.h"
#include "Point1.h"

using namespace std;

//Circle Class Implementation

//STATIC VARIABLE
    //Initializes static variable that for the getNumberOfObjects() function
    int Circle::numberOfObjects = 0;

//NO-ARG CONSTRUCTOR
    //Circle() is a "no-argument constructor".
    Circle::Circle() {
        radius = 1;
        x = 0;
        y = 0;
        numberOfObjects++;
    }

//CENTER RESET
    //Circle1 constructor that takes an argument to set the radius value.
    //Initializer list was used to initialize the constructors x and y values. "Point center" is initialized with coordinates (0, 0).
    Circle::Circle(double newRadius) : x(6), y(14)
    {
        radius = newRadius;
        double newX = 0;
        double newY = 0;
        center.setX(newX);
        center.setY(newY);
        numberOfObjects++;
    }


//OVERLOADED CONSTRUCTOR
    //Overloaded constructor that takes multiple arguments and sets all member variable values given specific parameters.
    Circle::Circle(double newRadius, double newX, double newY) {
        radius = newRadius;
        x = newX;
        y = newY;
        numberOfObjects++;
    }

//GET RADIUS
    //Function that fetches the circle objects radius and returns it.
    double Circle::getRadius() const {
        return radius;
    }

//GET AREA
    //Function that takes no arguments and calculates and returns the area of the "calling object" (circle).
    double Circle::getArea() const {
        return radius * radius * 3.14;
    }

//GET CIRCUMFERENCE
    //Function that takes no arguments and calculates and returns the circumference of the "calling object" (circle).
    double Circle::getCircumference() const {
        return 2 * radius * 3.14;
    }

//GET X
    //Fetches a circle object's current x coordinate.
    double Circle::getX() const {
        return x;
    }

//GET Y
    //Fetches a circle object's current y coordinate.
    double Circle::getY() const {
        return y;
    }

//SET RADIUS
    //Function that takes argument to set the radius of the "calling object" (circle).
    void Circle::setRadius(double newRadius) {
        radius = newRadius;
    }

//SET X
    //Sets the circle object's x coordinate.
    void Circle::setX(double newX) {
        x = newX;
    }

//SET Y
    //Sets the circle object's y coordinate.
    void Circle::setY(double newY) {
        y = newY;
    }

//SCALE
    //Increases (or decreases) the size of a circle object.
    void Circle::scale(double scaleFactor) {
        radius = radius * scaleFactor;
    }

//PASS BY REFERENCE - MOVE BY
    //Shifts a circle object's position on the Cartesian plane to a specified point.
    //Point parameter (p) is passed by reference.
    void Circle::moveBy(const Point& p) {
        x += p.getX();
        y += p.getY();
    }

//PRINT CIRCLE
    //Passes circle's radius by VALUE and prints the radius and area of the circle to the console.
    void printCircleVal(Circle c) {
        std::cout << "The area of the circle of " << c.getRadius() << " is " << c.getArea() << endl;
    }

//PASS BY REFERENCE - PRINT CIRCLE
    //Passes circle's radius by REFERENCE and prints the radius and area of the circle to the console.
    //In this instance of the printCircleConstRef function, the circle object is passed by REFERENCE. However, no changes will be made to the object. This is due to the "const" in front of the object parameter. So, you may be wondering, "Why not just pass by VALUE if we don't want to make changes to the object?" Good question. Remember, we want to be as efficient as possible. Passing by VALUE uses memory that we could be using for something else. with const REFERENCE, we get to save memory without having to worry about unintentionally changing the object.
    void printCircleConstRef(const Circle& c) {
        std::cout << "The area of the circle with a radius of " << c.getRadius() << " is " << c.getArea() << endl;
    }

//SCALE
    //Passes in a circle object and alters it's radius by whatever magnitude specified by the user. In this instance of the function, the circle object is passed by VALUE, which is not going to work the way we want.
    void scaleCircleVal(Circle c, double scaleFactor) {
        double newRadius = c.getRadius() * scaleFactor;
        c.setRadius(newRadius);
    }

//PASS BY REFERENCE - SCALE
    //In this instance of the scaleCircle function, the circle object is passed by REFERENCE which is kinda like using jumper cables to start another car instead of buying another battery. I think that kinda makes sense...
    void scaleCircleRef(Circle& c, double scaleFactor) {
        double newRadius = c.getRadius() * scaleFactor;
        c.setRadius(newRadius);
    }

//ARRAY OF OBJECTS
    //Function that prints an array of objects when called.
    void Circle::printCircleArray(Circle circleArray[], int size) {
        for(int i = 0; i < size; i++) {
            std::cout << "Circle" << i + 1 << " radius: " << circleArray[i].getRadius() << endl;
            std::cout << "Circle" << i + 1 << " area: " << circleArray[i].getArea() << endl;
            std::cout << "Circle" << i + 1 << " circumference: " << circleArray[i].getCircumference() << endl;
            std::cout << endl;
            numberOfObjects++;
        }
    }

//ADD ARRAY AREA
    //Function that adds up the total area of all objects in an array.
    double sum(Circle circleArray [], int size) {
        double total = 0;
        for (int i = 0; i < size; i++) {
            total = total + circleArray[i].getArea();
        }
        return total;
    }

//CIRCLE OUT OF AREA
    //Function that creates a circle object based on an area parameter.
    Circle Circle::makeCircleWithArea(double area) {
        double newRadius = sqrt(area / 3.14);
        Circle temp(newRadius); //Circle object made with calculated radius.
        numberOfObjects++;
        return temp;
    }

//NUMBER OF OBJECTS
    //Function that returns the total number of circle objects created.
    int Circle::getNumberOfObjects() {
        return numberOfObjects;
    }

//FETCHES CENTER COORDINATES
    //Fetches and returns (0, 0) point on cartesian plane.
    Point Circle::getCenter() const {
      return center;
    }



//Point Class Implementation

    //NO-ARG POINT CONSTRUCTOR
    Point::Point() {

    }

//POINT CONSTRUCTOR
    Point::Point(double startX, double startY) {
        x = startX;
        y = startY;
    }

//GET X
    double Point::getX() const {
        return x;
    }

//GET Y
    double Point::getY() const {
        return y;
    }

//SET X
    void Point::setX(double newX) {
        x = newX;
    }

//SET Y
    void Point::setY(double newY) {
        y = newY;
    }

//TRANSLATE - MOVE
    void Point::translate(double xShift, double yShift) {
        x += xShift;
        y += yShift;
    }

//IS SAME AS
    bool Point::isSameAs(const Point& other) const {
        const double EPSILON = 0.0000001;
            if( (abs(x - other.x) < EPSILON) &&
                (abs(y - other.y) < EPSILON) )
                return true;
            else
                return false;
    }

//DISTANCE TO
    double Point::distanceTo(const Point& other) const {
        double xDiff = x - other.x;
        double yDiff = y - other.y;
        return sqrt( pow(xDiff, 2) + pow(yDiff, 2) );
    }

//PRINT LOCATION
    void Point::print() const {
        std::cout << "Point at (" << x << "," << y << ")" << endl;
    }

//WEEK-2 EXECUTION

    void executeWeekTwo() {

        std::cout << endl;
        std::cout << "Week 2" << endl;
        std::cout << "Circle class computations:" << endl;
        std::cout << endl;

//ARRAY OF OBJECTS
    //Declares an array of 10 circle objects.
    Circle circleArrayOne[10];
    std::cout << "circleArrayOne radiuses: ";
    for(int i = 0; i < 10; i++) {
        circleArrayOne[i].setRadius(i * 10);
        std::cout << circleArrayOne[i].getRadius() << " ";
    }

    std::cout << endl;
    std::cout << endl;

//THREE CIRCLE ARRAY
    //Declares and initializes 3 circle in an array of objects (circleArrayTwo).
    Circle circleArrayTwo[3] = {Circle(), Circle(4), Circle(5, 9, 13)};
    //Since not all of the values on the first 2 circles in the array are initialized, we'll do it now.
    circleArrayTwo[0].setX(21);
    circleArrayTwo[0].setY(-34);
    circleArrayTwo[1].setX(45.76);
    circleArrayTwo[1].setY(-3.333);
    //Prints radius, x and y for all 3 circle objects in the array.
    std::cout << "circleArrayTwo prints: " << endl;
    for(int i = 0; i < 3; i++) {
        std::cout << "Circle" << i + 1 << " radius = " << circleArrayTwo[i].getRadius() << endl;
        std::cout << "Circle" << i + 1 << " x-coordinate = " << circleArrayTwo[i].getX() << endl;
        std::cout << "Circle" << i + 1 << " y-coordinate = " << circleArrayTwo[i].getY() << endl;
        std::cout << endl;
    }

//CALLS PRINT ARRAY FUNCTION
    //Calls printCircleArray function to print the radius, area and circumference first 8 circle objects of circleArrayOne.
    std::cout << "circleArrayOne prints: " << endl;
    Circle c0;
    c0.printCircleArray(circleArrayOne, 8);

//PRINTS TOTAL AREA OF CIRCLES IN AN ARRAY/
    //Calls sum function to print the total area of all circle objects in circleArrayTwo.
    std::cout << "circleArrayTwo total area: " << sum(circleArrayTwo, 3) << endl;

    std::cout << endl;

//CONSTRUCTS CIRCLE WITH ONLY AREA PARAMETER.
    //Call makeCircleWithArea function that returns a new circle object (c1) derived from a given area parameter.
    Circle c1;
    c1.makeCircleWithArea(125);
    std::cout << "Circle c1 radius: " << c1.getRadius() << endl;
    std::cout << "Circle c1 area: " << c1.getArea() << endl;
    std::cout << "Circle c1 perimeter: " << c1.getCircumference() << endl;

    std::cout << endl;

//PASS BY VALUE - SCALE CIRCLE
    //Call scaleCircle function to increase or decrease a circle object's radius then print the results.
    //This first run of the scaleCircle function passes the circle object to the function by VALUE. This is not efficient. In addition, any changes to the circle object made within the function are not passed back to the circle object itself. Any changes the function makes disappear once it is done doing it's thing. To make changes to the object itself, we need to pass the circle object to the function by REFERENCE.
    std::cout << "Radius of Circle c1 (before pass by value): " << c1.getRadius() << endl;
    scaleCircleVal(c1, 25);
    std::cout << "Radius of Circle c1 (after pass by value): " << c1.getRadius() << endl;
    //Notice that the radius of c1 did not change after calling the scaleCircle function.

    std::cout << endl;

//PASS BY REFERENCE - SCALE CIRCLE
    //Now, well call the "same" function and pass the circle object to the function by REFERENCE and see what happens.
    scaleCircleRef(c1, 25);
    std::cout << "Radius of Circle c1 (after pass by reference): " << c1.getRadius() << endl;
    //Notice how this time, the radius of c1 did change. Not only does passing by reference do what we wanted the function to do, but it is also more efficient (read: saves memory).

    std::cout << endl;

//PASS BY REFERENCE
    //Circle c1 is passed by reference to this const function. Since it is const, no changes will be made to the object. However, c1 data can still be used with other getter functions called from within the printCircleConstRef function. Note: all functions called within a const function must also be const. This is why the functions in the "//BEHAVIORS - ACCESSOR FUNCTIONS" category in the "Week-2.h" header file are all const.
    printCircleConstRef(c1);

    std::cout << endl;

//GET NUMBER OF OBJECTS MADE
    //Prints out the number of circle objects by invoking the getNumberOfObjects() function. Note: because getNumberOfObjects() is a static method, you must use "Circle::" to access it.
    std::cout << "The number of circle objects created: " << Circle::getNumberOfObjects() << endl;

    std::cout << endl;

//PROCESSES AND PRINTS POINT VALUES
    //Creates a point object with initialized x and y arguments.
    Point p1 (-9, 19);
    //Prints the default position of circle object c0.
    std::cout << "c0 position on the Cartesian plane: (" << c0.getX() << ", " << c0.getY() << ")" << endl;
    //Function call moveby() moves the circle object c0 to the point in the function argument p1. Point p1 is passed by reference to the moveby() function. (p1) ------> Point& p. p1's x and y values are read into x and y with the p.getX and p.getX functions. The new x and y values are then passed back to the circle object c0 where it is stored in memory to be processed further.

//MOVES THE CIRCLE OBJECT TO THE SAME LOCATION AS THE POINT OBJECT SPECIFIED IN THE ARGUMENT
    c0.moveBy(p1);
    //Prints the new position of circle object c0.
    std::cout << "c0 position on the Cartesian plane: (" << c0.getX() << ", " << c0.getY() << ")" << endl;

    Point p2 (-23, -8);
    Point p3 (4, 32);

//CALCULATE DISTANCE BETWEEN TO POINT LOCATIONS
    //Prints the distance between two locations, p2 and p4.
    std::cout << "The distance from p2 to p4: " << p2.distanceTo(p3) << endl;

//CHANGES THE POSITION OF TWO CIRCLE OBJECTS
    //Changes the positions of both circle objects c0 and c1.
    c0.moveBy(p2);
    c1.moveBy(p3);

//TRUE OR FALSE
    //If statements testing boolean function (isSameAs) for true/false output by comparing points on a cartesean plane.
    if (p2.isSameAs(p2) == 1) {
        std::cout << "true" << endl;
    }
        else {
        std::cout << "false" << endl;
    }
    if (p2.isSameAs(p3) == 1) {
        std::cout << "true" << endl;
    }
        else {
        std::cout << "false" << endl;
    }

}

