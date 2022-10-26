#ifndef DRINK_H
#define DRINK_H

#include "Item.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class Drink : public Item
{
    private:
        double Volume;

    public:
        void setVolume(double volume);
        double getVolume();

        void readDrinkData(int i);

        void Description();
};

#endif