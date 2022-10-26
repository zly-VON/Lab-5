#ifndef STORE_H
#define STORE_H

#include "Object.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;


class Store : public Object
{
    private:
        double Outcome;
        double Income;
        int BoughtItems;
        int SoldItems;
        int StolenItems;

    public:
        void setOutcome(double outcome);
        double getOutcome();
        void setIncome(double income);
        double getIncome();
        void setBoughtItems(int boughtItems);
        int getBoughtItems();
        void setSoldItems(int soldItems);
        int getSoldItems();
        void setStolenItems(int stolenItems);
        int getStolenItems();

        void Welcome();
        void goMainStore(string name);
        void goFishmonger(string name);
        void goButcher(string name);
        void goDrinkSection(string name);
        void goVendingMachine(string name);
        void goCashier(string name);
        void leaveStore(string name);
        void addOutcome(double price, int quantity);
        void addIncome(double price);
};

#endif