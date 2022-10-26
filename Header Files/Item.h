#ifndef ITEM_H
#define ITEM_H

#include "Object.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class Item : public Object
{
    private:
        double Price;
        double ShopPrice;
        int Quantity;

    public:
        void setPrice(double price);
        double getPrice();
        void setShopPrice(double shopPrice);
        double getShopPrice();
        void setQuantity(int quantity);
        int getQuantity();

        void readItemData(ifstream &fileItem);

        void wantedItem();
        int checkQuantity();
        void noItem();
        void takeItem();
        void Description();
        void Restock(int quant);
        int putItem(string itemCustomer);
};

#endif