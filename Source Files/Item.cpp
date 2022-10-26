#include "Header Files/Item.h"

void Item::setPrice(double price) { Price = price; }
double Item::getPrice() { return Price; }
void Item::setShopPrice(double shopPrice) { ShopPrice = shopPrice; }
double Item::getShopPrice() { return ShopPrice; }
void Item::setQuantity(int quantity) { Quantity = quantity; }
int Item::getQuantity() { return Quantity; }  

void Item::readItemData(ifstream &fileItem)
{
    readObjectData(fileItem);

    string price, quantity;
    getline(fileItem, price);
    setPrice(atof(price.c_str()));
    getline(fileItem, quantity);
    setQuantity(atof(quantity.c_str()));
}

void Item::wantedItem()
{
    cout << "The customer wants to take " << getName() << endl;
}
int Item::checkQuantity()
{
    if (Quantity <= 0) return 0;
    else return 1;
}
void Item::noItem()
{
    cout << "We are really sorry, there is no more " << getName() << endl;
}
void Item::takeItem()
{
    cout << "\nThe customer took " << getName() << endl;
    Quantity--;
}
void Item::Description()
{
    cout << "Price: " << getPrice() << "$." << endl;
}
void Item::Restock(int quant)
{
    Quantity = Quantity + quant;
}
int Item::putItem(string itemCustomer)
{
    if (itemCustomer == getName()) 
    { 
        Quantity++; 
        return 1;
    }
    else return 0;
}
