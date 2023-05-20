#include "Solider.h"

Solider::Solider(std::string _name)
{
    this->name = _name;
    this->ptr_gun = nullptr;
}

void Solider::addGun(Gun *_ptr_gun)
{
    this->ptr_gun = _ptr_gun;
}

void Solider::addBulletToGun(int num)
{
    this->ptr_gun->addBullet(num);
}

bool Solider::fire()
{
    return this->ptr_gun->shoot();
}

Solider::~Solider()
{
    if (this->ptr_gun != nullptr)
    {
        this->ptr_gun = nullptr;
    }
}