#include <iostream>
#include "function.h"

int main() 
{
    try 
    {
        char str[300] = "";
        char delimiters[100] = "";
        char result[600] = "";

        std::cout << "Enter string: ";
        std::cin.getline(str, 300);
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(300, '\n');
            throw std::overflow_error("Input string more than 300 characters");
        }


        std::cout << "Enter delimiters: ";
        std::cin.getline(delimiters, 100);
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            throw std::overflow_error("Input delimiters more than 100 characters");
        }


        ExtractVowelWords(str, delimiters, result);

        std::cout << "Result: " << result << '\n';
    } 

    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
