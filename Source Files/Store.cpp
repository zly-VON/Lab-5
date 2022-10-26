#include "Header Files/Store.h"

void Store::setOutcome(double outcome) { Outcome = outcome; }
double Store::getOutcome() { return Outcome; }
void Store::setIncome(double income) { Income = income; }
double Store::getIncome() { return Income; }
void Store::setBoughtItems(int boughtItems) { BoughtItems = boughtItems; }
int Store::getBoughtItems() { return BoughtItems; }
void Store::setSoldItems(int soldItems) { SoldItems = soldItems; }
int Store::getSoldItems() { return SoldItems; }
void Store::setStolenItems(int stolenItems) { StolenItems = stolenItems; }
int Store::getStolenItems() { return StolenItems; }

void Store::Welcome()
{
    cout << "Hello. Welcome at " << getName() << endl;
}
void Store::goMainStore(string name)
{
    cout << name << " is in the Main Section.\n" << endl;
}
void Store::goFishmonger(string name)
{
    cout << name << " is going to the fishmonger.\n" << endl;
}
void Store::goButcher(string name)
{
    cout << name << " is going to the butcher.\n" << endl;
}
void Store::goDrinkSection(string name)
{
    cout << name << " is going to the Beverage Section.\n" << endl;
}
void Store::goVendingMachine(string name)
{
    cout << name << " is going to the Vending Machine.\n" << endl;
}
void Store::goCashier(string name)
{
    cout << name << " is going to the cashier.\n" << endl;
}
void Store::leaveStore(string name)
{
    cout << endl;
    cout << name << " goes out of the store.\n" << endl;
}
void Store::addOutcome(double price, int quantity)
{
    Outcome += price * quantity;
}
void Store::addIncome(double price)
{
    Income += price;
}
