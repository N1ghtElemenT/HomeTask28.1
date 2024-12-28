#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyArray
{
    T* data;
    int size;
    int capacity;
    int grow;

    void allocateMemory(int newCapacity)
    {
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    MyArray(int initialSize = 0, int grow = 1) : size(0), capacity(initialSize), grow(grow)
    {
        data = new T[capacity]();
    }

    ~MyArray()
    {
        delete[] data;
    }

    int GetSize() const
    {
        return size;
    }

    void SetSize(int newSize, int grow = 1)
    {
        this->grow = grow;
        if (newSize > capacity)
        {
            int newCapacity = capacity;
            while (newCapacity < newSize)
            {
                newCapacity += grow;
            }
            allocateMemory(newCapacity);
        }
        size = newSize;
    }

    int GetUpperBound() const
    {
        return size > 0 ? size - 1 : -1;
    }

    bool IsEmpty() const
    {
        return size == 0;
    }

    void FreeExtra()
    {
        if (size < capacity)
        {
            allocateMemory(size);
        }
    }

    void RemoveAll()
    {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    T GetAt(int index) const
    {
        if (index < 0 || index >= size)
        {
            return T();
        }
        return data[index];
    }

    bool SetAt(int index, const T& value)
    {
        if (index < 0 || index >= size)
        {
            return false;
        }
        data[index] = value;
        return true;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }

    void Add(const T& value)
    {
        if (size >= capacity)
        {
            allocateMemory(capacity + grow);
        }
        data[size++] = value;
    }

    void Append(const MyArray<T>& other)
    {
        int totalSize = size + other.size;
        if (totalSize > capacity)
        {
            allocateMemory(totalSize);
        }
        for (int i = 0; i < other.size; ++i)
        {
            data[size++] = other.data[i];
        }
    }

    MyArray<T>& operator=(const MyArray<T>& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            grow = other.grow;
            data = new T[capacity];
            for (int i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T* GetData() const
    {
        return data;
    }

    bool InsertAt(int index, const T& value)
    {
        if (index < 0 || index > size)
        {
            return false;
        }
        if (size >= capacity)
        {
            allocateMemory(capacity + grow);
        }
        for (int i = size; i > index; --i)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
        return true;
    }

    bool RemoveAt(int index)
    {
        if (index < 0 || index >= size)
        {
            return false;
        }
        for (int i = index; i < size - 1; ++i)
        {
            data[i] = data[i + 1];
        }
        --size;
        return true;
    }
};