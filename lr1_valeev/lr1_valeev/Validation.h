#pragma once
#include <string>
#include <iostream>


template <typename T>
T proverka(double min, double max)
{
    T tipe;
    while (std::cin.peek() == '+' || !(std::cin >> tipe) || std::cin.peek() != '\n' || tipe < min || tipe > max)
    {
        std::cout << "enter the correct value:";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return tipe;
}
std::string proverka();
