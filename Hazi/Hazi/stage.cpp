#include "Stage.h"
#include <iostream>

using namespace std;

int Stage::maxIndex = 0;

Stage::Stage() : list(nullptr), objectCount(0) {}

Stage::Stage(const Stage& toCopy) {
	objectCount = toCopy.objectCount;
	if (list != nullptr) {
		delete[] list;
	}
	list = new Teacher * [objectCount];
	for (int i = 0; i < objectCount; i++) {
		list[i] = toCopy.list[i];
	}
}

void Stage::push(Teacher* newElement) {
	Teacher** temp = new Teacher * [objectCount + 1];

	if (temp == nullptr) {
		return;
	}
	int i;
	for (i = 0; i < objectCount; i++) {
		temp[i] = list[i];
	}
	temp[i] = newElement;
	if (list != nullptr) {
		delete[] list;
	}
	list = temp;
	raiseObjectCount();
	return;
}

void Stage::setMaxIndex(const int par) {
	maxIndex = par;
}

void Stage::raiseObjectCount() {
	objectCount++;
}

Stage::~Stage() {
	delete[] list;
	objectCount = 0;
}

void Stage::print() const {
	for (int i = 0; i < objectCount; i++) {
		cout << "<" << i + 1 << ">\t";
		list[i]->print();
	}
}

Teacher* Stage::operator[](const int indexpar) {
	return list[indexpar];
}