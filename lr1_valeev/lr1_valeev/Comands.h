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
void delet(
    std::unordered_map<int, Item>& items,
    std::ofstream& logfile)
{
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

std::unordered_map<int, Pipe> distributionPipes(
    const std::unordered_map<int, Pipe>& pipes,
    int i,
    std::ofstream& logfile)
{
    std::unordered_map<int, Pipe> result;

    if (i == 1) {
        std::string name;
        std::cout << "Enter the name: ";
        name = proverka();

        result = searchByNamet(pipes, name);
    }
    else {
        int status;
        std::cout << "Enter the repair status: ";
        status = proverka<int>(0, 1);

        result = searchBySignt(pipes, status);
    }
    output(result, "\nSearch results:");
    return result;
}

std::unordered_map<int, Station> distributionStations(
    const std::unordered_map<int, Station>& css,
    int i,
    std::ofstream& logfile)
{
    std::unordered_map<int, Station> result;
    if (i == 1) {
        std::string name;
        std::cout << "Enter the name: ";
        name = proverka();

        result = searchByNamet(css, name);
    }
    else {
        double percent;
        std::cout << "Enter the percent: ";
        percent = proverka<double>(0, 100);

        result = searchByUnusedWorkshops(css, percent);
    }

    output(result, "\nSearch results:");
    return result;
}

void saveData(
    const std::unordered_map<int, Pipe>& pipes,
    const std::unordered_map<int, Station>& css,
    std::ofstream& logfile)
{
    std::string filename;
    std::cout << "Enter filename: ";
    std::getline(std::cin >> std::ws, filename);

    std::ofstream file(filename);

    if (!file) {
        std::cout << "Cannot open file!\n";
        logfile << "Save error: " << filename << '\n';
        return;
    }

    file << "PIPES\n";
    file << pipes.size() << '\n';

    for (const auto& item : pipes) {
        file << item.second;
    }

    file << "STATIONS\n";
    file << css.size() << '\n';
    for (const auto& item : css) {
        file << item.second;
    }
    std::cout << "Data saved!\n";
    logfile <<  filename << '\n';
}

template<typename Item>
bool loadContainer(
    std::ifstream& file,
    std::unordered_map<int, Item>& items)
{
    size_t count;

    if (!(file >> count))
        return false;

    for (size_t i = 0; i < count; i++) {
        Item item;

        if (!(file >> item))
            return false;

        if (!items.emplace(item.getID(), item).second)
            return false;
    }

    return true;
}

void loadData(
    const std::unordered_map<int, Pipe>& pipes,
    const std::unordered_map<int, Station>& css,
    std::ofstream& logfile)
{
    std::string filename;
    std::cout << "Enter filename: ";
    std::getline(std::cin >> std::ws, filename);

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Cannot open file!\n";
        return;
    }

    std::string section;

    std::unordered_map<int, Pipe> newPipes;
    std::unordered_map<int, Station> newCss;

    if (!(file >> section) || section != "PIPES" ||
        !loadContainer(file, newPipes)) {
        std::cout << "Error reading pipes!\n";
        return;
    }

    if (!(file >> section) || section != "STATIONS" ||
        !loadContainer(file, newCss)) {
        std::cout << "Error reading stations!\n";
        return;
    }

    const_cast<std::unordered_map<int, Pipe>&>(pipes).swap(newPipes);
    const_cast<std::unordered_map<int, Station>&>(css).swap(newCss);

    std::cout << "Data loaded!\n";
    logfile << "Data loaded from: " << filename << '\n';
}

inline void massEditPipes(
    std::unordered_map<int, Pipe>& pipes,
    const std::unordered_map<int, Pipe>& found,
    std::ofstream& logfile)
{
    std::cout << "Enter new status (0 - not working, 1 - working): ";
    int status = proverka<int>(0, 1);

    for (const auto& item : found) {
        auto it = pipes.find(item.first);

        if (it != pipes.end() && it->second.getstatus() != status)
            it->second.editstatus();
    }

    std::cout << "Pipes successfully edited!\n";
    logfile << "Mass editing pipes. New status: "
        << status << '\n';
}

inline void massEditStations(
    std::unordered_map<int, Station>& css,
    const std::unordered_map<int, Station>& found,
    std::ofstream& logfile)
{
    for (const auto& item : found) {
        auto it = css.find(item.first);

        if (it == css.end())
            continue;

        std::cout << "Station ID: " << item.first << '\n';
        std::cout << it->second;

        std::cout << "Enter new number of working workshops: ";
        int count = proverka<int>(0, 10000);

        it->second.editTotalWorkingShops(count);
    }

    std::cout << "Stations successfully edited!\n";
    logfile << "Mass editing stations. Count: "
        << found.size() << '\n';
}

template<typename Item1, typename Item2>
void massDelete(
    std::unordered_map<int, Item1>& items,
    const std::unordered_map<int, Item2>& found,
    std::ofstream& logfile)
{
    for (auto& item : found)
        items.erase(item.first);

    std::cout << "deleted!\n";
    logfile << found.size() << '\n';
}


//void writeLog(std::ofstream& logfile, int action, bool success = true)
//{
//    if (action < 10)
//        logfile << "0";
//
//    logfile << action << '\n';
//    logfile.flush();
//}