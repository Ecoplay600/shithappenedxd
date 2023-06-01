#include "teacher.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class teacherlist {
private:
    string privfilename = "teachers.txt";
    Teacher* teachers;
    int size;

public:
    teacherlist();
    void save();
    void addTeacher(Teacher* name);
    void modSubj(const int tindex, const int i, const int j,const string& newsubj);
    void delSubj(const int tindex,const int i, const int j);
    void deleteTeacher(const int index);
    void readFromFile();

    Teacher& operator[](const int index);

    int getSize();
    void dispTeachers();

    void dispTeacherTimeTable(const int i) const;
};

