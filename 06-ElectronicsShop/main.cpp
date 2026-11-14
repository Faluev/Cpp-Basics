#include <cstddef>
#include <iostream>
#include <string>

#include "Products.h"

int readProductNumber(const std::string& line)
{
    int number = -1;
    for (std::size_t i = 0; i < line.size(); ++i)
    {
        const char symbol = line[i];
        if (symbol == ' ' || symbol == '\t' || symbol == '\r')
        {
            continue;
        }
        if (number != -1 || symbol < '0' || symbol > '9')
        {
            return -1;
        }
        number = symbol - '0';
    }
    return number;
}

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

        std::string line;
        if (!std::getline(std::cin, line))
        {
            break;
        }

        const int number = readProductNumber(line);
        if (number == 0)
        {
            break;
        }
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
