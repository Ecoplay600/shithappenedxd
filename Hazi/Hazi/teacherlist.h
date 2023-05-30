#include "teacher.h"
#include <string>

using namespace std;

class teacherlist {
private:
    string privfilename = "";
    Teacher** teachers;
    int size;

public:
    teacherlist();
    ~teacherlist();

    void addTeacher(Teacher** name);
    void deleteTeacher(int index);
    void readFromFile(const string& filename);

    Teacher& operator[](int index);

    int getSize() const;

    void clear();
    void resize();

    void dispTeacherList() const;
};

