#include "Header Files/Object.h"
#include "Header Files/Store.h"
#include "Header Files/People.h"
#include "Header Files/Customer.h"
#include "Header Files/Employee.h"
#include "Header Files/Item.h"
#include "Header Files/Food.h"
#include "Header Files/Drink.h"
#include <ctime>
#include <iostream>
using namespace std;

int randNumber(int min, int max)
{
    int randomNumber;
    randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

int main(void)
{
    srand(time(NULL));
    system("clear");

    int customerNr = 1000;
    int employeeNr = 5;
    int foodNr = 70;
    int drinkNr = 21;
    int restock = 1;
    int restockTimes = 0;
    int quantityRestock = 75;
    int allergicPeopleNr = 0;
    int vegPeopleNr = 0;
    int peopleNotPaidNr = 0;
    int discountsNr = 0;
    int discountSum = 0;
    string NutsList[6] = {"Almonds", "Cashew Nuts", "Walnuts", "Coconut", "Pistachios", "Hazelnut"};
    string MilkList[5] = {"Milk", "Yogurt", "Cheese", "Butter", "Cacao Butter"};

    Store store;
    store.setName("Random Store");
    store.setDate("12.03.1998");
    store.setOutcome(0);
    store.setIncome(0);
    store.setBoughtItems(0);
    store.setSoldItems(0);
    store.setStolenItems(0);
    store.Welcome();

    Customer customer, customers[customerNr];
    for (int i = 0; i < customerNr; i++)
    {
        customer.readCustomerData(i);
        customers[i].setName(customer.getName());
        customers[i].setDate(customer.getDate());
        customers[i].setLastName(customer.getLastName());
        customers[i].setCheque(customer.getCheque());
        customers[i].setBalance(customer.getBalance());
        customers[i].setSum(customer.getSum());
        customers[i].setAge(customer.getAge());
        customers[i].setNrItems(0);

        int particularity = randNumber(1, 100);
        if (particularity < 1) customers[i].setParticularity("Nuts Allergy");
        else if (particularity < 6) customers[i].setParticularity("Milk Allergy");
        else if (particularity < 21) customers[i].setParticularity("Vegetarian");
        else customers[i].setParticularity("Nothing");

        if (customers[i].getParticularity() != "Nothing")
            if (customers[i].getParticularity() == "Vegetarian") vegPeopleNr++;
            else allergicPeopleNr++;
    }

    Employee employee, employees[employeeNr];
    for (int i = 0; i < employeeNr; i++)
    {
        employee.readEmployeeData(i);
        employees[i].setName(employee.getName());
        employees[i].setDate(employee.getDate());
        employees[i].setLastName(employee.getLastName());
        employees[i].setAge(employee.getAge());
        employees[i].setWorkAges(employee.getWorkAges());
        employees[i].setRole(employee.getRole());
        employees[i].setSalary(employee.getSalary());

        store.setOutcome(store.getOutcome() + employees[i].getSalary());
    }

    Food food, foods[foodNr];
    for (int i = 0; i < foodNr; i++)
    {
        food.readFoodData(i);
        foods[i].setName(food.getName());
        foods[i].setDate(food.getDate());
        foods[i].setPrice(food.getPrice());
        foods[i].setMass(food.getMass());
        foods[i].setQuantity(food.getQuantity());
        foods[i].setShopPrice(0.7 * foods[i].getPrice());

        store.setOutcome(store.getOutcome() + foods[i].getQuantity() * foods[i].getShopPrice());
        store.setBoughtItems(store.getBoughtItems() + foods[i].getQuantity());
    }
    
    Drink drink, drinks[drinkNr];
    for (int i = 0; i < drinkNr; i++)
    {
        drink.readDrinkData(i);
        drinks[i].setName(drink.getName());
        drinks[i].setDate(drink.getDate());
        drinks[i].setPrice(drink.getPrice());
        drinks[i].setVolume(drink.getVolume());
        drinks[i].setQuantity(drink.getQuantity());
        drinks[i].setShopPrice(0.7 * drinks[i].getPrice());

        store.setOutcome(store.getOutcome() + drinks[i].getQuantity() * drinks[i].getShopPrice());
        store.setBoughtItems(store.getBoughtItems() + foods[i].getQuantity());
    }

    // what a customer does
    for (int i = 0; i < customerNr; i++)
    {
        cout << endl;
        customers[i].enterStore();
        customers[i].checkBalance();
        int productNr = 0;
        string productList[12];
        int times = randNumber(2, 12);

        while (times--)
        {
            int nr = 0, flag = -1;
            int option = randNumber(1, 5);
            if (customers[i].getParticularity() == "Vegetarian")
            {
                while (option == 3)
                    option = randNumber(1, 5);
            }

            switch (option)
            {   // main section
                case 1:
                    store.goMainStore(customers[i].getName());
                    
                    flag = -1;
                    while(flag != productNr)
                    {
                        flag = 0;
                        nr = randNumber(28, foodNr-1);
                        if (customers[i].getParticularity() == "Milk Allergy")
                        {
                            for (int j = 0; j < sizeof(MilkList)/sizeof(MilkList[0]); j++)
                            {
                                while (foods[nr].getName() == MilkList[j])
                                    nr = randNumber(28, foodNr-1);
                            }
                        }
                        if (customers[i].getParticularity() == "Nuts Allergy")
                        {
                            for (int j = 0; j < sizeof(NutsList)/sizeof(NutsList[0]); j++)
                            {
                                while (foods[nr].getName() == NutsList[j])
                                    nr = randNumber(28, foodNr-1);
                            }
                        }
                        for (int i = 0; i < productNr; i++)
                            if (foods[nr].getName() != productList[i]) flag++;
                    }

                    foods[nr].wantedItem();
                    foods[nr].Description();
                    if (foods[nr].checkQuantity())
                    {
                        foods[nr].takeItem();
                        productList[productNr] = foods[nr].getName();
                        productNr++;
                        customers[i].addSum(foods[nr].getPrice());
                        customers[i].setNrItems(customers[i].getNrItems() + 1);
                    }
                    else foods[nr].noItem();
                break;
                // fish section
                case 2:
                    store.goFishmonger(customers[i].getName());
                    if (employees[2].workerBreak(randNumber(1, 100)))
                    {
                        flag = -1;
                        while(flag != productNr)
                        {
                            flag = 0;
                            nr = randNumber(12, 27);
                            for (int i = 0; i < productNr; i++)
                                if (foods[nr].getName() != productList[i]) flag++;
                        }

                        foods[nr].wantedItem();
                        foods[nr].Description();
                        if (foods[nr].checkQuantity())
                        {
                            foods[nr].takeItem();
                            productList[productNr] = foods[nr].getName();
                            productNr++;
                            customers[i].addSum(foods[nr].getPrice());
                            customers[i].setNrItems(customers[i].getNrItems() + 1);
                        }
                        else foods[nr].noItem();
                    }
                break;
                // meat section
                case 3:
                    store.goButcher(customers[i].getName());
                    if (employees[1].workerBreak(randNumber(1, 100)))
                    {
                        flag = -1;
                        while(flag != productNr)
                        {
                            flag = 0;
                            nr = randNumber(0, 11);
                            for (int i = 0; i < productNr; i++)
                                if (foods[nr].getName() != productList[i]) flag++;
                        }
                        
                        foods[nr].wantedItem();
                        foods[nr].Description();
                        if (foods[nr].checkQuantity())
                        {
                            foods[nr].takeItem();
                            productList[productNr] = foods[nr].getName();
                            productNr++;
                            customers[i].addSum(foods[nr].getPrice());
                            customers[i].setNrItems(customers[i].getNrItems() + 1);
                        }
                        else foods[nr].noItem();
                    }
                break;
                // drink section
                case 4:
                    store.goDrinkSection(customers[i].getName());

                    flag = -1;
                    while(flag != productNr)
                    {
                        flag = 0;
                        nr = randNumber(5, drinkNr-1);
                        
                        if (customers[i].getParticularity() == "Milk Allergy" )
                        {
                            while (foods[nr].getName() == MilkList[0])
                                nr = randNumber(28, foodNr-1);
                        }
                        for (int i = 0; i < productNr; i++)
                            if (drinks[nr].getName() != productList[i]) flag++;
                    }

                    drinks[nr].wantedItem();
                    drinks[nr].Description();
                    if (drinks[nr].checkQuantity())
                    {
                        drinks[nr].takeItem();
                        productList[productNr] = drinks[nr].getName();
                        productNr++;
                        customers[i].addSum(drinks[nr].getPrice());
                        customers[i].setNrItems(customers[i].getNrItems() + 1);
                    }
                    else drinks[nr].noItem();
                break;
                // hot drink section
                case 5:
                    store.goVendingMachine(customers[i].getName());
                    nr = randNumber(0, 4);
                    drinks[nr].wantedItem();
                    if (drinks[nr].checkQuantity())
                    {   // buy hot drink
                        if (customers[i].getBalance() > drinks[nr].getPrice())
                        {
                            drinks[nr].takeItem();
                            customers[i].payHotDrink(drinks[nr].getPrice());
                            store.addIncome(drinks[nr].getPrice());
                            customers[i].setNrItems(customers[i].getNrItems() + 1);
                        }
                        else cout << "The customer does not have enough money " << endl;
                    }
                    else drinks[nr].noItem();
                break;

                default:
                    cout << "ERROR! Closing Simulation" << endl;
                    return 0;
                break;
            }
        }

        if (customers[i].getBalance() >= customers[i].getSum())
        {
            // cashier
            if (randNumber(1, 100) < 95 && customers[i].getSum() != 0)
            {
                store.goCashier(customers[i].getName());
                employees[0].Intro();
                employees[0].sayTotalSum(customers[i].getSum());
                if (employee.checkDiscount(customers[i].getNrItems()))
                {
                    discountSum += customers[i].receiveDiscount();
                    discountsNr++;
                    employees[0].sayTotalSum(customers[i].getSum());
                }
                customers[i].Payment();
                store.addIncome(customers[i].getSum());
                store.setSoldItems(store.getSoldItems() + customers[i].getNrItems());
                customers[i].setCheque(employees[0].changeCheque(customers[i].getCheque()));
                customers[i].setSum(0);
            }
            else store.setStolenItems(store.getStolenItems() + customers[i].getNrItems());
            
            // security guard
            if (randNumber(1, 100) < 30)
            {
                employees[3].Intro();
                employees[3].chequeRequest();
                customers[i].showCheque();
                if (!employees[3].checkCheque(customers[i].getSum(), customers[i].getCheque()))
                {
                    peopleNotPaidNr++;
                    system("clear");
                    store.goCashier(customers[i].getName());
                    employees[0].Intro();
                    employees[0].sayTotalSum(customers[i].getSum());
                    if (employee.checkDiscount(customers[i].getNrItems()))
                    {
                        customers[i].receiveDiscount();
                        employees[0].sayTotalSum(customers[i].getSum());
                    }
                    customers[i].Payment();
                    store.addIncome(customers[i].getSum());
                    store.setSoldItems(store.getSoldItems() + customers[i].getNrItems());
                    store.setStolenItems(store.getStolenItems() - customers[i].getNrItems());
                    customers[i].setCheque(employees[0].changeCheque(customers[i].getCheque()));
                    customers[i].setSum(0);
                }
            }
        }
        else // customer cannot pay
        {
            store.goCashier(customers[i].getName());
            employees[0].Intro();
            employees[0].sayTotalSum(customers[i].getSum());
            employees[0].cannotPay();
            customers[i].setSum(0);
            // item goes back in store
            for (int i = 0; i < productNr; i++)
            {
                for (int j = 0; j < foodNr; j++)
                    if (foods[j].putItem(productList[i])) break;
                for (int j = 0; j < drinkNr; j++)
                    if (drinks[j].putItem(productList[i])) break;
            }
        }
        // customer leaves store
        store.leaveStore(customers[i].getName());
        // restock
        if (restock != 0 && randNumber(1, 100) < 30)
        {
            employees[4].Intro();
            employees[4].announceRestock();
            for (int i = 0; i < foodNr; i++)
            {
                foods[i].Restock(quantityRestock);
                store.addOutcome(foods[i].getShopPrice(), quantityRestock);
                store.setBoughtItems(store.getBoughtItems() + quantityRestock);
            }
            for (int i = 0; i < drinkNr; i++)
            {
                drinks[i].Restock(quantityRestock);
                store.addOutcome(drinks[i].getShopPrice(), quantityRestock);
                store.setBoughtItems(store.getBoughtItems() + quantityRestock);
            }
            employees[4].SuccessfulRestock();
            restock--;
            restockTimes++;
            store.setOutcome(store.getOutcome() + 50);
        }
    }
    // print statistics
    cout << endl;
    cout << "Statistics" << endl;
    cout << endl;
    cout << "Store exepenses: " << store.getOutcome() << " $" << endl;
    cout << "Store income: " << store.getIncome() << " $" << endl;
    cout << "Store revenue: " << store.getIncome() - store.getOutcome() << " $" << endl;
    cout << "Discount given: " << discountsNr << " - " << discountSum << " $" << endl;
    cout << "Bought Products: " << store.getBoughtItems() << endl;
    cout << "Sold products: " << store.getSoldItems() << endl;
    cout << "Stolen products: " << store.getStolenItems() << endl;
    cout << "Remainig products: " << store.getBoughtItems() - store.getSoldItems() - store.getStolenItems() << endl;
    cout << "Nr of restocks: " << restockTimes << endl;
    cout << "Restock quantity per item: " << quantityRestock << endl;
    cout << endl;
    cout << "Based on " << endl;
    cout << "Total customers: " << customerNr << endl;
    cout << "Vegetarian People: " << vegPeopleNr << endl;
    cout << "Allergic People: " << allergicPeopleNr << endl;
    cout << "People caught to stole: " << peopleNotPaidNr << endl;

    return 0;
}
