#include <cctype>
#include <iomanip>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int first = 0;
    int second = 0;
    std::cout << "Введите два числа:\n";
    if (!(std::cin >> first >> second) || (!std::cin.eof() && !std::isspace(std::cin.peek())))
    {
        std::cerr << "Ошибка: введите два целых числа.\n";
        return 1;
    }

    const auto wideFirst = static_cast<long long>(first);
    std::cout << "\nРезультаты математических и логических операций:\n"
              << first << " + " << second << " = " << wideFirst + second << '\n'
              << first << " - " << second << " = " << wideFirst - second << '\n'
              << first << " * " << second << " = " << wideFirst * second << '\n'
              << first << " / " << second << " = ";

    if (second == 0)
    {
        std::cout << "деление на ноль невозможно\n";
    }
    else
    {
        std::cout << std::setprecision(15) << static_cast<double>(first) / second << '\n';
    }

    std::cout << first << " & " << second << " = " << (first & second) << '\n'
              << first << " | " << second << " = " << (first | second) << '\n'
              << first << " ^ " << second << " = " << (first ^ second) << '\n';
    return 0;
}
