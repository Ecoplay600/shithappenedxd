#include <iostream>
#include <fstream>
#include "teacherlist.h"


teacherlist::teacherlist() : teachers(nullptr), size(0) {}
teacherlist::~teacherlist() {
    ofstream file(privfilename);
    for (int i = 0; i < size; i++) {
        file << teachers[i].getName() << "\n"; // Tanárok kiírása a fájlba, "\n" elválasztóval az órarendjük
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 6; k++) {
                file << teachers[i].getSubj(j, k) << "\n";
            } file << "\n";
        }
    }
    file.close(); // Fájl bezárása
    delete[] teachers; // Tömb felszabadítása
}

void teacherlist::addTeacher(Teacher* T) {
    Teacher* newTeacher = new Teacher[size + 1]; // Új, nagyobb méretû tömb létrehozása

    for (int i = 0; i < size; i++) {
            newTeacher[i] = teachers[i]; // Stringek másolása az új tömbbe
    }
     newTeacher[size] = T[0];

    delete[] teachers; // Régi tömb felszabadítása
    size++;
    teachers = newTeacher; // Tömb frissítése az új tömbre
}

void teacherlist::deleteTeacher(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            teachers[i] = teachers[i + 1]; // Elemek átmásolása az egy helyel elõbb lévõ pozícióba
        }

        size--; // Méret csökkentése

        Teacher* newTeachers = new Teacher[size]; // Új, kisebb méretû tömb létrehozása

        for (int i = 0; i < size; i++) {
            newTeachers[i] = teachers[i]; // Tanárok másolása az új tömbbe
        }

        delete[] teachers; // Régi tömb felszabadítása

        teachers = newTeachers; // Tömb frissítése az új tömbre
    }
    else {
        cout << "Hiba: Tulindexeles." << endl;
    }
}

void teacherlist::readFromFile(const string& filename) {
    privfilename = filename;
    ifstream file(filename); // File megnyitása
    Teacher* temp = new Teacher("sanyi");
    
    if (file.is_open()) {
        string data;
        int i = 0;
        while (getline(file, data, '\n')) {
            
            if (!data.empty()) {
                
                if ((i % 31) == 0) {
                    temp->reName(data);
                    for (int j = 0; j < 5; j++) {
                        for (int k = 0; k < 6; k++) {
                            getline(file, data, '\n');
                            temp->addSubj(j, k, data);
                        }
                    }
                    i += 31;
                    addTeacher(temp);
                }
                
            }
        }

        file.close(); // File bezárása
    }
    else {
        cout << "Hiba: Nem sikerult megnyitni a file-t." << endl;
     }
}

void teacherlist::dispTeacherList() const {
    string days[5] = { "Hetfo","Kedd","Szerda","Csutortok","Pentek" };
    string times[6] = { "8:15-9:45","10:15-11:45","12:15-13:45","14:15-15:45","16:15-17:45","18:15-19:45" };
    for (int i = 0; i < size; i++) {
        cout << teachers[i].getName() << endl;
        for (int j = 0; j < 5; j++) {
            cout << days[j] << "\n";
            for (int k = 0; k < 6; k++) {
                cout << times[k] << " " << "(" << teachers[i].getSubj(j, k) << ")" << " ";
            } cout << endl;
        }
    }
    cout << endl << endl;
}