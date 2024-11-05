#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include "drink.h"

// lecture activity. Please submit the code you have changed
// add a drink pointer to the main and create a new dynamic drink.
// create a dynamic array of doubles in the main.

void resetStream();
sizeType inputDrinkSize();
baseType inputDrinkBase();
tempType inputDrinkTemperature();
std::string inputDrinkFlavor();
std::string inputDrinkDairy();
int *newArray();
bool numInRange(int num, int lower, int upper);
bool numGT0(int num, int = 0, int = 0);
bool negNum(int num, int = 0, int = 0);
int inputInt(std::string prompt, bool (*func)(int, int, int), int lower = 0, int upper = 0); // the function pointer returns a true if the data is valid
int main()
{
    int *list;

    int x = 7;
    int *p = &x;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    // drink yourDrink;
    drink *myDrink = nullptr;
    myDrink = new drink(inputDrinkBase(), inputDrinkTemperature(), inputDrinkSize(), inputDrinkDairy(), inputDrinkFlavor());
    std::cout << myDrink->tostring() << std::endl;

    list = newArray();

    delete myDrink;
    delete[] list;

    drink **order;
    int numDrinks = 1;
    order = new drink *[numDrinks];
    char yN = 'Y';
    while (yN == 'Y')
    {
        order[numDrinks - 1] = new drink(inputDrinkBase(), inputDrinkTemperature(), inputDrinkSize(), inputDrinkDairy(), inputDrinkFlavor());
        std::cout << order[numDrinks - 1]->tostring() << std::endl;
        std::cout << "Would you like another drink? ";
        std::cin >> yN;
        yN = toupper(yN);
        while (yN != 'Y' && yN != 'N')
        {
            std::cout << "You did not enter y or n." << std::endl;
            std::cout << "Would you like another drink? ";
            std::cin >> yN;
            yN = toupper(yN);
        }
        if (yN == 'Y')
        {
            drink **cpy = order;
            order = new drink *[++numDrinks];
            for (int i = 0; i < numDrinks - 1; i++)
            {
                order[i] = cpy[i];
            }
            delete[] cpy;
        }
    }
    std::cout << "The list of drinks is:" << std::endl;
    for (int i = 0; i < numDrinks; i++)
    {
        std::cout << order[i]->tostring() << std::endl;
        delete order[i];
    }
    delete[] order;
    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

sizeType inputDrinkSize()
{
    std::ostringstream out;

    out << "Please choose the drink size:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        out << i + 1 << ": " << sizeStr[i] << std::endl;
    }
    int drinkSize = inputInt(out.str(), numInRange, 1, 3);

    return sizes[drinkSize - 1];
}

baseType inputDrinkBase()
{
    std::ostringstream out;
    out << "Please choose the drink base:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        out << i + 1 << ": " << baseStr[i] << std::endl;
    }
    int drinkBase = inputInt(out.str(), numInRange, 1, 3);

    return bases[drinkBase - 1];
}

tempType inputDrinkTemperature()
{
    std::ostringstream out;
    int drinkTemp;
    out << "Please choose the drink temperature:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        out << i + 1 << ": " << tempStr[i] << std::endl;
    }
    drinkTemp = inputInt(out.str(), numInRange, 1, 3);

    return temps[drinkTemp - 1];
}

std::string inputDrinkFlavor()
{
    std::string flavor;
    std::cout << "Please enter a flavor for your drink: ";
    std::cin >> std::ws;
    std::getline(std::cin, flavor);
    return flavor;
}

std::string inputDrinkDairy()
{
    std::string dairy;
    std::cout << "What kind of dairy would you like? ";
    std::cin >> std::ws;
    std::getline(std::cin, dairy);
    return dairy;
}

int *newArray()
{
    int *list;
    int numRand = inputInt("How many numbers do you want? ", numGT0);
    list = new int[numRand];
    for (int i = 0; i < numRand; i++)
    {
        list[i] = rand() % 50 + 1;
    }
    return list;
}

bool numInRange(int num, int lower, int upper)
{
    return lower <= num && num <= upper;
}

bool numGT0(int num, int, int)
{

    return num > 0;
}

bool negNum(int num, int, int)
{
    return num < 0;
}

int inputInt(std::string prompt, bool (*func)(int, int, int), int lower, int upper)
{
    int theNum;
    std::cout << prompt;
    std::cin >> theNum;
    std::cout << std::endl;
    while (!std::cin || !func(theNum, lower, upper))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You have entered invalid data." << std::endl;
        std::cout << prompt;
        std::cin >> theNum;
        std::cout << std::endl;
    }

    return theNum;
}