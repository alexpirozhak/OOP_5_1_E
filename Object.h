#pragma once
#include <iostream>

class Object
{
private:
    static int counter;
public:
    Object();
    ~Object();
    static int getCounter();
};
