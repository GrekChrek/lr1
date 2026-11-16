#pragma once
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"
#include <string>

void menu(
    int action,
    std::unordered_map<int, Pipe>& pipes,
    std::unordered_map<int, Station>& css
);