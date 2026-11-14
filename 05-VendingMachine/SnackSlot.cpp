#include "SnackSlot.h"

SnackSlot::SnackSlot(int maxSnacks)
{
    capacity = maxSnacks > 0 ? maxSnacks : 0;
    snackCount = 0;
    snacks = new Snack*[capacity];
}

SnackSlot::~SnackSlot()
{
    delete[] snacks;
}

bool SnackSlot::addSnack(Snack* snack)
{
    if (snack == nullptr || snackCount == capacity)
    {
        return false;
    }

    snacks[snackCount] = snack;
    ++snackCount;
    return true;
}

Snack* SnackSlot::takeSnack()
{
    if (snackCount == 0)
    {
        return nullptr;
    }

    Snack* snack = snacks[0];
    // Сдвигаем остаток к началу, сохраняя порядок загрузки.
    for (int i = 1; i < snackCount; ++i)
    {
        snacks[i - 1] = snacks[i];
    }
    --snackCount;
    return snack;
}

int SnackSlot::getSnackCount() const
{
    return snackCount;
}

int SnackSlot::getEmptySpacesCount() const
{
    return capacity - snackCount;
}
