#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"
#include "Validation.h"
#include "Menu.h"
using namespace std;
int main() {
	string str = "\nMenu\n1.Add pipe\n2.Add CS\n3.View all objects\n4.Save\n5.Load\n6.Remove the pipe\n7.Remove the compressor station\n0.Exit\n";
	unordered_map <int, Pipe> pipes = {};
	unordered_map <int, Station> css = {};
	while (true) {
		cout << str;
		int action;
		action = proverka<int>(0, 9);
		if (action == 0) {
			return 0;
		}
		else {
			menu(action, pipes, css);
		}
	}
	return 0;
}
