#include "Menu.h"
#include "Validation.h"
#include "Comands.h"
#include <cmath>

void menu(int action,
    std::unordered_map<int, Pipe>& pipes,
    std::unordered_map<int, Station>& css,
    std::ofstream& logfile) {
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
            output(pipes, "\nData output for the pipe:");
            output(css, "\nData output for the station:");
        }
        break;
    }
    case 4: {
        saveData(pipes, css, logfile);
        break;
    }
    case 5: {
        loadData(pipes, css, logfile);
        break;
    }
    case 6: {
        delet(pipes, logfile);
        break;
    }
    case 7: {
        delet(css, logfile);
        break;
    }
    case 8: {
        int i;
        cout << "Choose how to search: 1 — by name, 2 — by attribute\n";
        i = proverka<int>(1, 2);

        unordered_map<int, Pipe> found = distributionPipes(pipes, i, logfile);

        if (!found.empty()) {
            cout << "Choose action: 1 — edit, 2 — delete\n";
            int choice = proverka<int>(1, 2);

            if (choice == 1)
                massEditPipes(pipes, found, logfile);
            else
                massDelete(pipes, found, logfile);
        }
        break;
    }
    case 9: {
        int i;
        cout << "Choose how to search: 1 — by name, 2 — by percent\n";
        i = proverka<int>(1, 2);

        auto found = distributionStations(css, i, logfile);

        if (!found.empty()) {
            cout << "Choose action: 1 — edit, 2 — delete\n";
            int choice = proverka<int>(1, 2);

            if (choice == 1)
                massEditStations(css, found, logfile);
            else
                massDelete(pipes, found, logfile);;
        }
        break;
    }
    }
}