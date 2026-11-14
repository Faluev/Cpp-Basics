#include "Electronics.h"

#include <iostream>

Electronics::Electronics(const std::string& name, int priceRubles)
    : name(name), priceRubles(priceRubles)
{
}

Electronics::~Electronics() = default;

const std::string& Electronics::getName() const
{
    return name;
}

void Electronics::showCommonInfo() const
{
    std::cout << name << "\nЦена: " << priceRubles << " руб.\n";
}

HomeAppliance::HomeAppliance(int powerWatts)
    : powerWatts(powerWatts)
{
}

void HomeAppliance::showPower() const
{
    std::cout << "Мощность: " << powerWatts << " Вт\n";
}

PortableDevice::PortableDevice(int batteryMinutes)
    : batteryMinutes(batteryMinutes)
{
}

void PortableDevice::showBatteryLife() const
{
    std::cout << "Время работы от аккумулятора: " << batteryMinutes << " мин.\n";
}
