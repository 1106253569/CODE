#include "Gun.h"

void Gun::addBullet(int bullet_num)
{
    this->_bullet_count += bullet_num;
}

bool Gun::shoot()
{
    if(this->_bullet_count<=0)
    {
        std::cout << "There is no bullet!" << '\n';
        return false;
    }
    this->_bullet_count -= 1;
    return true;
}