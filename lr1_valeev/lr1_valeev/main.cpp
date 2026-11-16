
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

int main()
{
    string time = std::format("{:%d_%m_%Y %H_%M_%OS}", std::chrono::system_clock::now());
    ofstream logfile("Logs\\log_" + time + ".txt");
    redirect_output_wrapper cerr_out(cerr);
    if (logfile) {
        cerr_out.redirect(logfile);
    }

    unordered_map<int, Pipe> pipes;
    unordered_map<int, Station> css;

    string str =
        "\nMenu\n"
        "1.Add pipe\n"
        "2.Add CS\n"
        "3.View all objects\n"
        "4.Save\n"
        "5.Load\n"
        "6.Remove the pipe\n"
        "7.Remove the compressor station\n"
        "8.Batch processing of pipes\n"
        "9.Batch processing of CS\n"
        "0.Exit\n";

    while (true) {
        cout << str;

        int action = proverka<int>(0, 9);

        menu(action, pipes, css, logfile);

        if (action == 0) {
            break;
        }
    }

    logfile.close();

    return 0;
}
