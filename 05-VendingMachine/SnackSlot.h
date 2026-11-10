#pragma once

#include "Snack.h"

class SnackSlot
{
public:
    SnackSlot(int capacity);
    ~SnackSlot();

    bool addSnack(Snack* snack);
    Snack* takeSnack();
    int getSnackCount() const;
    int getEmptySpacesCount() const;

private:
    // Доступ к копированию закрыт, чтобы массив принадлежал одному лотку.
    SnackSlot(const SnackSlot& other);
    SnackSlot& operator=(const SnackSlot& other);

    Snack** snacks;
    int capacity;
    int snackCount;
};
