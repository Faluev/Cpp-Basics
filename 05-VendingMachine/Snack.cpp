#include "Snack.h"

Snack::Snack(const std::string& snackName, int price, int calories)
{
    name = snackName;
    setPrice(price);
    setCalories(calories);
}

const std::string& Snack::getName() const
{
    return name;
}

int Snack::getPrice() const
{
    return price;
}

int Snack::getCalories() const
{
    return calories;
}

void Snack::setPrice(int newPrice)
{
    price = newPrice >= 0 ? newPrice : 0;
}

void Snack::setCalories(int newCalories)
{
    calories = newCalories >= 0 ? newCalories : 0;
}
