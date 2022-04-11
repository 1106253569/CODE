#include <iostream>
class Rectangle
{
public:
    Rectangle() = default;
    Rectangle(int L,int W):length(L),width(W){}
    virtual ~Rectangle() = default;

private:

protected:
    int length;
    int width;
};

class Cuboid:public Rectangle
{
public:
    Cuboid() = default;
    Cuboid(int L,int W,int H):Rectangle(L,W),height(H){}
    ~Cuboid() = default;
    int volume() { return length * width * height; }

private:
    int height;
};

int main()
{
    Cuboid C1(10, 20, 30);
    printf("volume=%d", C1.volume());
    return 0;
}