#include <iostream>
#include"Admin.h"
#include"Menu.h"
#include"Stu.h"
using namespace std;
int main(){
	int s = 1, x, i, j;
	Menu menu;
	while (s) {
		menu.menu1();
		cin >> x;
		switch (x) {
		case 1: {
			Admin* admin = new Admin;
			if (admin->load()) {
				menu.menu2();
				i = 1;
				while (i) {
					cin >> i;
					system("cls");
					menu.menu2();
					switch (i) {
					case 1:admin->addDorm(); break;
					case 2:admin->changeDorm(); break;
					case 3:admin->display(); break;
					case 4:admin->deleteDorm(); break;
					case 5:admin->sortDorm(); break;
					case 6:admin->changepassword(); break;
					default:cout << "请在0到6中选择!\n";
					}
				}
				delete admin;
			}
		}
			  break;
		case 2: {
			Stu* stu = new Stu;
			menu.menu3();
			j = 1;
			while (j) {
				cin >> j;
				system("cls");
				menu.menu3();
				switch (j) {
				case 1: stu->display_grades(); break;
				case 2:stu->display_number(); break;
				case 3:stu->query(); break;
				case 4:stu->best(); break;
				case 5:stu->worst(); break;
				default:cout << "请在0到5中选择!\n";
				}
			}
			delete stu;
		}
			  break;
		case 3:return 0;
		}
	}
}