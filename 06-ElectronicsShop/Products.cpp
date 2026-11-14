#include "Products.h"

#include <iostream>

Television::Television(const std::string& name, int priceRubles, int powerWatts, int screenInches)
    : Electronics(name, priceRubles), HomeAppliance(powerWatts), screenInches(screenInches)
{
}

void Television::showCharacteristics() const
{
    showCommonInfo();
    showPower();
    std::cout << "Диагональ экрана: " << screenInches << " дюймов\n";
}

Headphones::Headphones(const std::string& name, int priceRubles, int batteryMinutes, bool noiseCancellation)
    : Electronics(name, priceRubles), PortableDevice(batteryMinutes), noiseCancellation(noiseCancellation)
{
}

void Headphones::showCharacteristics() const
{
    showCommonInfo();
    showBatteryLife();
    std::cout << "Шумоподавление: " << (noiseCancellation ? "есть" : "нет") << '\n';
}

CordlessVacuum::CordlessVacuum(const std::string& name, int priceRubles, int powerWatts,
    int batteryMinutes, int binMilliliters)
    : Electronics(name, priceRubles), HomeAppliance(powerWatts), PortableDevice(batteryMinutes),
      binMilliliters(binMilliliters)
{
}

void CordlessVacuum::showCharacteristics() const
{
    showCommonInfo();
    showPower();
    showBatteryLife();
    std::cout << "Объём контейнера: " << binMilliliters << " мл\n";
}
