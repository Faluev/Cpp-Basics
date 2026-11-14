#include <iostream>
#include <string>

#include "Products.h"

int main()
{
    Television television("Телевизор", 32990, 95, 43);
    Headphones headphones("Беспроводные наушники", 4990, 1800, true);
    CordlessVacuum vacuum("Аккумуляторный пылесос", 16990, 220, 45, 600);
    Electronics* stock[] = { &television, &headphones, &vacuum };
    const int stockSize = sizeof(stock) / sizeof(stock[0]);

    std::cout << "Магазин электроники\n";
    while (true)
    {
        std::cout << "\nТовары на складе\n";
        for (int i = 0; i < stockSize; ++i)
        {
            std::cout << i + 1 << ". " << stock[i]->getName() << '\n';
        }
        std::cout << "0. Выход\nВыберите номер товара: ";

        std::string choice;
        if (!(std::cin >> choice) || choice == "0")
        {
            break;
        }

        const int number = choice.size() == 1 ? choice[0] - '0' : -1;
        if (number < 1 || number > stockSize)
        {
            std::cout << "Введите номер из списка.\n";
            continue;
        }

        std::cout << "\nХарактеристики товара\n";
        stock[number - 1]->showCharacteristics();
    }

    return 0;
}
