#pragma once
#include "People.h"
#include"Menu.h"
#include"AVL.h"
#include"Dormitory.h"
class Stu :public People{
private:
	Dormitory* a = NULL;
	Menu menu;
	AVL avl;
public:
	Stu();
	~Stu();
	void display_grades();
	void display_number();
	void query();
	void best();
	void worst();
};