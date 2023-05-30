#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Teacher {
	string name;
	string timetable[5][6];
public:
	Teacher() {}

	Teacher(const string& nev);

	void reName(const string& nev);

	string getName();

	void addSubj(int rowpar, int colpar, const string& subject);

	void removeSubj(int rowpar, int colpar);

	string getSubj(int rowpar, int colpar);

	void operator=(Teacher &other);
};