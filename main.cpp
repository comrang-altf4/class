#include <iostream>
#include <cmath>
using namespace std;
class baseMath
{
public:
    baseMath(){}
    bool isEven(int number)
    {
        return number%2==0? true:false;
    }
    int factorial(int n)
    {
        int res=1;
        while (n>0)
            res*=n--;
        return res;
    }
};
class advancedMath:public baseMath
{
public:
    advancedMath(){}
    double estimateEulerNumber(int loops)
    {
        double res=1;
        for (int i=1;i<=loops;i++)
            res+=double(1/double(factorial(i)));
        return res;
    }
};
class CenterPoint
{
private:
    int x;
    int y;
public:
    CenterPoint(){}
    CenterPoint(int x,int y)
    :x{x},y{y}{}
    void setter(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
    float compute_distance(CenterPoint cp)
    {
        return sqrt((this->x-cp.x)*(this->x-cp.x)+(this->y-cp.y)*(this->y-cp.y));
    }
};
class Shape
{
public:
    CenterPoint centerPoint;
    virtual float compute_area(){};
    virtual float compute_circumference(){};
    float compute_distance(Shape s2)
    {
        return this->centerPoint.compute_distance(s2.centerPoint);
    }
};
class Circle:public Shape
{
private:
    int radius;
public:
    Circle(){}
    Circle(CenterPoint centerPoint,int radius):radius{radius}
    {
        this->centerPoint=centerPoint;
    }
    float compute_area()
    {
        return 3.14*radius*radius;
    }
    float compute_circumference()
    {
        return 2*3.14*radius;
    }
};
class Square:public Shape
{
private:
    int side;
public:
    Square(){}
    Square(CenterPoint centerPoint,int side):side{side}
    {
        this->centerPoint=centerPoint;
    }
    float compute_area()
    {
        return side*side;
    }
    float compute_circumference()
    {
        return 4*side;
    }
};
class Rectangle:public Shape
{
private:
    int width;
    int height;
public:
    Rectangle(){}
    Rectangle(CenterPoint centerPoint,int width, int height):width{width},height{height}
    {
        this->centerPoint=centerPoint;
    }
    float compute_area()
    {
        return width*height;
    }
    float compute_circumference()
    {
        return 2*(width+height);
    }
};
int main()
{
    CenterPoint cp(1,1);
    CenterPoint cp1(5,10);
    Circle c(cp,3);
    Circle d(cp1,6);
    cout<<c.centerPoint.compute_distance(d.centerPoint)<<' '<<c.compute_circumference()<<' '<<c.compute_area();
    return 0;
}
