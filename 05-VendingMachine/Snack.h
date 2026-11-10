#pragma once

#include <string>

class Snack
{
public:
    Snack(const std::string& name, int price = 0, int calories = 0);

    const std::string& getName() const;
    int getPrice() const;
    int getCalories() const;

    void setPrice(int newPrice);
    void setCalories(int newCalories);

private:
    std::string name;
    int price;
    int calories;
};
