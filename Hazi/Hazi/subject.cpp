#include "subject.h"
#include <iostream>
#include <fstream>

using namespace std;

Subject::Subject() : strings(nullptr), size(0) {}

Subject::~Subject() {
    ofstream file(privfilename);
    for (int i = 0; i < size; i++) {
            file << strings[i] << "\n"; // Stringek kiírása a fájlba, "\n" elválasztóval
        }
    file.close(); // Fájl bezárása

    delete[] strings; // Tömb felszabadítása
}

void Subject::readFromFile(const string& filename) {
    privfilename = filename;
    ifstream file(filename); // File megnyitása

    if (file.is_open()) {
        string line;

        while (getline(file, line, '\n')) {
            if (!line.empty()) {
                addString(line); // String hozzáadása a tömbhöz
            }
        }

        file.close(); // File bezárása
    }
    else {
        cout << "Hiba: Nem sikerult megnyitni a file-t." << endl;
    }
}

void Subject::addString(string& str) {
    string* newStrings = new string[size + 1]; // Új, nagyobb méretû tömb létrehozása

    for (int i = 0; i < size; i++) {
        newStrings[i] = strings[i]; // Stringek másolása az új tömbbe
    }

    newStrings[size] = str; // Új string hozzáadása az új tömbhöz

    delete[] strings; // Régi tömb felszabadítása

    strings = newStrings; // Tömb frissítése az új tömbre
    size++; // Méret növelése
}


void Subject::deleteString(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            strings[i] = strings[i + 1]; // Elemek átmásolása az egy helyel elõbb lévõ pozícióba
        }

        size--; // Méret csökkentése

        string* newStrings = new string[size]; // Új, kisebb méretû tömb létrehozása

        for (int i = 0; i < size; i++) {
            newStrings[i] = strings[i]; // Stringek másolása az új tömbbe
        }

        delete[] strings; // Régi tömb felszabadítása

        strings = newStrings; // Tömb frissítése az új tömbre
    }
    else {
        cout << "Hiba: Tulindexeles." << endl;
    }
}

string& Subject::operator[](int index) {
    if (index >= 0 && index < size) {
        return strings[index]; // Visszaadja az adott indexû stringet
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
    return size; // Visszaadja a tömb méretét
}
