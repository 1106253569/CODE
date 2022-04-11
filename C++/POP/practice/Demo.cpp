#include <iostream>
#include <math.h>
class Point
{
    friend double distance2(Point lc, Point rc);

private:
    double x;
    double y;

public:
    Point()
    {
        double _x;
        double _y;
        std::cout << "please enter x: ";
        std::cin >> _x;
        std::cout << "please enter y: ";
        std::cin >> _y;
        x = _x;
        y = _y;
    }
    Point(double _x, double _y) : x(_x), y(_y) {}
    double getX() { return x; }
    double getY() { return y; }
};

double distance1(Point lc, Point rc)
{
    return sqrt(pow(lc.getX() - rc.getX(), 2) + pow(lc.getY() - rc.getY(), 2));
}

double distance2(Point lc, Point rc)
{
    return sqrt(pow(lc.x - rc.x, 2) + pow(lc.y - rc.y, 2));
}

int main()
{
    Point x1;
    Point x2;
    std::cout << "This is normal functions's result: " << distance1(x1, x2) << '\n';
    std::cout << "This is friend functions's result: " << distance2(x1, x2) << '\n';
    return 0;
}
