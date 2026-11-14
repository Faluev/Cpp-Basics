#pragma once

#include <string>

class Electronics
{
public:
    Electronics(const std::string& name, int priceRubles);
    virtual ~Electronics();

    const std::string& getName() const;
    virtual void showCharacteristics() const = 0;

protected:
    void showCommonInfo() const;

private:
    std::string name;
    int priceRubles;
};

// Обе ветви используют одну общую часть Electronics в устройстве с двумя родителями.
class HomeAppliance : virtual public Electronics
{
protected:
    HomeAppliance(int powerWatts);
    void showPower() const;

private:
    int powerWatts;
};

class PortableDevice : virtual public Electronics
{
protected:
    PortableDevice(int batteryMinutes);
    void showBatteryLife() const;

private:
    int batteryMinutes;
};
