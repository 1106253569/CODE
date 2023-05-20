#pragma once
#include <iostream>

class Gun
{
public:
    Gun(std::string _type) : type(_type), bullet_count(0) {}
    void addBullet(int bullet_num);
    bool shoot();

private:
    std::string type;
    int bullet_count;
};