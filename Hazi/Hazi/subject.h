#include <string>

using namespace std;

class Subject {
private:
    string privfilename = "";
    string* strings; // Dinamikus tömb
    int size; // Tömb mérete
public:
    Subject();
    ~Subject();

    void readFromFile(const string& filename);
    void addString(string& str);
    void deleteString(int index);
    void dispSubject() const;
    string& operator[](int index);
    int getSize() const;
};

