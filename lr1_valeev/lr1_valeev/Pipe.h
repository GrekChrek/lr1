#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Pipe {
private:
	static int nextID;
	int ID;
	string name;
	double length;
	int diameter;
	bool status;
public:
	Pipe();
	int getID() const;
	std::string getName() const;
	bool getstatus() const;
	void editstatus();
	friend std::istream& operator >> (std::istream& in, Pipe& p);
	friend std::ifstream& operator >> (std::ifstream& inF, Pipe& p);
	friend std::ostream& operator << (std::ostream& out, const Pipe& p);
	friend std::ofstream& operator << (std::ofstream& outF, const Pipe& p);
};
