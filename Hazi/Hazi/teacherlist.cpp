#include "teacherlist.h"

teacherlist::teacherlist() : teachers(nullptr), size(0) {}

void teacherlist::save() {
    ofstream file(privfilename);
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            file << teachers[i].getName() << "\n"; // Tan�rok ki�r�sa a f�jlba, "\n" elv�laszt�val az �rarendj�k
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 6; k++) {
                        file << teachers[i].getSubj(j, k) << "\n";
                    } file << "\n";
                }
        }
        file.close(); // F�jl bez�r�sa
            delete[] teachers; // T�mb felszabad�t�sa
    }
    else
        cout << "Hiba: Nem sikerult megnyitni a file-t." << endl;

}



void teacherlist::addTeacher(Teacher* T) {
    Teacher* newTeacher = new Teacher[size + 1]; // �j, nagyobb m�ret� t�mb l�trehoz�sa

    for (int i = 0; i < size; i++) {
            newTeacher[i] = teachers[i]; // Stringek m�sol�sa az �j t�mbbe
    }
     newTeacher[size] = T[0];

    delete[] teachers; // R�gi t�mb felszabad�t�sa
    size++;
    teachers = newTeacher; // T�mb friss�t�se az �j t�mbre
}

void teacherlist::deleteTeacher(const int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            teachers[i] = teachers[i + 1]; // Elemek �tm�sol�sa az egy helyel el�bb l�v� poz�ci�ba
        }

        size--; // M�ret cs�kkent�se

        Teacher* newTeachers = new Teacher[size]; // �j, kisebb m�ret� t�mb l�trehoz�sa

        for (int i = 0; i < size; i++) {
            newTeachers[i] = teachers[i]; // Tan�rok m�sol�sa az �j t�mbbe
        }

        delete[] teachers; // R�gi t�mb felszabad�t�sa

        teachers = newTeachers; // T�mb friss�t�se az �j t�mbre
    }
    else {
        std::cout << "Hiba: Tulindexeles." << endl;
    }
}

int teacherlist::getSize(){
    return size;
}

void teacherlist::readFromFile() {
    ifstream file(privfilename); // File megnyit�sa
    Teacher* temp = new Teacher("temp");
    
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
        file.close(); // File bez�r�sa
    }
    else {
        std::cout << "Hiba: Nem sikerult megnyitni a file-t." << endl;
     }
}

void teacherlist::delSubj(const int tindex,const int i, const int j) {
    teachers[tindex].delSubj(i, j);
}

void teacherlist::modSubj(const int tindex, const int i, const int j, const string& newsubj) {
    teachers[tindex].editSubj(i, j, newsubj);
}

void teacherlist::dispTeachers() {
    for (int i = 0; i < size; i++) {
        cout << "<" << i + 1 << "> " << teachers[i].getName() << endl;
    }
    if (!size)
        cout << "Nincsen egy tanar sem" << endl;

}

void teacherlist::dispTeacherTimeTable(const int i) const {
    string days[5] = { "Hetfo","Kedd","Szerda","Csutortok","Pentek" };
    string times[6] = { "8:15-9:45","10:15-11:45","12:15-13:45","14:15-15:45","16:15-17:45","18:15-19:45" };
    std::cout << teachers[i].getName() << endl << endl;
        for (int j = 0; j < 5; j++) {
            std::cout << days[j] << "\n";
            for (int k = 0; k < 6; k++) {
                std::cout << times[k] << " " << "(" << teachers[i].getSubj(j, k) << ")" << " ";
            } std::cout << endl;
        } std::cout << endl << endl;
    } 

Teacher& teacherlist::operator[](const int index) {
    return teachers[index];
}
