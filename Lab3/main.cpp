#include <iostream>
#include "function.h"

int main() 
{
    try 
    {
        int64_t size{};
        std::cout << "Введите размер массива: ";

        size = InputSize();
        
        double* arr = new double[size];

        std::cout << "Выберите способ заполнения массива: \n 1. С клавиатуры \n 2. Случайными числами \n";
        int32_t typeInput{};
        typeInput = InputInputType();

        switch(typeInput)
        {
        case 1:
        {
            arr = FillArray(size, arr);
            break;
        }
        case 2:
        {
            arr = FillArrayRandom(size, arr);
            break;
        }
        default:
        {
            throw std::invalid_argument("Неверный выбор способа заполнения.");
            break;
        }
        }

        std::cout << "Максимальный по модулю элемент: " << FindMaxElement(size, arr) << "\n";
        std::cout << "Сумма между первым и вторым положительными элементами: " << FindSumBetweenPositive(size, arr) << "\n";
        std::cout << "Произведение положительных элементов: " << Positive(size, arr) << "\n";

        int64_t minIndex = FindMinElementIndex(size, arr);
        std::cout << "Сумма элементов до первого минимального: " << FindSumElementArray(minIndex, arr) << "\n";
        std::cout << "Элементы в порядке убывания их частоты встречаемости: "; 
        PrintArray(size, SortByCounts(size, arr));
        std::cout << '\n';

        std::cout << "Элементы упорядочены по четным и нечетным номерам: ";
        SortEvenAndOdd(size, arr);
        PrintArray(size, arr);
        std::cout << '\n';

        delete[] arr;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}