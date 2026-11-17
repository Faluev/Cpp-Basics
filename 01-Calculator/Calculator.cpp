#include <cctype>
#include <iostream>

bool readInteger(int& value)
{
    if (!(std::cin >> value))
    {
        return false;
    }
    const int next = std::cin.peek();
    return next == std::char_traits<char>::eof() || std::isspace(next);
}

int main()
{
    int first = 0;
    int second = 0;
    std::cout << "Введите два целых числа.\n";
    if (!readInteger(first) || !readInteger(second))
    {
        std::cout << "Ошибка ввода. Ожидались два целых числа.\n";
        return 1;
    }

    const long long wideFirst = first;
    const double dividend = first;
    std::cout << "\nРезультаты математических и логических операций:\n"
              << first << " + " << second << " = " << wideFirst + second << '\n'
              << first << " - " << second << " = " << wideFirst - second << '\n'
              << first << " * " << second << " = " << wideFirst * second << '\n';
    if (second == 0)
    {
        std::cout << "Деление на ноль невозможно.\n";
    }
    else
    {
        std::cout << first << " / " << second << " = " << dividend / second << '\n';
    }
    std::cout << first << " & " << second << " = " << (first & second) << '\n'
              << first << " | " << second << " = " << (first | second) << '\n'
              << first << " ^ " << second << " = " << (first ^ second) << '\n';
    return 0;
}
