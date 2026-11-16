#pragma once

#include <exception>

class bad_range : public std::exception
{
public:
    const char* what() const noexcept override;
};

class bad_length : public std::exception
{
public:
    const char* what() const noexcept override;
};

class IntegerArray
{
public:
    explicit IntegerArray(int length = 0);
    IntegerArray(const IntegerArray& other);
    IntegerArray& operator=(const IntegerArray& other);
    ~IntegerArray();

    int getLength() const;
    int& operator[](int index);
    const int& operator[](int index) const;
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);

private:
    void checkIndex(int index) const;
    void replaceData(int* newData, int newLength);

    int length;
    int* data;
};
