#ifndef CIRCLE1_H
#define CIRCLE1_H

class Circle1 {
public:

    //STATE - PROPERTIES - variables

    //Public data field (radius) that can be accessed directly by objects of the Circle1 class
    double radius;

    //CONSTRUCTORS
    Circle1();
    Circle1(double newRadius);

    //BEHAVIORS - ACCESSOR ("getter") FUNCTIONS
    double getAreaNoArg();
    double getAreaWithArg(double newRadius);
    double getCircumferenceNoArg();
    double getCircumferenceWithArg(double newRadius);

    //BEHAVIORS - MUTATOR ("setter") FUNCTIONS
    void setRadius(double newRadius);
};


class Circle2 {
public:

    //CONSTRUCTORS
    Circle2();
    Circle2(double newRadius);
    Circle2(double newRadius, double newX, double newY);

    //BEHAVIORS - ACCESSOR FUNCTIONS
    double getRadius();
    double getArea();
    double getCircumference();
    double getX();
    double getY();

    //BEHAVIORS - MUTATOR FUNCTIONS
    void setRadius(double newRadius);
    void setX(double newX);
    void setY(double newY);
    void scale(double scaleFactor);
    void moveBy(double deltaX, double deltaY);

private:

    //STATE - PROPERTIES
    double radius;
    double x;
    double y;
};

//Function that runs all Week-1 code.
void executeWeekOne();

#endif // CIRCLE1_H
