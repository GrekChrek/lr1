#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"

//void cinpipe() {
//    cout << "\nadd pipe:\n";
//    cout << "name:";
//    getline(cin >> ws, p);
//    cout << "length (double):";
//    p.length = proverka<double>(0, 10000);
//    cout << "diametr (int):";
//    p.diametr = proverka<int>(0, 10000);
//    cout << "am i working? (1-yes 0-no)";
//    p.work = proverka<bool>(0, 10000);
//}

int main() {
	string menu = "Меню\n1.Добавить трубу\n2.Добавить КС\n3.Просмотр всех объектов\n4.Редактировать трубу\n5.Редактировать КС\n6.Сохранить\n7.Загрузить\n0.Выход\n";
	Pipe p = {};
	CS cs = {};
	string menu = "Меню\n1.Добавить трубу\n2.Добавить КС\n3.Просмотр всех объектов\n4.Сохранить\n5.Загрузить\n6.Пакетная обработка труб\n7.Пакетная обработка КС\n0.Выход\n";
	unordered_map <int, Pipe> pipes = {};
	unordered_map <int, Station> css = {};
	while (true) {
		int action;
		readValid(action, menu);
		readValidNumber(action, menu, 0, 7);
		if (action == 0) {
			return 0;
		}
		else {
			command(action, p, cs);
			command(action, pipes, css);
		}
	}
	return 0;
}