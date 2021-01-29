#ifndef POINT1_H
#define POINT1_H

class Point {
public:

    //CONSTRUCTORS
    Point();
    Point(double startX, double startY);

    //BEHAVIORS - ACCESSOR FUNCTIONS
    double getX() const;
    double getY() const;

    //BEHAVIORS - MUTATOR FUNCTIONS
    void setX(double newX);
    void setY(double newY);
    void translate(double xShift, double yShift);

    bool isSameAs(const Point& other) const;
    double distanceTo(const Point& other) const;

    void print() const;

private:

    //STATE - PROPERTIES
    double x;
    double y;
};

#endif // POINT1_H
