#include "Menu.h"
#include "Validation.h"
#include "Comands.h"

void menu(int action,
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
        int i;
        cout << "Choose how to search: 1 — by name, 2 — by attribute\n";
        i = proverka<int>(1, 2);
        distributionPipes(pipes,i);
        break;
    }
    case 9: {
        int i;
        cout << "Choose how to search: 1 — by name, 2 — by percent\n";
        i = proverka<int>(1, 2);
        distributionStations(css, i);
        break;
    }
    }
}