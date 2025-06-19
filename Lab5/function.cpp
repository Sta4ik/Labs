#include <iostream>

int64_t EnterCols()
{
    int64_t cols{};

    std::cin >> cols;

    if(std::cin.fail() || cols < 1) 
    {
        throw std::invalid_argument("Неверный аргумент. Ожидается число больше нуля.");
    }

    return cols;
}

int64_t EnterRows()
{
    int64_t rows{};

    std::cin >> rows;

    if(std::cin.fail() || rows < 1) 
    {
        throw std::invalid_argument("Неверный аргумент. Ожидается число больше нуля.");
    }

    return rows;
}

void AllocatedMemory(int64_t**& mtr, int64_t rows, int64_t cols)
{
    mtr = new int64_t*[rows];
    for(int64_t i = 0; i < rows; ++i)
    {
        mtr[i] = new int64_t[cols];
    }
}

void DeleteMemory(int64_t**& mtr, int64_t rows)
{
    for(int64_t i = 0; i < rows; ++i)
    {
        delete[] mtr[i];
    }

    delete[] mtr;
}

bool CheckZero(int64_t* rows, int64_t cols)
{
    for(int64_t i = 0; i < cols; ++i)
    {
        if(rows[i] == 0)
        {
            return true;
        }
    }
    return false;
}

int64_t SumRowsWithoutZero(int64_t** mtr, int64_t rows, int64_t cols) 
{
    int64_t sum{};

    for(int64_t i = 0; i < rows; ++i)
    {
        if(!CheckZero(mtr[i], cols)) 
        {
            for(int64_t j = 0; j < cols; ++j) 
            {
                sum += mtr[i][j];
            }
        }
    }

    return sum;
}

void SwapCols(int64_t**& mtr, int64_t rows, int64_t cols)
{
    for(int64_t i = 0; i < rows; ++i)
    {
      for(int64_t j = 0; j < cols / 2; ++j)
        {
            std::swap(mtr[i][j], mtr[i][cols - j - 1]);
        }
    }
}

void MakeElementZero(int64_t**& mtr, int64_t rows, int64_t cols)
{
    for(int64_t i = 0; i < rows; ++i)
    {
        for(int64_t j = 0; j < cols; ++j)
        {
            mtr[i][j] = 0;
        }
    }
}

void PrintMatrix(int64_t** mtr, int64_t rows, int64_t cols)
{
    for(int64_t i = 0; i < rows; ++i)
    {
        for(int64_t j = 0; j < cols; ++j)
        {
            std::cout << mtr[i][j] << ' ';
        }

        std::cout << '\n';
    }

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

void FillMatrix(int64_t**& mtr, int64_t rows, int64_t cols)
{
    for(int64_t i = 0; i < rows; ++i)
    {
        for(int64_t j = 0; j < cols; ++j)
        {
            std::cout << "Введите элемент [" << i << "][" << j << "]: ";
            std::cin >> mtr[i][j];

            if(std::cin.fail())
            {
                throw std::invalid_argument("Неверный аргумент. Ожидается число.");
            }
        }
    }
}

void FillMatrixRandom(int64_t**& mtr, int64_t rows, int64_t cols)
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
    for(int64_t i = 0; i < rows; ++i)
    {
        for(int64_t j = 0; j < cols; ++j)
        {
            mtr[i][j] = lowerBorder + rand() % static_cast<int>(lowerBorder - upperBorder + 1);;
        }
    }
}

void FindFirstRowWithZero(int64_t** mtr, int64_t rows, int64_t cols)
{
    for(int64_t i = 0; i < rows; ++i)
    {
        if(CheckZero(mtr[i], cols))
        {
            std::cout << "Строка " << i << " содержит хотя бы один ноль: \n";

            for(int64_t j = 0; j < cols; ++j)
            {
                std::cout << mtr[i][j] << ' ';
            }

            std::cout << '\n';
            return;
        }
    }

    std::cout << "Ни одна строка не содержит нулей. \n";
}

void FindSaddlePoints(int64_t** mtr, int64_t rows, int64_t cols)
{
    bool foundSaddlePoint = false;

    for(int64_t i = 0; i < rows; ++i)
    {
        for(int64_t j = 0; j < cols; ++j)
        {
            int64_t temp = mtr[i][j];

            bool isMinInRow = true;
            for(int64_t col = 0; col < cols; ++col)
            {
                if(mtr[i][col] < temp)
                {
                    isMinInRow = false;
                    break;
                }
            }

            bool isMaxInCol = true;
            for(int64_t row = 0; row < rows; ++row)
            {
                if(mtr[row][j] > temp)
                {
                    isMaxInCol = false;
                    break;
                }
            }

            if(isMinInRow && isMaxInCol)
            {
                std::cout << "Седловая точка: [" << i << "][" << j << "] = " << temp << '\n';
                foundSaddlePoint = true;
            }
        }
    }

    if (!foundSaddlePoint)
    {
        std::cout << "Седловых точек не найдено.\n";
    }
}