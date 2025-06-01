#include <iostream>
#include <string>
#include <sstream>
#include "function.h"

int main() 
{
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    try 
    {
        std::string output = ProcessString(input);
        std::cout << "Результат: " << output << '\n';
    } 
    catch (const std::exception& e) 
    {
        std::cerr<< e.what() << '\n';
    }

    return 0;
}