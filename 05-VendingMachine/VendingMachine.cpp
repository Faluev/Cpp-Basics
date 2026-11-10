#include "VendingMachine.h"

VendingMachine::VendingMachine(int slotCount)
{
    capacity = slotCount > 0 ? slotCount : 0;
    this->slotCount = 0;
    slots = new SnackSlot*[capacity];
}

VendingMachine::~VendingMachine()
{
    // Лотки удаляет вызывающий код, который их создал.
    delete[] slots;
}

bool VendingMachine::addSlot(SnackSlot* slot)
{
    if (slot == nullptr || slotCount == capacity)
    {
        return false;
    }

    for (int i = 0; i < slotCount; ++i)
    {
        if (slots[i] == slot)
        {
            return false;
        }
    }

    slots[slotCount] = slot;
    ++slotCount;
    return true;
}

int VendingMachine::getEmptySlotsCount() const
{
    return capacity - slotCount;
}

Snack* VendingMachine::vend(int slotIndex)
{
    if (slotIndex < 0 || slotIndex >= slotCount)
    {
        return nullptr;
    }

    return slots[slotIndex]->takeSnack();
}
