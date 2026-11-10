#pragma once

#include "SnackSlot.h"

class VendingMachine
{
public:
    VendingMachine(int slotCount);
    ~VendingMachine();

    bool addSlot(SnackSlot* slot);
    int getEmptySlotsCount() const;
    Snack* vend(int slotIndex);

private:
    // Доступ к копированию закрыт, чтобы массив принадлежал одному автомату.
    VendingMachine(const VendingMachine& other);
    VendingMachine& operator=(const VendingMachine& other);

    SnackSlot** slots;
    int capacity;
    int slotCount;
};
