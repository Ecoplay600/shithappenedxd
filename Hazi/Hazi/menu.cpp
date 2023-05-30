#pragma once
#include "menu.h"

using namespace std;

void logo() {
	cout << "################" << endl;
	cout << "Tanszeg Manager" << endl;
	cout << "################" << endl << endl;
}

void dispRemoveSubject(Subject& list) {
	int id;
	list.dispSubject();
	cout << "Ird be a tantargy szamat amit elakarsz tavolitani:" << endl;
	cin >> id;
	if (id <= list.getSize()) {
		list.deleteString(id - 1);
		menucls();
		dispSubjects(list);
	}
	else {
		menucls();
		cout << "Valaszz a megadott listabol!" << endl << endl;
		dispRemoveSubject(list);
	}
}

void dispAddSubject(Subject& list) {
	string subj;
	cout << "Ird be a hozzaadni kivant tantargy nevet:" << endl;
	cin >> subj;
	if (subj != "") {
		list.addString(subj);
	}
	menucls();
	dispSubjects(list);
}


void menucls() {
	system("CLS");
}

void dispTeachers() {
	cout << "igen";
}

void dispSubjects(Subject& list) {
	char val;
	logo();
	list.dispSubject();
	cout << "a. Tantargy hozzaadas" << endl;
	cout << "d. Tantargy eltavolitas" << endl;
	cout << "q. Vissza" << endl;
	cin >> val;
	switch (val) {
	case 'd':
		menucls();
		dispRemoveSubject(list);
		break;
	case 'a':
		menucls();
		dispAddSubject(list);
		break;
	case 'q':
		menucls();
		dispMain(list);
		break;
	default:
		menucls();
		cout << "Valaszz a megadott listabol!" << endl << endl;
		dispSubjects(list);
		break;
	}
}

void dispMain(Subject& list) {
	char val;
	logo();
	cout << "1. Tanarok kilistazasa" << endl;
	cout << "2. Tantargyak kilistazasa" << endl;
	cout << "q. Kilepes" << endl;
	cin >> val;
	switch (val) {
	case '1':
		menucls();
		dispTeachers();
		break;
	case '2':
		menucls();
		dispSubjects(list);
		break;
	case 'q':
		break;
	default:
		menucls();
		cout << "Valaszz a megadott listabol!" << endl << endl;
		dispMain(list);
		break;
	}
}
