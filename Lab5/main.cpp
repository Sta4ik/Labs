#include "function.h"
#include <iostream>

int main()
{
    try
    {
        int64_t rows{};
        int64_t cols{};
        int64_t **mtr = nullptr;

        std::cout << "Введите количество строк: ";
        rows = EnterRows();

        std::cout << "Введите количество столбцов: ";
        cols = EnterCols();

        AllocatedMemory(mtr, rows, cols);
        MakeElementZero(mtr, rows, cols);
        
        std::cout << "Выберите способ заполнения матрицы: \n 1. С клавиатуры \n 2. Случайными числами \n";
        int32_t typeInput{};
        typeInput = InputInputType();

        switch(typeInput)
        {
        case 1:
        {
            FillMatrix(mtr, rows, cols);

            std::cout << "Начальная матрица, заполненная числами с клавиатуры: \n"; 
            PrintMatrix(mtr, rows, cols);

            break;
        }
        case 2:
        {
            FillMatrixRandom(mtr, rows, cols);

            std::cout << "Начальная матрица, заполненная случайными числами: \n"; 
            PrintMatrix(mtr, rows, cols);

            break;
        }
        default:
        {
            throw std::invalid_argument("Неверный выбор способа заполнения.");
            break;
        }
        }

        int64_t sum = SumRowsWithoutZero(mtr, rows, cols);
        std::cout << "Cумма элементов в тех строках, которые не содержат нулей: " << sum << '\n';

        FindFirstRowWithZero(mtr, rows, cols);

        FindSaddlePoints(mtr, rows, cols);

        std::cout << "Матрица с переставлеными местами 1-ый и последний столбец, 2-ой и предпоследний и т. д: \n";
        SwapCols(mtr, rows, cols);
        PrintMatrix(mtr, rows, cols);

        DeleteMemory(mtr, rows);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }
    
}