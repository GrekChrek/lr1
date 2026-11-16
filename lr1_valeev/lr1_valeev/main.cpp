#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"
#include "Validation.h"
#include "Menu.h"
using namespace std;
int main() {
	string menu = "Меню\n1.Добавить трубу\n2.Добавить КС\n3.Просмотр всех объектов\n4.Сохранить\n5.Загрузить\n6.Пакетная обработка труб\n7.Пакетная обработка КС\n0.Выход\n";
	unordered_map <int, Pipe> pipes = {};
	unordered_map <int, Station> css = {};
	while (true) {
		cout << menu;
		int action;
		action = proverka<int>(0, 7);
		if (action == 0) {
			return 0;
		}
		else {
			command(action, pipes, css);
		}
	}
	return 0;
}
