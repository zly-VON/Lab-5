#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "People.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class Customer : public People
{
    private:
        string Cheque;
        double Balance;
        double Sum;
        int NrItems;
        string Particularity;

    public:
        void setCheque(string cheque);
        string getCheque();
        void setBalance(double balance);
        double getBalance();
        void setSum(double sum);
        double getSum();
        void setNrItems(int nrItems);
        int getNrItems();
        void setParticularity(string particularity);
        string getParticularity();

        void readCustomerData(int i);

        void enterStore();
        void checkBalance();
        void addSum(double price);
        void payHotDrink(double price);
        double receiveDiscount();
        void Payment();
        void showCheque();
};

#endif