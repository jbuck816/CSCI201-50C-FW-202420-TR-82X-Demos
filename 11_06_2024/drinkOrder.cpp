#include "drinkOrder.h"

drinkOrder::drinkOrder()
{
    numDrinks = 0;
    drinks = new drink *[numDrinks + 1];
    drinks[0] = nullptr;
}
drinkOrder::drinkOrder(const drinkOrder &otherDrinkOrder)
{
    numDrinks = otherDrinkOrder.numDrinks;
    drinks = new drink *[numDrinks + 1];
    for (int i = 0; i < numDrinks; i++)
    {
        drinks[i] = new drink(*otherDrinkOrder.drinks[i]);
    }
}

void drinkOrder::addDrink(const drink &drinkToAdd)
{
    drinks[numDrinks] = new drink(drinkToAdd);
    numDrinks++;
    drink **dCpy;
    dCpy = drinks;
    drinks = new drink *[numDrinks + 1];
    for (int i = 0; i < numDrinks; i++)
    {
        drinks[i] = dCpy[i];
    }
    delete[] dCpy;
}

std::string drinkOrder::tostring() const
{
    std::ostringstream out;
    out << "This order has " << numDrinks << " drinks:" << std::endl;
    out << std::setw(25) << std::setfill('-') << "-" << std::endl;
    for (int i = 0; i < numDrinks; i++)
    {
        out << drinks[i]->tostring() << std::endl;
        out << std::setw(25) << std::setfill('-') << "-" << std::endl;
    }
    return out.str();
}

void drinkOrder::removeLastDrink()
{
    delete drinks[numDrinks - 1];
    numDrinks--;
}

drinkOrder::~drinkOrder()
{
    for (int i = 0; i < numDrinks; i++)
    {
        delete drinks[i];
    }
    delete[] drinks;
}

const drinkOrder &drinkOrder::operator=(const drinkOrder &rightHandSide)
{
    for (int i = 0; i < this->numDrinks; i++)
    {
        delete this->drinks[i];
        this->drinks[i] = nullptr;
    }
    delete[] this->drinks;
    this->drinks = nullptr;

    this->numDrinks = rightHandSide.numDrinks;
    this->drinks = new drink *[this->numDrinks];
    for (int i = 0; i < numDrinks; i++)
    {
        this->drinks[i] = new drink(*(rightHandSide.drinks[i]));
    }
    return *this;
}