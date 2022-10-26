#include "Header Files/People.h"

void People::setLastName(string lastName) { LastName = lastName; }
string People::getLastName() { return LastName; }
void People::setAge(int age) { Age = age; }
int People::getAge() { return Age; }

void People::readPeopleData(ifstream &filePeople)
{
    readObjectData(filePeople);

    string lastName, age;
    getline(filePeople, lastName);
    setLastName(lastName);
    getline(filePeople, age);
    setAge(atof(age.c_str()));
}

void People::Intro()
{
    cout << "Hi. I am " << getName() << endl;
}
