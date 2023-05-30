#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "menu.h"

using namespace std;

int main() {
	Subject sl;
	sl.readFromFile("subjects.txt");
	teacherlist tl;
	tl.readFromFile("teachers.txt");
	tl.dispTeacherList();
	//dispMain(sl);
	return 0;
}