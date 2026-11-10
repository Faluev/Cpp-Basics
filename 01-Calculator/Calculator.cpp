#include <iostream>

int main()
{
    int first = 0;
    int second = 0;
    std::cout << "Введите два целых числа. Второе должно быть ненулевым.\n";
    std::cin >> first >> second;

    const long long wideFirst = first;
    const double dividend = first;
    std::cout << "\nРезультаты математических и логических операций:\n"
              << first << " + " << second << " = " << wideFirst + second << '\n'
              << first << " - " << second << " = " << wideFirst - second << '\n'
              << first << " * " << second << " = " << wideFirst * second << '\n'
              << first << " / " << second << " = " << dividend / second << '\n'
              << first << " & " << second << " = " << (first & second) << '\n'
              << first << " | " << second << " = " << (first | second) << '\n'
              << first << " ^ " << second << " = " << (first ^ second) << '\n';
    return 0;
}
