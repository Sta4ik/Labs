#include <iostream>
#include <string>
#include <sstream>


bool IsNumber(const std::string& word) 
{
    if(word.empty()) 
    { 
        return false; 
    }

    for(size_t i = 0; i < word.length(); ++i)
    {
        if(!isdigit(word[i]))
        { 
            return false;
        }
    }

    return true;
}

bool IsAlphabet(const std::string& word)
{
    if(word.empty())
    { 
        return false; 
    }

    for(size_t i = 0; i < word.length(); ++i)
    {
        if (!isalpha(word[i]))
        { 
            return false; 
        }
    }

    return true;
}

bool IsOnlyDelimetrs(const std::string& input)
{
    std::string separators = ".,!?;:()[]{}\"' ";

    for(size_t i = 0; i < input.length(); ++i) 
    {
        if(separators.find(input[i]) == std::string::npos)
        { 
            return false; 
        }
    }

    return true;
}


std::string CleanDelimetrs(const std::string& input) 
{
    std::string cleaned;
    std::string delimetrs = ".,!?;:()[]{}\"' ";
    
    for(size_t i = 0; i < input.length(); ++i)
    {
        if (delimetrs.find(input[i]) != std::string::npos)
        {
            cleaned += ' ';
        } 
        else 
        {
            cleaned += input[i];
        }
    }

    return cleaned;
}

std::string ProcessString(const std::string& input) 
{
    if (input.empty()) 
    {
        throw std::runtime_error("Введена пустая строка.");
    }

    if (IsOnlyDelimetrs(input)) 
    {
        throw std::runtime_error("Строка содержит только знаки препинания.");
    }

    std::string cleaned = CleanDelimetrs(input); 

    std::istringstream stream(cleaned);

    std::string word;

    const int32_t MAX_WORDS = 100;

    std::string numbers[MAX_WORDS];
    std::string letters[MAX_WORDS]; 
    std::string others[MAX_WORDS];

    size_t numCount{};
    size_t letterCount{};
    size_t otherCount{};

    while(stream >> word) 
    {
        if(IsNumber(word)) 
        {
            numbers[numCount++] = word;
        }

        else if(IsAlphabet(word)) 
        {
            letters[letterCount++] = word;
        }

        else 
        {
            others[otherCount++] = word;
        }
    }

    std::string result;
    size_t numIndex{};
    size_t letterIndex{};
    
    for(size_t i = 0; i < numCount + letterCount; ++i) 
    {
        if(i % 2 == 0) 
        {
            if(letterIndex < letterCount) 
            {
                result += letters[letterIndex++] + " ";
            }
        }
        else 
        {
            if(numIndex < numCount) 
            {
                result += numbers[numIndex++] + " ";
            }
        }
    }

    for (size_t j = 0; j < otherCount; ++j) 
    {
        result += others[j] + " ";
    }
    
    return result;
}