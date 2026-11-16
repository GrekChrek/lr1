#include <iostream>
#include <fstream>
#include <unordered_map>
#include <format>
#include <chrono>
#include <filesystem>
#include "Pipe.h"
#include "Station.h"
#include "Validation.h"
#include "Menu.h"


using namespace std;

int main() {
    filesystem::create_directories("Logs");
    string time = std::format(
        "{:%d_%m_%Y_%H_%M_%S}",
        chrono::system_clock::now()
    );

    ofstream logfile("Logs/log_" + time + ".txt");

    if (!logfile) {
        cerr << "Failed to create log file\n";
    }
    

    unordered_map<int, Pipe> pipes = {};
    unordered_map<int, Station> css = {};

    string str = "\nMenu\n1.Add pipe\n2.Add CS\n3.View all objects\n4.Save\n5.Load\n6.Remove the pipe\n7.Remove the compressor station\n8.Batch processing of pipes\n9.Batch processing of CS\n0.Exit\n";

    while (true) {
        cout << str;

        int action = proverka<int>(0, 9);

        //logfile << action << '\n';
        //logfile.flush();
        menu(action, pipes, css, logfile);
        if (action == 0) {
            break;
        }
    }


    return 0;
}
