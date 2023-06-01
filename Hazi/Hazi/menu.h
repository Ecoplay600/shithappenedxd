 #pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "teacherlist.h"
#include "subject.h"

using namespace std;

class menu {
	Subject sl;
	teacherlist tl;
	void logo();
	void menucls();
	void dispRemoveSubject();
	void dispAddSubject();
	void dispAddTeacher();
	void dispRemoveTeacher();
	void dispEditSubj(const int tindex);
	void dispDelSubj(const int tindex);
	void dispTeachers();
	void dispSubjects();
public:
	menu();
	void dispMain();
};

