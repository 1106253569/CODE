#include <iostream>

bool TestAndSet(bool* lock)
{
    bool old;
    old = *lock;
    *lock = true;
    return old;
}