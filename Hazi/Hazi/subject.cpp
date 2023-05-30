#include "subject.h"
#include <iostream>
#include <fstream>

using namespace std;

Subject::Subject() : strings(nullptr), size(0) {}

Subject::~Subject() {
    ofstream file(privfilename);
    for (int i = 0; i < size; i++) {
            file << strings[i] << "\n"; // Stringek ki�r�sa a f�jlba, "\n" elv�laszt�val
        }
    file.close(); // F�jl bez�r�sa

    delete[] strings; // T�mb felszabad�t�sa
}

void Subject::readFromFile(const string& filename) {
    privfilename = filename;
    ifstream file(filename); // File megnyit�sa

    if (file.is_open()) {
        string line;

        while (getline(file, line, '\n')) {
            if (!line.empty()) {
                addString(line); // String hozz�ad�sa a t�mbh�z
            }
        }

        file.close(); // File bez�r�sa
    }
    else {
        cout << "Hiba: Nem sikerult megnyitni a file-t." << endl;
    }
}

void Subject::addString(string& str) {
    string* newStrings = new string[size + 1]; // �j, nagyobb m�ret� t�mb l�trehoz�sa

    for (int i = 0; i < size; i++) {
        newStrings[i] = strings[i]; // Stringek m�sol�sa az �j t�mbbe
    }

    newStrings[size] = str; // �j string hozz�ad�sa az �j t�mbh�z

    delete[] strings; // R�gi t�mb felszabad�t�sa

    strings = newStrings; // T�mb friss�t�se az �j t�mbre
    size++; // M�ret n�vel�se
}


void Subject::deleteString(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            strings[i] = strings[i + 1]; // Elemek �tm�sol�sa az egy helyel el�bb l�v� poz�ci�ba
        }

        size--; // M�ret cs�kkent�se

        string* newStrings = new string[size]; // �j, kisebb m�ret� t�mb l�trehoz�sa

        for (int i = 0; i < size; i++) {
            newStrings[i] = strings[i]; // Stringek m�sol�sa az �j t�mbbe
        }

        delete[] strings; // R�gi t�mb felszabad�t�sa

        strings = newStrings; // T�mb friss�t�se az �j t�mbre
    }
    else {
        cout << "Hiba: Tulindexeles." << endl;
    }
}

string& Subject::operator[](int index) {
    if (index >= 0 && index < size) {
        return strings[index]; // Visszaadja az adott index� stringet
    }
    else {
        cout << "Hiba: Tulindexeles." << endl;
        exit(1);
    }
}

void Subject::dispSubject() const {
    for (int i = 0; i < size; i++) {
        cout << i+1 << ". " << strings[i] << endl;
    }
    cout << endl;
}
 
int Subject::getSize() const {
    return size; // Visszaadja a t�mb m�ret�t
}
