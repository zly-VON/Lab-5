#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "People.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class Employee : public People
{
    private:
        int WorkAges;
        string Role;
        double Salary;
    
    public:
        void setWorkAges(int workAges);
        int getWorkAges();
        void setRole(string role);
        string getRole();
        void setSalary(double salary);
        double getSalary();

        void readEmployeeData(int i);

        void Intro();
        void sayTotalSum(double sum);
        string changeCheque(string cheque);
        void chequeRequest();
        int checkCheque(double sum, string cheque);
        int workerBreak(int randNum);
        int checkDiscount(int num);
        void announceRestock();
        void SuccessfulRestock();
        void cannotPay();
};

#endif