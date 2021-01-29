#ifndef CIRCLE2_H
#define CIRCLE2_H

#include "Point1.h"

class Circle {
public:

    //CONSTRUCTORS
    Circle();
    Circle(double newRadius);
    Circle(double newRadius, double newX, double newY);

    Circle makeCircleWithArea(double area);

    void printCircleArray(Circle circleArray[], int size);

    //BEHAVIORS - ACCESSOR FUNCTIONS
    double getRadius() const;
    double getArea() const;
    double getCircumference() const;
    double getX() const;
    double getY() const;
    Point getCenter() const;

    static int getNumberOfObjects();

    //BEHAVIORS - MUTATOR FUNCTIONS
    void setRadius(double newRadius);
    void setX(double newX);
    void setY(double newY);
    void scale(double scaleFactor);
    void moveBy(const Point& p);

//    bool contains(const Point& p);

private:

    //STATE - PROPERTIES
    double radius;
    double x;
    double y;
    Point center;

    static int numberOfObjects;
};

void printCircleVal(Circle c);

void printCircleConstRef(const Circle& c);

void scaleCircleVal(Circle c, double scaleFactor);

void scaleCircleRef( Circle& c, double scaleFactor);

double sum(Circle circleArray [], int size);

//Function that runs all Week-2 code.
void executeWeekTwo();

#endif // CIRCLE2_H
