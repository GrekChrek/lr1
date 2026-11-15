#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename T>
T proverka(double min, double max) 
{
    T tipe;
    while (cin.peek() == '+' || !(cin >> tipe) || cin.peek() != '\n' || tipe < min || tipe > max) 
    {
        cout << "enter the correct value:";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return tipe;
}
string proverka()
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