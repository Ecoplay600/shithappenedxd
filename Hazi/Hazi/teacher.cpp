#include "teacher.h"

Teacher::Teacher(const string& nev) {
    name = nev;
    int row = 5, col = 6;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            timetable[i][j] = "-";
        }
    }
};

string Teacher::getName() {
	return name;
}

void Teacher::addSubj(int rowpar, int colpar, const string& subject) {
    timetable[rowpar][colpar] = subject;
};

void Teacher::removeSubj(int rowpar, int colpar) {
    timetable[rowpar][colpar] = "-";
};

void Teacher::reName(const string& nev){
	name = nev;
}

string Teacher::getSubj(int rowpar, int colpar) {
    return timetable[rowpar][colpar];
}

void Teacher::operator=(Teacher& other) {
    name = other.name;
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 6; k++) {
            timetable[j][k] = other.timetable[j][k];
        } 
    }
};