#include <string>

using namespace std;

class Subject {
private:
    string privfilename = "subjects.txt";
    string* strings; // Dinamikus t�mb
    int size; // T�mb m�rete
public:
    Subject();

    void save();
    void readFromFile();
    void addString(string& str);
    void deleteString(int index);
    void dispSubject() const;
    string& operator[](int index);
    int getSize() const;
};

