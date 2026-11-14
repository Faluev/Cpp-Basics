#pragma once

#include "Electronics.h"

class Television : public HomeAppliance
{
public:
    Television(const std::string& name, int priceRubles, int powerWatts, int screenInches);
    void showCharacteristics() const override;

private:
    int screenInches;
};

class Headphones : public PortableDevice
{
public:
    Headphones(const std::string& name, int priceRubles, int batteryMinutes, bool noiseCancellation);
    void showCharacteristics() const override;

private:
    bool noiseCancellation;
};

class CordlessVacuum : public HomeAppliance, public PortableDevice
{
public:
    CordlessVacuum(const std::string& name, int priceRubles, int powerWatts, int batteryMinutes, int binMilliliters);
    void showCharacteristics() const override;

private:
    int binMilliliters;
};
