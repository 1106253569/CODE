#include "Gun.h"

void Gun::addBullet(int bullet_num)
{
    this->bullet_count += bullet_num;
}

bool Gun::shoot()
{
    if(this->bullet_count<=0)
    {
        std::cout << "There is no bullet!" << '\n';
        return false;
    }
    this->bullet_count -= 1;
    std::cout << "shoot successfully" << '\n';
    return true;
}