#ifndef POINT2_H
#define POINT2_H

#include <string>

class Point2 {
public:

    //CONSTRUCTORS
    Point2();
    Point2(double startX, double startY);

    //BEHAVIORS - ACCESSOR FUNCTIONS
    double getX() const;
    double getY() const;

    //BEHAVIORS - MUTATOR FUNCTIONS
    void setX(double newX);
    void setY(double newY);
    void translate(double xShift, double yShift);

    bool isSameAs(const Point2& other) const;
    double distanceTo(const Point2& other) const;

    void print() const;

private:

    //STATE - PROPERTIES
    double x;
    double y;
};

#endif // POINT2_H
