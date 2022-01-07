#include <iostream>
class Point
{
public:
    Point() = default;
    Point(double X,double Y):x(X),y(Y){}
    virtual ~Point()=default;
private:

protected:
    double x;
    double y;
};

class Circle:public Point
{
public:
    Circle() = default;
    Circle(double x,double y,double range):Point(x,y),r(range){}
    ~Circle() = default;
    double area() { return 3.14 * r * r; }

private:

protected:
    double r;
};

class Cylinder:public Circle
{
public:
    Cylinder() = default;
    Cylinder(double x,double y,double range,double H):Circle(x,y,range),Height(H){}
    ~Cylinder() = default;
    double Surface_area() { return 2 *area() + 2 * 3.14 * r * Height; }
    double volume() { return area() * Height; }

private:
    double Height;
};

int main()
{
    double x, y, r, h;
    printf("输入初始点坐标:");
    std::cin >> x >> y;
    printf("输入圆半径:");
    std::cin >> r;
    printf("输入圆柱高:");
    std::cin >> h;
    Circle C1(x, y, r);
    Cylinder C2(x, y, r, h);
    printf("圆的面积=%f\n", C1.area());
    printf("圆柱的表面积=%f\n圆柱的体积=%f", C2.Surface_area(), C2.volume());
    return 0;
}