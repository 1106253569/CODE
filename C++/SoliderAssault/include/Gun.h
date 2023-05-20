#pragma once
#include <iostream>

class Gun
{
public:
    Gun(std::string type) : _type(type), _bullet_count(0) {}
    void addBullet(int bullet_num);
    bool shoot();

private:
    int _bullet_count;
    std::string _type;
};