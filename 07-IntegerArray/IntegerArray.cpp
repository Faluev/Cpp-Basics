#include "IntegerArray.h"

#include <climits>

namespace
{
    int* allocateData(int length)
    {
        if (length < 0)
        {
            throw bad_length();
        }

        return length == 0 ? nullptr : new int[length]{};
    }

    int* copyData(const int* source, int length)
    {
        int* copy = allocateData(length);
        for (int i = 0; i < length; ++i)
        {
            copy[i] = source[i];
        }
        return copy;
    }
}

const char* bad_range::what() const noexcept
{
    return "Index is out of range";
}

const char* bad_length::what() const noexcept
{
    return "Invalid array length";
}

IntegerArray::IntegerArray(int length)
    : length(length), data(allocateData(length))
{
}

IntegerArray::IntegerArray(const IntegerArray& other)
    : length(other.length), data(copyData(other.data, other.length))
{
}

IntegerArray& IntegerArray::operator=(const IntegerArray& other)
{
    if (this != &other)
    {
        replaceData(copyData(other.data, other.length), other.length);
    }
    return *this;
}

IntegerArray::~IntegerArray()
{
    delete[] data;
}

int IntegerArray::getLength() const
{
    return length;
}

int& IntegerArray::operator[](int index)
{
    checkIndex(index);
    return data[index];
}

const int& IntegerArray::operator[](int index) const
{
    checkIndex(index);
    return data[index];
}

void IntegerArray::resize(int newLength)
{
    if (newLength == length)
    {
        return;
    }

    int* newData = allocateData(newLength);
    const int count = newLength < length ? newLength : length;
    for (int i = 0; i < count; ++i)
    {
        newData[i] = data[i];
    }
    replaceData(newData, newLength);
}

void IntegerArray::insertBefore(int value, int index)
{
    if (index < 0 || index > length)
    {
        throw bad_range();
    }
    if (length == INT_MAX)
    {
        throw bad_length();
    }

    const int newLength = length + 1;
    int* newData = allocateData(newLength);
    for (int i = 0; i < index; ++i)
    {
        newData[i] = data[i];
    }
    newData[index] = value;
    for (int i = index; i < length; ++i)
    {
        newData[i + 1] = data[i];
    }
    replaceData(newData, newLength);
}

void IntegerArray::remove(int index)
{
    checkIndex(index);

    const int newLength = length - 1;
    int* newData = allocateData(newLength);
    for (int i = 0; i < index; ++i)
    {
        newData[i] = data[i];
    }
    for (int i = index + 1; i < length; ++i)
    {
        newData[i - 1] = data[i];
    }
    replaceData(newData, newLength);
}

void IntegerArray::checkIndex(int index) const
{
    if (index < 0 || index >= length)
    {
        throw bad_range();
    }
}

void IntegerArray::replaceData(int* newData, int newLength)
{
    // Меняем массив после успешного выделения памяти и копирования элементов.
    delete[] data;
    data = newData;
    length = newLength;
}
