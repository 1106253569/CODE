#include "include/Gun.h"
#include "include/Solider.h"

int test()
{
    Solider solider01("XuSanDuo");
    Gun gun01("AK47");
    solider01.addGun(&gun01);
    gun01.addBullet(20);
    solider01.fire();
    return 0;
}

int main()
{
    test();
    return 0;
}