
#pragma once

#include <string>
#include <iostream>
#include <fstream>

//inline std::ofstream createLogFile()
//{
//    std::ofstream logfile("log.txt", std::ios::app);
//
//    if (!logfile.is_open())
//        std::cout << "Log file error!\n";
//
//    return logfile;
//}

template <typename T>
T proverka(double min, double max)
{
    T tipe;

    while (std::cin.peek() == '+' ||
        !(std::cin >> tipe) ||
        std::cin.peek() != '\n' ||
        tipe < min || tipe > max)
    {
        std::cout << "Enter the correct value: ";

        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cerr << tipe << std::endl;
    //logfile.flush();

    return tipe;
}


inline std::string proverka()
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
            std::cerr << name << std::endl;
            //logfile.flush();
            return name;
        }
    }
}