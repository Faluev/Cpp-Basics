#include "IntegerArray.h"

#include <iostream>
#include <stdexcept>

void Check(bool condition, const char* message)
{
    if (!condition)
    {
        throw std::runtime_error(message);
    }
}

int main()
{
    try
    {
        IntegerArray values(3);
        Check(values.getLength() == 3 && values[0] == 0 && values[2] == 0,
            "Создание массива");
        values[0] = 10;
        values[1] = 20;
        values[2] = 30;

        const IntegerArray& original = values;
        IntegerArray copy(original);
        copy[0] = 99;
        Check(copy.getLength() == 3 && copy[2] == 30 && original[0] == 10,
            "Независимость копии");

        IntegerArray assigned(1);
        assigned = original;
        const IntegerArray& sameObject = assigned;
        assigned = sameObject;
        assigned[1] = 88;
        Check(assigned.getLength() == 3 && assigned[0] == 10 && assigned[2] == 30
            && original[1] == 20, "Присваивание и самоприсваивание");

        values.resize(5);
        Check(values.getLength() == 5 && values[2] == 30 && values[4] == 0,
            "Увеличение размера");
        values.resize(2);
        Check(values.getLength() == 2 && values[0] == 10 && values[1] == 20,
            "Уменьшение размера");

        values.insertBefore(5, 0);
        values.insertBefore(15, 2);
        values.insertBefore(25, values.getLength());
        Check(values.getLength() == 5 && values[0] == 5 && values[1] == 10
            && values[2] == 15 && values[3] == 20 && values[4] == 25,
            "Вставка в начало, середину и конец");

        values.remove(0);
        values.remove(1);
        values.remove(values.getLength() - 1);
        Check(values.getLength() == 2 && values[0] == 10 && values[1] == 20,
            "Удаление первого, среднего и последнего элементов");

        IntegerArray empty(0);
        IntegerArray emptyCopy(empty);
        assigned = emptyCopy;
        Check(emptyCopy.getLength() == 0 && assigned.getLength() == 0,
            "Копирование пустого массива");
        empty.insertBefore(7, 0);
        Check(empty.getLength() == 1 && empty[0] == 7, "Вставка в пустой массив");
        empty.remove(0);
        Check(empty.getLength() == 0, "Удаление единственного элемента");

        try
        {
            IntegerArray invalid(-1);
            Check(false, "Отрицательная длина при создании должна вызвать bad_length");
        }
        catch (const bad_length& error)
        {
            std::cout << "bad_length: " << error.what() << '\n';
        }

        try
        {
            values.resize(-1);
            Check(false, "Отрицательная длина при изменении размера должна вызвать bad_length");
        }
        catch (const bad_length&)
        {
        }

        const int invalidIndices[] = { -1, values.getLength() };
        const int invalidInsertIndices[] = { -1, values.getLength() + 1 };
        for (int i = 0; i < 2; ++i)
        {
            try
            {
                original[invalidIndices[i]];
                Check(false, "Неверный индекс чтения должен вызвать bad_range");
            }
            catch (const bad_range& error)
            {
                std::cout << "bad_range: " << error.what() << '\n';
            }

            try
            {
                values.remove(invalidIndices[i]);
                Check(false, "Неверный индекс удаления должен вызвать bad_range");
            }
            catch (const bad_range&)
            {
            }

            try
            {
                values.insertBefore(99, invalidInsertIndices[i]);
                Check(false, "Неверная позиция вставки должна вызвать bad_range");
            }
            catch (const bad_range&)
            {
            }
        }

        Check(values.getLength() == 2 && values[0] == 10 && values[1] == 20,
            "Данные должны сохраниться после исключений");
        values.resize(0);
        Check(values.getLength() == 0, "Уменьшение размера до нуля");

        std::cout << "Все проверки IntegerArray пройдены.\n";
    }
    catch (const std::exception& error)
    {
        std::cerr << "Проверка не пройдена: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
