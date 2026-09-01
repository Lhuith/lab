#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point // base, parent, super
{
protected: // externally locked, internally public
    int x;

public:
    Point(int = 0); // constructor with overload default constructor
    ~Point();
    int getX() { return x; }
    void setX(int);
};

class Point2D : public Point // derived, child, subclass
{
protected:
    int y;

public:
    Point2D(int = 0, int = 0);
    ~Point2D();
    int getY() { return y; }
    void setY(int);
    void setX(int);
    void setXY(int, int);
};

class Point3D : public Point2D // derived, child, subclass
{
protected:
    int z;
};

/*
    class Point2D : public Point
    everything what is inside Point2D (excluding con/destructors) will be in Point2D
    private - CANNOT ACCESS
    protected - protected
    public - public

    class Point2D : protected Point
    everything what is inside Point2D (excluding con/destructors) will be in Point2D
    private - CANNOT ACCESS
    protected - protected
    public - protected

      lass Point2D : protected Point
    everything what is inside Point2D (excluding con/destructors) will be in Point2D
    private - CANNOT ACCESS
    protected - private
    public - private
*/

#endif