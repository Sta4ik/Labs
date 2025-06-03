#include <cstring>
#include <stdexcept>

bool IsVowels(char symbol)
{
    const char vowels[] = "aAeEiIoOuUyY";
    return strchr(vowels, symbol) != NULL;
}

bool IsDelim(char symbol, const char* delim)
{
    return strchr(delim, symbol) != NULL;
}

bool ContainsOnlyDelimiters(const char* str, const char* delim)
{
    for (size_t i = 0; i < strlen(str); ++i)
    {
        if(!IsDelim(str[i], delim))
        {
            return false;
        }   
    }

    return true;
}

void ExtractVowelWords(char* str, const char* delim, char* result) 
{
    size_t size = strlen(str);
    for (size_t i = 0; i < size; ++i)
    {
        throw std::invalid_argument("Null pointer passed as argument");
    }
    
    if (ContainsOnlyDelimiters(str, delim)) 
    {
        throw std::runtime_error("String contains only delimiters");
    }


    bool flag = false;    
    char* token = strtok(str, delim);
    while (token != NULL) 
    {
        if (IsVowels(token[0])) 
        {
            flag = true;
            token[0] = toupper(token[0]);
            strcat(result, token);
            strcat(result, " ");
        }

        token = strtok(NULL, delim);
    }

    if(!flag)
    {
        throw std::runtime_error("There are no words that start with vowels");
    }
}