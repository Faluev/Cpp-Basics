#include <climits>
#include <iostream>

int main()
{
    while (true)
    {
        char operation = ' ';
        std::cout << "\nВыберите операцию (+, -, *, /, !, ^) или q для выхода: ";
        if (!(std::cin >> operation) || operation == 'q')
        {
            break;
        }

        if (operation != '+' && operation != '-' && operation != '*' &&
            operation != '/' && operation != '!' && operation != '^')
        {
            std::cout << "Неизвестная операция.\n";
            continue;
        }

        int first = 0;
        int second = 0;
        std::cout << (operation == '!' ? "Введите целое число: " : "Введите два целых числа: ");
        if (!(std::cin >> first) || (operation != '!' && !(std::cin >> second)))
        {
            std::cout << "Ошибка ввода. Ожидались целые числа.\n";
            break;
        }

        const long long wideFirst = first;
        const double realFirst = first;
        switch (operation)
        {
        case '+':
            std::cout << "Результат = " << wideFirst + second << '\n';
            break;
        case '-':
            std::cout << "Результат = " << wideFirst - second << '\n';
            break;
        case '*':
            std::cout << "Результат = " << wideFirst * second << '\n';
            break;
        case '/':
            if (second == 0)
            {
                std::cout << "Деление на ноль невозможно.\n";
            }
            else
            {
                std::cout << "Результат = " << realFirst / second << '\n';
            }
            break;
        case '!':
        {
            if (first < 0 || first > 20)
            {
                std::cout << "Для факториала введите число от 0 до 20.\n";
                break;
            }

            long long result = 1;
            for (int factor = 2; factor <= first; ++factor)
            {
                result *= factor;
            }
            std::cout << "Результат = " << result << '\n';
            break;
        }
        case '^':
        {
            const bool negativeResult = first < 0 && second % 2 != 0;
            const unsigned long long base = first < 0 ? -wideFirst : wideFirst;
            if (second < 0)
            {
                if (base == 0)
                {
                    std::cout << "Ноль нельзя возвести в отрицательную степень.\n";
                    break;
                }

                const double divisor = first < 0 ? -realFirst : realFirst;
                double result = 1.0;
                for (int i = second; i < 0 && base > 1 && result != 0.0; ++i)
                {
                    result /= divisor;
                }
                if (result == 0.0)
                {
                    std::cout << "Результат слишком мал.\n";
                }
                else
                {
                    std::cout << "Результат = " << (negativeResult ? -result : result) << '\n';
                }
                break;
            }

            unsigned long long result = base == 0 && second > 0 ? 0 : 1;
            bool overflow = false;
            for (int i = 0; i < second && base > 1; ++i)
            {
                // Проверяем, поместится ли следующее произведение в тип.
                if (result > ULLONG_MAX / base)
                {
                    overflow = true;
                    break;
                }
                result *= base;
            }
            if (overflow)
            {
                std::cout << "Степень выходит за диапазон вычислений.\n";
            }
            else
            {
                std::cout << "Результат = " << (negativeResult ? "-" : "") << result << '\n';
            }
            break;
        }
        }
    }

    return 0;
}
