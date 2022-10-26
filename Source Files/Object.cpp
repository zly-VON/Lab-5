#include "Header Files/Object.h"

void Object::setName(string name) { Name = name; }
string Object::getName() { return Name; }
void Object::setDate(string date) { Date = date; }
string Object::getDate() { return Date; }

void Object::readObjectData(ifstream &file)
{
    string name, date;
    getline(file, name);
    setName(name);
    getline(file, date);
    setDate(date);
}
