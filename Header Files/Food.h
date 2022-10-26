#ifndef FOOD_H
#define FOOD_H

#include "Item.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class Food : public Item
{
    private:
        double Mass;

    public:
        void setMass(double mass);
        double getMass(); 

        void readFoodData(int i);
        
        void Description();
};

#endif
