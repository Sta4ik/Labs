#include <iostream>
#include <time.h>
#include "function.h"

size_t InputSize()
{
    int64_t size{};

    std::cin >> size;

    if(std::cin.fail() || size < 0) 
    {
        throw std::invalid_argument("Неверный аргумент. Ожидается число > 0.");
    }

    return size;
}

void AllocationMemory(int64_t size, double*& arr)
{
    arr = new double[size];
}

double* FillArray(int64_t size, double* arr)
{
    std::cout << "Введите " << size << " элементов: ";
    for (int64_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    return arr;
}

double* FillArrayRandom(int64_t size, double* arr) 
{
    double lowerBorder{}; 
    double upperBorder{};
    std::cout << "Введите границы интервала (например, 1 и 10): ";
    std::cin >> lowerBorder >> upperBorder;

    if(lowerBorder > upperBorder) 
    {
        throw std::invalid_argument("Неверные границы интервала.");
    }
    
    srand(time(nullptr));
    for(size_t i = 0; i < size; ++i)
    {
        arr[i] = lowerBorder + rand() % static_cast<int>(lowerBorder - upperBorder + 1);
    }
    
    return arr;
}


double FindMaxElement(int64_t size, double* arr)
{
    double maxElement{arr[0]};

    for(size_t i = 0; i < size; ++i) 
    {
        if(abs(arr[i]) > abs(maxElement)) 
        {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

double FindSumBetweenPositive(int64_t size, double* arr)
{
    double sum{0.0};
    int64_t firstPos{-1};
    int64_t secondPos{-1};

    for(int64_t i = 0; i < size; ++i)
    {
        if(arr[i] > 0)
        {
            if(firstPos < 0)
            {
                firstPos = i;
            }
            else
            {
                secondPos = i;
                break;
            }
        }
    }
    
    if(firstPos == -1 || secondPos == -1)
    {
        throw std::runtime_error("Не найдено положительных чисел в массиве.");
    }

    for(int64_t i = firstPos + 1; i < secondPos; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

double Positive(int64_t size, double* arr)
{
    double result{1.0};

    for(int64_t i = 0; i < size; ++i)
    {
        if(arr[i] > 0)
        {
            result *= arr[i];
        }
    }
    return result;
}

int64_t FindMinElementIndex(int64_t size, double* arr)
{
    int64_t minElementIndex{};

    for(int64_t i = 0; i < size; ++i)
    {
        if(arr[i] < arr[minElementIndex])
        {
            minElementIndex = i;
        }
    }
    return minElementIndex;
}

double FindSumElementArray(int64_t size, double* arr)
{
    double sum{};

    for(int64_t i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

void BubleSort(int64_t size, double* arr)
{
    bool swapped{};
    for(int64_t i = 0; i < size; ++i)
    {
        swapped = false;
        for(int64_t j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
}

void SortEvenAndOdd(int64_t size, double* arr)
{
    int64_t temp{};
    double* even = new double[size / 2 + size % 2];
    double* odd = new double[size / 2];

    for(int64_t i = 0; i < size; i+= 2)
    {
        even[temp] = arr[i];
        odd[temp] = arr[i + 1];
        temp += 1;
    }

    BubleSort(size / 2 + size % 2, even);
    BubleSort(size / 2, odd);

    temp = 0;

    for(int64_t i = 0; i < size; i+= 2)
    {
        arr[i] = even[temp];
        arr[i + 1] = odd[temp];
        temp += 1;
    }

    delete[] even;
    delete[] odd;
}

int64_t FindNewSize(int64_t size, double* arr)
{
    int64_t temp{};

    for(int64_t i = 0; i < size; ++i)
    {
        if(arr[i] != arr[i + 1])
        {
            temp += 1;
        }
    }
    return temp;
}

double* SortByCounts(int64_t size, double* arr)
{
    int64_t index{};
    int64_t newSize = FindNewSize(size, arr);
    double* keys = new double[newSize];
    int64_t* counts = new int64_t[newSize];

    BubleSort(size, arr);
    
    keys[0] = arr[0];
    counts[0] = 1;

    for(int64_t i = 1; i < size; ++i)
    {
        if(keys[index] != arr[i])
        {
            index += 1;
            keys[index] = arr[i];
            counts[index] = 1;
        }
        else
        {
            counts[index] += 1;
        }
    }

    Sort(newSize, counts, keys);

    return ExpationArray(size, newSize, counts, keys);
}

void Sort(int64_t size, int64_t* arr, double* keys)
{
    bool swapped{};
    for(int64_t i = 0; i < size; ++i)
    {
        swapped = false;
        for(int64_t j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] < arr[j + 1])
            {
                std::swap(keys[j], keys[j + 1]);
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
}

double* ExpationArray(int64_t size, int64_t newSize, int64_t* count, double* keys)
{
    int64_t index{};
    double* result = new double[size];

    for(int64_t i = 0; i < newSize; ++i)
    {
        for(int64_t j = 0 ; j < count[i]; ++j)
        {
            result[index] = keys[i];
            ++index;
        }
    }
 
    return result;
}

int32_t InputInputType()
{
    int32_t inputType{};

    std::cin >> inputType;

    if(std::cin.fail() || inputType < 1 || inputType > 2) 
    {
        throw std::invalid_argument("Неверный аргумент. Ожидается число от 1 до 2.");
    }

    return inputType;
}

void PrintArray(int64_t size, double* arr)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}