#pragma once
#include <iostream>
#include "Gun.h"

class Solider
{
public:
    Solider(std::string _name);
    void addGun(Gun *_ptr_gun);
    void addBulletToGun(int num);
    bool fire();
    ~Solider();

private:
    std::string name;
    Gun *ptr_gun;
};