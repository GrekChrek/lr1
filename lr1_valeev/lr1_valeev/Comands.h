#pragma once
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"
#include "Validation.h"
#include <string>
#include <cmath>

template<typename Item>
void input(std::unordered_map<int, Item>& items) {
    Item item;
    std::cin >> item;
    items.emplace(item.getID(), item);
}

template<typename Item>
void output(
    const std::unordered_map<int, Item>& items,
    const std::string& prompt) {
    if (!items.empty()) {
        std::cout << prompt << std::endl;
        for (const auto& item : items) {
            std::cout << item.second;
            std::cout << std::endl;
        }
    }
}

template<typename Item>
void delet(std::unordered_map<int, Item>& items) {
    std::cout << "Enter the ID you want to delete:";
    int id;
    id = proverka<int>(1, 999999);
    if (items.erase(id)) {
        std::cout << "The element has been found and removed" << std::endl;
    }
    else {
        std::cout << "There was no element with that ID" << std::endl;
    }
}

template<typename Item>
std::unordered_map<int, Item> searchByNamet(
    const std::unordered_map<int, Item>& items,
    const std::string& name)
{
    std::unordered_map<int, Item> result;

    for (const auto& item : items) {
        if (item.second.getName() == name) {
            result.emplace(item.first, item.second);
        }
    }

    if (result.empty()) {
        std::cout << "I couldn't find it\n";
    }

    return result;
}

template<typename Item>
std::unordered_map<int, Item> searchBySignt(
    const std::unordered_map<int, Item>& items,
    const int& status)
{
    std::unordered_map<int, Item> result;

    for (const auto& item : items) {
        if (item.second.getstatus() == status) {
            result.emplace(item.first, item.second);
        }
    }

    if (result.empty()) {
        std::cout << "I couldn't find it\n";
    }

    return result;
}

template<typename Item>
std::unordered_map<int, Item> searchByUnusedWorkshops(
    const std::unordered_map<int, Item>& items,
    double percentage)
{
    std::unordered_map<int, Item> result;

    for (const auto& item : items) {
        if (std::abs(item.second.getUnusedWorkshops() - percentage) < 0.001) {
            result.emplace(item.first, item.second);
        }
    }

    if (result.empty()) {
        std::cout << "I couldn't find it\n";
    }

    return result;
}

void distributionPipes(
    const std::unordered_map<int, Pipe>& pipes,
    int i)
{
    if (i == 1) {
        std::string name;
        std::cout << "Enter the name: ";
        name = proverka();

        auto result = searchByNamet(pipes, name);
        output(result, "\nSearch results:");
    }
    else {
        int status;
        std::cout << "Enter the repair status: ";
        status = proverka<int>(0, 1);

        auto result = searchBySignt(pipes, status);
        output(result, "\nSearch results:");
    }
}

void distributionStations(
    const std::unordered_map<int, Station>& css,
    int i)
{
    if (i == 1) {
        std::string name;
        std::cout << "Enter the name: ";
        name = proverka();

        auto result = searchByNamet(css, name);
        output(result, "\nSearch results:");
    }
    else {
        double percent;
        std::cout << "Enter the percent: ";
        percent = proverka<double>(0, 100);

        auto result = searchByUnusedWorkshops(css, percent);
        output(result, "\nSearch results:");
    }
}
