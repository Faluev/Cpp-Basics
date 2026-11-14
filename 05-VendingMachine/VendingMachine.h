#pragma once

#include "SnackSlot.h"

class VendingMachine
{
public:
    VendingMachine(int maxSlots);
    ~VendingMachine();

    // Автомат хранит адрес лотка. Лоток удаляет код, который его создал.
    bool addSlot(SnackSlot* slot);
    int getEmptySlotsCount() const;
    Snack* vend(int slotIndex);

private:
    // Запрещаем копировать автомат, чтобы каждый массив удалялся один раз.
    VendingMachine(const VendingMachine& other);
    VendingMachine& operator=(const VendingMachine& other);

    SnackSlot** slots;
    int capacity;
    int slotCount;
};
