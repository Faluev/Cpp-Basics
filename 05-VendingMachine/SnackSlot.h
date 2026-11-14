#pragma once

#include "Snack.h"

class SnackSlot
{
public:
    SnackSlot(int maxSnacks);
    ~SnackSlot();

    // Лоток хранит адрес товара. Товар удаляет код, который его создал.
    bool addSnack(Snack* snack);
    Snack* takeSnack();
    int getSnackCount() const;
    int getEmptySpacesCount() const;

private:
    // Запрещаем копировать лоток, чтобы каждый массив удалялся один раз.
    SnackSlot(const SnackSlot& other);
    SnackSlot& operator=(const SnackSlot& other);

    Snack** snacks;
    int capacity;
    int snackCount;
};
