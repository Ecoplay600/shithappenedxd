#pragma once
#include "menu.h"

using namespace std;

menu::menu() {
	sl.readFromFile();
	tl.readFromFile();
}

void menu::logo() {
	cout << "################" << endl;
	cout << "Tanszeg Manager" << endl;
	cout << "################" << endl << endl;
}

void menu::menucls() {
	system("CLS");
}

void menu::dispAddSubject() {
	string subj;
	cout << "Ird be a hozzaadni kivant tantargy nevet:" << endl;
	cin >> subj;
	if (subj != "") {
		sl.addString(subj);
	}
	menucls();
	dispSubjects();
}

void menu::dispRemoveSubject() {
	int id;
	sl.dispSubject();
	cout << "Ird be a tantargy szamat amit elakarsz tavolitani:" << endl;
	cin >> id;
	if (id <= sl.getSize()) {
		sl.deleteString(id - 1);
		menucls();
		dispSubjects();
		return;
	}
	else {
		menucls();
		cout << "Valaszz a megadott listabol!" << endl << endl;
		dispRemoveSubject();
		return;
	}
}

void menu::dispAddTeacher() {
	string subj;
	Teacher temp("temp");
	cout << "Ird be a hozzaadni kivant tantargy nevet:" << endl;
	cin >> subj;
	if (subj != "") {
		temp.reName(subj);
		tl.addTeacher(&temp);
	}
	menucls();
	dispTeachers();
	return;
};

void menu::dispRemoveTeacher() {
	cout << "Ird be a szamat a tanarnak amelyiket torolni akarod" << endl;
	tl.dispTeachers();
	string val;
	cin >> val;
	if (stoi(val) <= tl.getSize()) {
		tl.deleteTeacher(stoi(val));
		menucls();
		dispTeachers();
		return;
	}
	else
		menucls();
		cout << "A listabol valaszz szamot!" << endl;
		dispRemoveTeacher();
		return;
}

void menu::dispEditSubj(const int tindex) {
	cout << "Melyik napon van az ora amin valtoztatni akarsz?" << endl << endl;
	cout << "<1> Hetfo" << endl << "<2> Kedd" << endl << "<3> Szerda" << endl << "<4> Csutortok" << endl << "<5> Pentek" << endl << endl;
	string val;
	int i;
	int j;
	cin >> val;
	if (stoi(val) < 6) {
		i = int (stoi(val)-1);
		menucls();
		cout << "Melyik idopontban?" << endl;
		cout << "<1> 8:15-9:45" << endl << "<2> 10:15 - 11:45" << endl << "<3> 12:15 - 13:45" << endl << "<4> 14:15 - 15:45" << endl;
		cout << "<5> 16:15 - 17:45" << endl << "<6> 18:15 - 19:45" << endl;
		cin >> val;
		if (stoi(val) < 7) {
			j = int(stoi(val)-1);
			menucls();
			cout << "Mire akarod cserelni?" << endl;
			sl.dispSubject();
			cout << endl;
			cin >> val;
			if (stoi(val) < sl.getSize()) {
				val = sl[stoi(val) - 1];
				tl[tindex].editSubj(i, j, val);
				menucls();
				dispTeachers();
				return;
			}

		}

	} 
}

void menu::dispDelSubj(const int tindex) {
	cout << "Melyik napon van az ora amin valtoztatni akarsz?" << endl << endl;
	cout << "<1> Hetfo" << endl << "<2> Kedd" << endl << "<3> Szerda" << endl << "<4> Csutortok" << endl << "<5> Pentek" << endl << endl;
	string val;
	int i;
	int j;
	cin >> val;
	if (stoi(val) < 6) {
		i = int(stoi(val));
		menucls();
		cout << "Melyik idopontban levo tanorat akarod torolni?" << endl;
		cout << "<1> 8:15-9:45" << endl << "<2> 10:15 - 11:45" << endl << "<3> 12:15 - 13:45" << endl << "<4> 14:15 - 15:45" << endl;
		cout << "<5> 16:15 - 17:45" << endl << "<6> 18:15 - 19:45" << endl;
		cin >> val;
		if (stoi(val) < 7) {
			j = int(stoi(val));
			tl.delSubj(tindex, i-1, j-1);
			menucls();
			dispTeachers();
		}

	}
}

void menu::dispTeachers() {
	logo();
	for (int i = 0; i < tl.getSize(); i++) {
		cout << "<" << i + 1 << ">" << " " << tl[i].getName() << endl;
	}
	string val;
	cout << endl << "<a> Tanar hozzaadas" << endl;
	cout << "<d> Tanar eltavolitas" << endl;
	cout << "<q> Vissza" << endl;
	cin >> val;
	if (val == "q") {
		menucls();
		dispMain();
		return;
	}
	else if (val == "a") {
		menucls();
		dispAddTeacher();
		return;
	}
	else if (val == "d") {
		menucls();
		dispRemoveTeacher();
		return;
	}
	if (stoi(val) <= tl.getSize()) {
		menucls();
		int tindex (stoi(val) - 1);
		tl.dispTeacherTimeTable(stoi(val) - 1);
		cout << "<e> Ora modositas" << endl;
		cout << "<d> Ora eltavolitas" << endl;
		cout << "<q> Vissza" << endl;
		cin >> val;
		if (val == "q") {
			menucls();
			dispMain();
			return;
		}
		else if (val == "e") {
			menucls();
			dispEditSubj(tindex);
			return;
		}
		else if (val == "d") {
			menucls();
			dispDelSubj(tindex);
			return;
		}
	}
}



	void menu::dispSubjects() {
		char val;
		logo();
		sl.dispSubject();
		cout << "<a> Tantargy hozzaadas" << endl;
		cout << "<d> Tantargy eltavolitas" << endl;
		cout << "<q> Vissza" << endl;
		cin >> val;
		switch (val) {
		case 'd':
			menucls();
			dispRemoveSubject();
			return;
		case 'a':
			menucls();
			dispAddSubject();
			return;
		case 'q':
			menucls();
			dispMain();
			return;
		default:
			menucls();
			cout << "Valaszz a megadott listabol!" << endl << endl;
			dispSubjects();
			return;
		}
}

void menu::dispMain() {
	char val;
	logo();
	cout << "<1> Tanarok kilistazasa" << endl;
	cout << "<2> Tantargyak kilistazasa" << endl;
	cout << "<q> Kilepes" << endl;
	cin >> val;
	switch (val) {
	case '1':
		menucls();
		dispTeachers();
		break;
	case '2':
		menucls();
		dispSubjects();
		break;
	case 'q':
		tl.save();
		sl.save();
		return;
	default:
		menucls();
		cout << "Valaszz a megadott listabol!" << endl << endl;
		dispMain();
		break;
	}
}
