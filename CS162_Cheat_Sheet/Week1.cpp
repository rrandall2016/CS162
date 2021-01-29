#include <iostream>

#include "Circle1.h"

using namespace std;



//Circle1 Class Implementation

    //"Circle1::" precedes every constructor and function with the "binary scope resolution operator" (::), which lets the compiler know that these constructors and compilers are defined in the Circle1 class encapsulated in the .h file (Week-1.h). With this, you can declare and create a constructor (or function) anywhere that the .h file is #included as long as it is declared within the class. "That::This" = "That (is a part of) This"
    //Circle1() is a "no-argument constructor". The scope of "radius" spans the entire class.
    Circle1::Circle1() {
        radius = 1;
    }

    //Circle1 constructor that takes arguments. *Uses "goofy name trick" to copy parameter "newRadius" to "radius" variable. This is done to avoid "shadow variable" (i.e. does not change the member/class variable).
    Circle1::Circle1(double newRadius) {
        radius = newRadius;
    }

    //Function that takes no arguments and calculates and returns the area of the "calling object" (circle).
    double Circle1::getAreaNoArg() {
        return radius * radius * 3.14;
    }

    //Function that takes arguments and calculates and returns the area of the "calling object" (circle). *Uses "goofy name trick" to copy parameter "newRadius" to "radius" variable.This is done to avoid "shadow variable" (i.e. does not change the member/class variable).
    double Circle1::getAreaWithArg(double newRadius) {
        radius = newRadius;
        return radius * radius * 3.14;
    }

    //Function that takes no arguments and calculates and returns the circumference of the "calling object" (circle).
    double Circle1::getCircumferenceNoArg() {
        return 2 * radius * 3.14;
    }

    //Function that takes arguments and calculates and returns the circumference of the "calling object" (circle). *Uses "goofy name trick" to copy parameter "newRadius" to "radius" variable. This is done to avoid "shadow variable" (i.e. does not change the member/class variable).
    double Circle1::getCircumferenceWithArg(double newRadius) {
        radius = newRadius;
        return 2 * radius * 3.14;
    }

    //Function that takes argument to set the radius of the "calling object" (circle). *Uses "goofy name trick" to copy parameter "newRadius" to "radius" variable. This is done to avoid "shadow variable" (i.e. does not change the member/class variable).
    void Circle1::setRadius(double newRadius) {
        radius = newRadius;
    }



//Circle2 Class Implementation

    //Circle2() is a "no-argument constructor".
    Circle2::Circle2() {
        radius = 1;
        x = 0;
        y = 0;
    }

    //Circle2 constructor that takes an argument to set the radius value.
    //Initializer list was used to initialize the constructors x and y values.
    Circle2::Circle2(double newRadius) : x(2), y(4) {
        radius = newRadius;
    }

    //Overloaded constructor that takes multiple arguments and sets all member variable values given specific parameters.
    Circle2::Circle2(double newRadius, double newX, double newY) {
        radius = newRadius;
        x = newX;
        y = newY;
    }

    //Function that fetches the circle objects radius and returns it.
    double Circle2::getRadius() {
        return radius;
    }

    //Function that takes no arguments and calculates and returns the area of the "calling object" (circle).
    double Circle2::getArea() {
        return radius * radius * 3.14;
    }

    //Function that takes no arguments and calculates and returns the circumference of the "calling object" (circle).
    double Circle2::getCircumference() {
        return 2 * radius * 3.14;
    }

    //Fetches a circle object's current x coordinate.
    double Circle2::getX() {
        return x;
    }

    //Fetches a circle object's current y coordinate.
    double Circle2::getY() {
        return y;
    }

    //Function that takes argument to set the radius of the "calling object" (circle).
    void Circle2::setRadius(double newRadius) {
        radius = newRadius;
    }

    //Sets the circle object's x coordinate.
    void Circle2::setX(double newX) {
        x = newX;
    }

    //Sets the circle object's y coordinate.
    void Circle2::setY(double newY) {
        y = newY;
    }

    //Increases (or decreases) the size of a circle object
    void Circle2::scale(double scaleFactor) {
        radius = radius * scaleFactor;
    }

    //Shifts a circle object's position on the Cartesian plane
    void Circle2::moveBy(double deltaX, double deltaY) {
        x += deltaX;
        y += deltaY;
    }

//WEEK-1 EXECUTION

void executeWeekOne() {

    std::cout << endl;
    std::cout << "Week 1" << endl;
    std::cout << "Circle1 class computations:" << endl;
    std::cout << endl;

    //Creates an anonymous Circle1 object from the no argument constructor that initializes the radius to 1.
    Circle1();

    //Creates an anonymous Circle1 object from the constructor that initializes the radius to 7.
    Circle1(7);

    //Declaration that creates circle1 object by invoking Circle class's no-arg constructor (Circle1();).
    Circle1 circle1; //*Notice no () after "circle1".

    //Declaration that creates circle2 object by invoking Circle class and setting it to a specific radius (9.6).
    Circle1 circle2(9.6);

    //Prints the size (in bytes) of objects circle1 and circle2.
    std::cout << "circle1 size (in bytes) = " << sizeof (circle1) << endl;
    std::cout << "circle2 size (in bytes) = " << sizeof (circle2) << endl;

    //Copies all data fields from circle2 into circle1 then prints to console.
    circle2 = circle1;
    std::cout << "circle1 radius is " << circle1.radius << " and circle2 radius is also " << circle2.radius << endl;

    //Uses dot (.) operator to invoke setRadius function for circle1 and circle2, which then gets printed by cout.
    circle1.setRadius(6.6);
    circle2.setRadius(15.3);
    std::cout <<  "circle1 radius set to: " << circle1.radius << endl;
    std::cout <<  "circle2 radius set to: " << circle2.radius << endl;

    //Uses assignment (=) operator to set the radius for circle1 and circle2, which then gets printed by cout.
    circle1.radius = 9.46;
    circle2.radius = 5.2;
    std::cout <<  "circle1 radius set to: " << circle1.radius << endl;
    std::cout <<  "circle2 radius set to: " << circle2.radius << endl;

    //Uses dot (.) operator to invoke (no arg) getArea function for circle2, which then gets printed by cout. Does same for circle1, but with arguments.
    std::cout << "circle2 area = " << circle2.getAreaNoArg() << endl;
    std::cout << "circle1 area = " << circle1.getAreaWithArg(8.2) << endl;

    //Uses dot (.) operator to invoke getCircumference function (with argument for radius) for circle1, which then gets printed by cout. Does same for circle2, but with no arguments.
    std::cout << "circle1 circumference = " << circle1.getCircumferenceWithArg(24) << endl;
    std::cout << "circle2 circumference = " << circle2.getCircumferenceNoArg() << endl;

    std::cout << endl;

    std::cout << "Circle2 class computations:" << endl;
    std::cout << endl;

    //Creates an anonymous Circle2 object from the no argument constructor that initializes the radius to 1.
    Circle2();

    //Creates an anonymous Circle2 object from the constructor that initializes the radius to 7.
    Circle2(8);

    //Declaration that creates circle3 object by invoking Circle class's no-arg constructor (Circle1();).
    Circle2 circle3; //*Notice no () after "circle1".

    //Declaration that creates circle4 object by invoking Circle class and setting it to a specific radius (16.9).
    Circle2 circle4(16.9);

    //Prints out the radius of 3 circle objects, all with slightly different implementations.
    std::cout << "No arg circle radius is: " << Circle2().getRadius() << endl;
    std::cout << "Anonymous circle radius is: " << Circle2(45).getRadius() << endl;
    std::cout << "circle4 radius is: " << circle4.getRadius() << endl;

    //Declaration of circle5 object that sets the values of radius, x and y.
    Circle2 circle5(34.6, 17, 26.3);

    //Prints out circle5 position on Cartesian plane based on values fetched with getX and getY functions.
    std::cout << "circle5 position on the Cartesian plane: (" << circle5.getX() << ", " << circle5.getY() << ")" << endl;

    //Resets the x and y coordinates of circle5 and prints position on Cartesian plane.
    circle5.setX(47.6);
    circle5.setY(783.78);
    std::cout << "circle5 position on the Cartesian plane: (" << circle5.getX() << ", " << circle5.getY() << ")" << endl;

    //Fetches and prints out circumference and area of circle3 object.
    std::cout << "The circumference of circle3 is: " << circle3.getCircumference() << " and the area of circle3 is: " << circle3.getArea() << endl;

    //Scales up the radias by a factor of 10, then fetches and prints out circumference and area of circle3 object.
    circle3.scale(10);
    std::cout << "The circumference of circle3 is: " << circle3.getCircumference() << " and the area of circle3 is: " << circle3.getArea() << endl;

    //Sets circle4's x and y values, prints it's position on the Cartesian plane, moves it's position according to the moveBy() function arguments and then reprints it's position on the Cartesian plane.
    circle4.setX(34.81);
    circle4.setY(-52.57);
    std::cout << "circle4 position on the Cartesian plane: (" << circle4.getX() << ", " << circle4.getY() << ")" << endl;
    circle4.moveBy(21.5, 47.39);
    std::cout << "circle4 position on the Cartesian plane: (" << circle4.getX() << ", " << circle4.getY() << ")" << endl;

}
