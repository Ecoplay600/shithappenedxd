#pragma once
#include "teacher.h"

class Stage {
private:
	static int maxIndex;
	int objectCount;
	Teacher** list{};

public:
	Stage();
	Stage(const Stage&);
	~Stage();

	inline static int getMaxindex() { return maxIndex; }
	inline int getObjectCount() const { return objectCount; }

	void push(Teacher*);

	static void setMaxIndex(const int);
	void raiseObjectCount();
	void print() const;

	Teacher* operator[](const int);
};