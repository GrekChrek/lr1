#include "Validation.h"


std::string proverka()
{
    std::string name;
    while (true)
    {
        getline(std::cin, name);
        if (name.find_first_not_of(' ') == std::string::npos)
        {
            std::cout << "Enter the correct name: ";

        }
        else
        {
            return name;
        }
    }
}