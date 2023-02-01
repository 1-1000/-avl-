#pragma once
#include"Dormitory.h"
#include<vector>
#include <iomanip>
#include<fstream>
class People{
protected:
	vector<Dormitory*>Dorm;
public:
	virtual ~People() {}
};

