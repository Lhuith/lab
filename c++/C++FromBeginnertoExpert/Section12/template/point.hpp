#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>

using namespace std;

template <typename T>
class Point // base, parent, super
{
protected: // externally locked, internally public
    T x;

public:
    Point(T = 0); // constructor with overload default constructor
    ~Point();
    T getX();
    void setX(T);
};

template <typename T>
Point<T>::Point(T x)
{
    this->x = x;
    cout << "the constructor from 1D class" << endl;
}

template <typename T>
Point<T>::~Point()
{
    cout << "the destructor from 1D class" << endl;
}

template <typename T>
T Point<T>::getX()
{
    cout << "this is from default method for getX()<T>" << endl;
    return this->x;
}

template <>
double Point<double>::getX()
{
    cout << "this is from specialized method for getX()<double>" << endl;
    return this->x;
}

template <typename T>
void Point<T>::setX(T x)
{
    this->x = x;
    cout << "I am from point1D" << endl;
}

template <typename K>
class Point<K *>
{
public:
    Point(K a = 0) { cout << "you cant use pointers here" << endl; }
};

template <typename T>
class Point2D : public Point<T> // derived, child, subclass
{
protected:
    T y;

public:
    Point2D(T = 0, T = 0);
    ~Point2D();
    T getY() { return y; }
    void setY(T);
    void setX(T);
    void setXY(T, T);
    Point2D operator+(Point2D);
};

template <typename T>
Point2D<T>::Point2D(T x, T y) : Point<T>(x)
{
    this->y = y;
    cout << "the constructor from 2D class" << endl;
}

template <typename T>
Point2D<T>::~Point2D()
{
    cout << "the destructor from 2D class" << endl;
}

template <typename T>
void Point2D<T>::setY(T y)
{
    this->y = y;
}

template <typename T>
void Point2D<T>::setXY(T x, T y)
{
    this->setX(x);
    this->setY(y);
}

template <typename T>
void Point2D<T>::setX(T x)
{
    this->x = x;
    cout << "I am from point2D" << endl;
}

template <typename T>
Point2D<T> Point2D<T>::operator+(Point2D o)
{
    Point2D<T> tmp;

    tmp.setX(this->getX() + o.getX());
    tmp.setY(this->getY() + o.getY());

    return tmp;
}

template <>
class Point<char>
{
public:
    Point(char a = 0)
    {
        cout << "this is from Point <char>" << endl;
    };
};

// class Point3D : public Point2D // derived, child, subclass
// {
// protected:
//     int z;
// };

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