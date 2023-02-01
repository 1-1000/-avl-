#pragma once
#include "People.h"
#include"Menu.h"
#include"AVL.h"
#include<cstdlib>
#include<algorithm>
#include <direct.h>
#include<conio.h>
#include<io.h>
class Admin :public People
{
private:
	static string password;
	Menu menu;
	Dormitory* a = NULL;
	void petfilesave();
	void passwordfilesave();
public:
	Admin();
	~Admin();
	static string getpassword();
	bool load();
	void display();
	void addDorm();
	void deleteDorm();
	void changeDorm();
	void sortDorm();
	void changepassword();
};