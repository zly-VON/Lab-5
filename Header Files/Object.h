#ifndef OBJECT_H
#define OBJECT_H

#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class Object
{
    private:
        string Name;
        string Date;

    public:
        void setName(string name);
        string getName();
        void setDate(string date);
        string getDate();

        void readObjectData(ifstream &file);
};

#endif