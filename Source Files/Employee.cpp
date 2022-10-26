#include "Header Files/Employee.h"

void Employee::setWorkAges(int workAges) { WorkAges = workAges; }
int Employee::getWorkAges() { return WorkAges; }
void Employee::setRole(string role) { Role = role; }
string Employee::getRole() { return Role; }
void Employee::setSalary(double salary) { Salary = salary; }
double Employee::getSalary() { return Salary; }

void Employee::readEmployeeData(int i)
{
    ifstream fileEmployee;
    fileEmployee.open("Data List/employeeData.txt", ios::in);

    string ignore;
    int j = i * 7;
    while(j--) getline(fileEmployee, ignore);

    readPeopleData(fileEmployee);

    string workAges, role, salary;
    getline(fileEmployee, workAges);
    setWorkAges(atof(workAges.c_str()));
    getline(fileEmployee, role);
    setRole(role);
    getline(fileEmployee, salary);
    setSalary(atof(salary.c_str()));

    fileEmployee.close();
}

void Employee::Intro()
{
    cout << "Hi. I am " << getName() << endl;
    cout << "I am the " << getRole() << " that works today" << endl;
}
void Employee::sayTotalSum(double sum)
{
    cout << "The total comes to " << sum << "$." << endl;
}
string Employee::changeCheque(string cheque)
{
    if (cheque == "Paid") cheque = "NotPaid";
    else cheque = "Paid";
    return cheque;
}
void Employee::chequeRequest()
{
    cout << "I will control the cheque of the customer" << endl;
}
int Employee::checkCheque(double sum, string cheque)
{
    if (sum == 0 && cheque == "NotPaid")
    { 
        cout << "The customer did not buy anything. He is free to leave." << endl;
        return 1;
    }
    else if (cheque == "NotPaid") 
    {
        cout << "The customer have not paid! He cannot leave. \n" << endl;
        return 0;
    }
    else 
    {
        cout << "It is all right.\n" << endl;
        return 1;
    }
}
int Employee::workerBreak(int randNum)
{
    if (randNum <= 15)
    {
        cout << "\nWe are really sorry, the employee in charge of this section is temporary on break" << endl;
        cout << "Come back later" << endl;
        return 0;
    }
    else return 1;
}
int Employee::checkDiscount(int num)
{
    if (num == 12) 
    {
        cout << "\nOh, you bought 12 items. You won a discount of 10%, congrats!" << endl;
        return 1;
    }
    else return 0;
}
void Employee::announceRestock()
{
    cout << "I am here to restock all the item of the store" << endl;
}
void Employee::SuccessfulRestock() 
{
    cout << "\nAll items were restored" << endl;
}
void Employee::cannotPay()
{
    cout << "\nSorry, you do not have enough money to pay" << endl;
    cout << "Come back another time" << endl;
}
