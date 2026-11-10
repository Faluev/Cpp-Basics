#include <iostream>

#include "VendingMachine.h"

int main()
{
    Snack* bounty = new Snack("Bounty");
    Snack* snickers = new Snack("Snickers");
    bounty->setPrice(80);
    bounty->setCalories(220);

    SnackSlot* slot = new SnackSlot(10);
    slot->addSnack(bounty);
    slot->addSnack(snickers);

    const int slotCount = 5;
    VendingMachine* machine = new VendingMachine(slotCount);
    machine->addSlot(slot);
    std::cout << "Свободных мест для лотков: " << machine->getEmptySlotsCount() << '\n';

    Snack* snack = machine->vend(0);
    if (snack != nullptr)
    {
        std::cout << "Выдан товар: " << snack->getName()
                  << ", цена: " << snack->getPrice()
                  << ", калорийность: " << snack->getCalories() << " ккал\n";
    }
    std::cout << "Осталось товаров в лотке: " << slot->getSnackCount() << '\n';

    delete machine;
    delete slot;
    delete snickers;
    delete bounty;

    return 0;
}
