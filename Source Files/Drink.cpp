#include "Header Files/Drink.h"

void Drink::setVolume(double volume) { Volume = volume; }
double Drink::getVolume() { return Volume; }   

void Drink::readDrinkData(int i)
{
    ifstream fileDrink;
    fileDrink.open("Data List/drinkData.txt", ios::in);

    string ignore;
    int j = i * 5;
    while(j--) getline(fileDrink, ignore);
    
    readItemData(fileDrink);

    string volume;
    getline(fileDrink, volume);
    setVolume(atof(volume.c_str()));

    fileDrink.close();
}

void Drink::Description()
{
    cout << "Price: " << getVolume() << " L of " << getName();
    cout << " for " << getPrice() << "$." << endl;
}
