#include "Validation.h"
using namespace std;

std::string proverka()
{
    string name;
    while (true)
    {
        getline(cin, name);
        if (name.find_first_not_of(' ') == string::npos)
        {
            cout << "Enter the correct name: ";

        }
        else
        {
            return name;
        }
    }
}