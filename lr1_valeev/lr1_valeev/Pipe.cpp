#include "Pipe.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
using namespace std;

int Pipe::nextID = 1;

Pipe::Pipe()
{
	ID = nextID++;
}

int Pipe::getID() const
{
	return ID;
}

std::string Pipe::getName() const
{
	return name;
}

bool Pipe::getstatus() const
{
	return status;
}

void Pipe::editstatus()
{
	status = !(status);
}

std::istream& operator>>(std::istream& in, Pipe& p)
{
	cout << "\nadd Pipe:\n";
	p.name = proverka();
	cout << "length (double):";
	p.length = proverka<double>(0, 10000);
	cout << "diametr (int):";
	p.diameter = proverka<int>(0, 10000);
	cout << "Is the pipe working? (1 - yes, 0 - no): ";
	p.status = proverka<int>(0, 1);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Pipe& p)
{
	out << "ID pipe: " << p.ID << endl;
	out << "Name pipe: " << p.name << endl;
	out << "length pipe: " << p.length << " км" << endl;
	out << "diameter: " << p.diameter << " мм" << endl;
	out << "Condition of the pipe: " << (p.status ? "In working order" : "Under repair") << endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& inF, Pipe& p)
{
	inF >> p.ID;
	inF.ignore(100, '\n');
	getline(inF, p.name);
	inF >> p.length;
	inF >> p.diameter;
	inF >> p.status;
	Pipe::nextID = p.ID + 1;
	return inF;
}

std::ofstream& operator<<(std::ofstream& outF, const Pipe& p)
{
	outF << p.ID << endl;
	outF << p.name << endl;
	outF << p.length << endl;
	outF << p.diameter << endl;
	outF << p.status << endl;
	return outF;
}
