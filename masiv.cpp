#include <iostream>
#include <stdexcept>

class DynArray
{
private:
    int *mas; 
    int size; 

public:

    DynArray(int sz = 8)
    {
        mas = new int[sz];
        size = sz;
        // Инициализация массива нулями
        for (int i = 0; i < size; ++i)
        {
            mas[i] = 0;
        }
    }

    DynArray(int *P, int sz)
    {
        mas = new int[sz];
        size = sz;
        for (int i = 0; i < size; ++i)
        {
            mas[i] = P[i];
        }
    }


    DynArray(const DynArray &obj)
    {
        size = obj.size;
        mas = new int[size];
        for (int i = 0; i < size; ++i)
        {
            mas[i] = obj.mas[i];
        }
    }

    ~DynArray()
    {
        delete[] mas;
    }

    DynArray &operator=(const DynArray &obj)
    {
        if (this != &obj)
        {
           
            delete[] mas;

            size = obj.size;
            mas = new int[size];
            for (int i = 0; i < size; ++i)
            {
                mas[i] = obj.mas[i];
            }
        }
        return *this;
    }


    DynArray operator+(const DynArray &obj)
    {
        int newSize = size + obj.size;
        DynArray result(newSize);


        for (int i = 0; i < size; ++i)
        {
            result.mas[i] = mas[i];
        }

        for (int i = 0; i < obj.size; ++i)
        {
            result.mas[size + i] = obj.mas[i];
        }

        return result;
    }

    int &operator[](int ix)
    {
        if (ix < 0 || ix >= size)
        {
            throw std::out_of_range("Индекс вне допустимого диапазона");
        }
        return mas[ix];
    }

    friend std::ostream &operator<<(std::ostream &out, const DynArray &obj)
    {
        for (int i = 0; i < obj.size; ++i)
        {
            out << obj.mas[i] << " ";
        }
        return out;
    }
};

int main()
{
    try
    {
        DynArray arr1;
        std::cout << "arr1: " << arr1 << std::endl;

        int values[] = {1, 2, 3, 4, 5};
        DynArray arr2(values, 5);
        std::cout << "arr2: " << arr2 << std::endl;

        DynArray arr3 = arr2;
        std::cout << "arr3: " << arr3 << std::endl;

        DynArray arr4;
        arr4 = arr3;
        std::cout << "arr4: " << arr4 << std::endl;

        DynArray arr5 = arr2 + arr3;
        std::cout << "arr5: " << arr5 << std::endl;

        std::cout << "arr2[2]: " << arr2[2] << std::endl;

    }
    catch (const std::exception &ex)
    {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
    }

    return 0;
}
