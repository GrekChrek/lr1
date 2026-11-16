#include "Station.h"
#include <iostream>
#include "Validation.h"
#include <fstream>
#include <cmath>
using namespace std;

int Station::NextId = 1;

Station::Station()
{
	id = NextId++;
}

int Station::getID() const
{
	return id;
}

std::string Station::getName() const
{
	return name;
}

double Station::getUnusedWorkshops() const
{
	
	return (totalShops == 0 ? 0 : 100 * static_cast<double>(totalShops - totalWorkingShops) / totalShops);
}

void Station::editTotalWorkingShops(double workshopPercentage)
{
	if (workshopPercentage >= 0 && workshopPercentage <= 100)
	{
		totalWorkingShops = floor(totalShops * workshopPercentage / 100);
	}
	else
	{
		cout << "error";
	}
}

std::istream& operator>>(istream& in, Station& cs)
{
	cout << "\nadd cs:\n";
	cs.name = proverka();
	cout << "the number of stations(int):";
	cs.totalShops = proverka<int>(0, 10000);
	cout << "number of workstations(int):";
	cs.totalWorkingShops = proverka<int>(0, cs.totalShops);
	cout << "station class(char):";
	cs.classStation = proverka<char>('a', 'c');
	return in;
}

std::ifstream& operator>>(ifstream& inF, Station& cs) {
	inF >> cs.id;
	inF.ignore(100, '\n');
	getline(inF, cs.name);
	inF >> cs.totalShops;
	inF >> cs.totalWorkingShops;
	inF >> cs.classStation;
	Station::NextId = cs.id + 1;
	return inF;
}

std::ostream& operator<<(ostream& out, const Station& cs)
{
	out << "Station ID: " << cs.id << endl;
	out << "Station name: " << cs.name << endl;
	out << "Number of workshops: " << cs.totalShops << endl;
	out << "Number of working workshops: " << cs.totalWorkingShops << endl;
	out << "Station class: " << cs.classStation << endl;
	return out;
}

std::ofstream& operator<<(ofstream& outF, const Station& cs)
{
	outF << cs.id << endl;
	outF << cs.name << endl;
	outF << cs.totalShops << endl;
	outF << cs.totalWorkingShops << endl;
	outF << cs.classStation << endl;
	return outF;
}