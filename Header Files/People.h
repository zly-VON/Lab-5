#ifndef PEOPLE_H
#define PEOPLE_H

#include "Object.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class People : public Object
{
    private:
        string LastName;
        int Age;

    public:
        void setLastName(string lastName);
        string getLastName();
        void setAge(int age);
        int getAge();

        void readPeopleData(ifstream &filePeople);

        void Intro();
};

#endif