#include "Menu.h"
#include "Validation.h"
template<typename Item>
void input(std::unordered_map<int, Item>& items) {
    Item item;
    std::cin >> item;
    items.emplace(item.getID(), item);
}

template<typename Item>
void output(const std::unordered_map<int, Item>& items, const std::string& prompt) {
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
    id = proverka<int>(1,999999);
    if (items.erase(id)) {
        std::cout << "The element has been found and removed" << std::endl;
    }
    else {
        std::cout << "There was no element with that ID" << std::endl;
    }
}



void command(int action,
    std::unordered_map<int, Pipe>& pipes,
    std::unordered_map<int, Station>& css) {
    switch (action) {
    case 1: {
        input(pipes);
        break;
    }

    case 2: {
        input(css);
        break;
    }
    case 3: {
        if (pipes.empty() && css.empty()) {
            cout << "Warning: The pipe and CS have not been created." << std::endl;
        }
        else {
            output(pipes, "Data output for the pipe:");
            output(css, "Data output for the station:");
        }
        break;
    }
    case 4: {
        break;
    }
    case 5: {
        break;
    }
    case 6: {
        delet(pipes);
        break;
    }
    case 7: {
        delet(css);
        break;
    }
    case 8: {
        break;
    }
    case 9: {
        break;
    }
    }
}