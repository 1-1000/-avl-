#include "Admin.h"
using namespace std;
string Admin::password = "111111";
Admin::Admin() {
	string u, b;
	u = "user.txt";
	b = "Adminpassword.txt";
	if (_access(b.c_str(), 0) == -1)
	{
		passwordfilesave();
	}
	else {
		ifstream ifilein("Adminpassword.txt", ios::in);
		if (!ifilein)cout << "open Adminpassword error!" << endl;
		string Password;
		while (!ifilein.eof()) {
			ifilein >> Password;
			Admin::password = Password;
		}
		ifilein.close();
	}
	if (_access(u.c_str(), 0) == -1) {
		petfilesave();
	}
	else
	{
		ifstream ifile("user.txt", ios::in);
		if (!ifile)cout << "open user error!" << endl;
		int Floor_grades, Bed_grades,Items_grades,Other_grades,Sum_grades;
		string Number,Member[4];
		while (!ifile.eof()) {
			a = new Dormitory;
			ifile >> Floor_grades >> Bed_grades >> Items_grades >> Other_grades >> Sum_grades >> Number >> Member[0] >> Member[1] >> Member[2] >> Member[3];
			a->setFloor_grades(Floor_grades);
			a->setBed_grades(Bed_grades);
			a->setItems_grades(Items_grades);
			a->setOther_grades(Other_grades);
			a->setSum_grades(Sum_grades);
			a->setNumber(Number);
			a->setMember(Member[0], Member[1], Member[2], Member[3]);
			Dorm.push_back(a);
		}
		ifile.close();
	}
}
Admin::~Admin() {
	delete a;
}
string Admin::getpassword() {
	return password;
}
void Admin::petfilesave() {
	ofstream ofile("user.txt");
	if (!ofile)
	{
		cout << "open user error!" << endl;
	}
	for (int i = 0; i < Dorm.size(); ++i)
	{
		ofile << Dorm[i]->getFloor_grades() << " "
			<< Dorm[i]->getBed_grades() << " "
			<< Dorm[i]->getItems_grades() << " "
			<< Dorm[i]->getOther_grades() << " "
			<< Dorm[i]->getSum_grades() << " "
			<< Dorm[i]->getNumber() << " "
			<< Dorm[i]->getMember()[0]<<" "
			<< Dorm[i]->getMember()[1]<<" "
			<< Dorm[i]->getMember()[2]<<" "
			<< Dorm[i]->getMember()[3];
		if (i != Dorm.size() - 1)
		{
			ofile << "\n";
		}
	}
	ofile.close();
	cout << "用户信息保存成功!\n";
}
void Admin::passwordfilesave() {
	ofstream ofilein("Adminpassword.txt");
	if (!ofilein) {
		cout << "open admin error!" << endl;
	}
	string Password = password;
	ofilein << Password;
	ofilein << endl;
	ofilein.close();
}
void Admin::display() {
	cout << "总共有" << Dorm.size() << "个宿舍信息\n";
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "地面卫生     床铺卫生     物品摆放     其他     总和     宿舍号     宿舍成员     宿舍成员     宿舍成员     宿舍成员\n";
	for (auto m : Dorm) {
		cout << left << setw(8) << m->getFloor_grades() << "     ";
		cout << left << setw(8) << m->getBed_grades() << "     ";
		cout << left << setw(8) << m->getItems_grades() << "     ";
		cout << left << setw(4) << m->getOther_grades() << "     ";
		cout << left << setw(4) << m->getSum_grades() << "     ";
		cout << left << setw(6) << m->getNumber() << "     ";
		cout << left << setw(8) << m->getMember()[0] << "     ";
		cout << left << setw(8) << m->getMember()[1] << "     ";
		cout << left << setw(8) << m->getMember()[2] << "     ";
		cout << left << setw(8) << m->getMember()[3] << endl;
	}
}
void Admin::addDorm() {
	int n, j = 1;
	int Floor_grades, Bed_grades, Items_grades, Other_grades, Sum_grades;
	string Number, Member[4];
	cout << "请输入待增加的宿舍数目:";
	cin >> n;
	if (n <= 0) {
		cout << "待增加的信息数目不能小于1\n";
		addDorm();
	}
	else
	{
		while (j <= n) {
			int flag = 1;
			cout << "请输入本次增加第" << j << "个宿舍的宿舍号:";
			cin >> Number;
			for (auto m : Dorm) {
				if (m->getNumber() == Number) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				a = new Dormitory;
				a->setNumber(Number);
				cout << "请输入本次增加第" << j << "个宿舍的地面成绩:";
				cin >> Floor_grades;
				a->setFloor_grades(Floor_grades);
				cout << "请输入本次增加第" << j << "个宿舍的床铺成绩:";
				cin >> Bed_grades;
				a->setBed_grades(Bed_grades);
				cout << "请输入本次增加第" << j << "个宿舍的物品成绩:";
				cin >> Items_grades;
				a->setItems_grades(Items_grades);
				cout << "请输入本次增加第" << j << "个宿舍的其他成绩:";
				cin >> Other_grades;
				a->setOther_grades(Other_grades);
				a->setSum_grades(Floor_grades + Bed_grades + Items_grades + Other_grades);
				cout << "请输入本次增加第" << j << "个宿舍的第一个成员:";
				cin >> Member[0];
				cout << "请输入本次增加第" << j << "个宿舍的第二个成员:";
				cin >> Member[1];
				cout << "请输入本次增加第" << j << "个宿舍的第三个成员:";
				cin >> Member[2];
				cout << "请输入本次增加第" << j << "个宿舍的第四个成员:";
				cin >> Member[3];
				a->setMember(Member[0], Member[1], Member[2], Member[3]);
				Dorm.push_back(a);
				Admin::petfilesave();
			}
			else {
				cout << "该宿舍已存在!\n";
				continue;
			}
			j++;
		}
		cout << "信息添加完毕!" << endl;
	}
}
void Admin::deleteDorm() {
	int flag = 0, i = 0;
	string Number;
	cout << "请输入要删除的宿舍:";
	cin >> Number;
	for (auto m : Dorm) {
		if (m->getNumber() == Number) {
			flag = 1;
			Dorm.erase(Dorm.begin() + i);
			cout << "删除成功!" << endl;
			Admin::petfilesave();
			break;
		}
		i++;
	}
	if (!flag) {
		cout << "输入的寝室号有误!\n";
		deleteDorm();
	}
}

void Admin::changeDorm() {
	int a = 1, flag = 0;
	string Number;
	cout << "请输入你要修改信息的宿舍所对应的宿舍号:";
	cin >> Number;
	for (auto m : Dorm) {
		int k = 0;
		if (m->getNumber() == Number) {
			flag = 1;
			cout << "------------------\n";
			cout << "0.返回\n";
			cout << "1.修改地面成绩\n";
			cout << "2.修改床铺成绩\n";
			cout << "3.修改物品成绩\n";
			cout << "4.修改其他成绩\n";
			cout << "5.修改宿舍成员\n";
			cout << "------------------\n";
			while (a) {
				if (!k) {
					cout << "请输入你要修改的信息编号:";
				}
				cin >> a;
				switch (a) {
				case 1: {
					cout << "地面成绩修改为:";
					int Floor_grades;
					cin >> Floor_grades;
					m->setFloor_grades(Floor_grades);
					m->setSum_grades(m->getBed_grades() + m->getFloor_grades() + m->getItems_grades() + m->getOther_grades());
					cout << "修改成功!\n";
					k++;
					break;
				}
				case 2: {
					cout << "床铺成绩修改为:";
					int Bed_grades;
					cin >> Bed_grades;
					m->setBed_grades(Bed_grades);
					m->setSum_grades(m->getBed_grades() + m->getFloor_grades() + m->getItems_grades() + m->getOther_grades());
					cout << "修改成功!\n";
					k++;
					break;
				}
				case 3: {
					cout << "物品成绩修改为:";
					int Items_grades;
					cin >> Items_grades;
					m->setItems_grades(Items_grades);
					m->setSum_grades(m->getBed_grades() + m->getFloor_grades() + m->getItems_grades() + m->getOther_grades());
					cout << "修改成功!\n";
					k++;
					break;
				}
				case 4: {
					cout << "其他成绩修改为:";
					int Other_grades;
					cin >> Other_grades;
					m->setOther_grades(Other_grades);
					m->setSum_grades(m->getBed_grades() + m->getFloor_grades() + m->getItems_grades() + m->getOther_grades());
					cout << "修改成功!\n";
					k++;
					break;
				}
				case 5: {
					cout << "宿舍成员修改为:";
					string Mem[4];
					for (int i = 0; i < 4; i++) {
						cin >> Mem[i];
					}
					m->setMember(Mem[0],Mem[1],Mem[2],Mem[3]);
					cout << "修改成功!\n";
					k++;
					break;
				}
				case 0: {
					system("cls");
					menu.menu2();
					Admin::petfilesave();
					return;
				}
				default:cout << "请在0到5中选择!\n";
				}
			}
		}
	}
	if (!flag)
	{
		cout << "输入宿舍号有误!\n";
		Admin::changeDorm();
	}
}
void Admin::sortDorm() {
	AVL avl;
	AVLnode* root=NIL;
	root = avl.build_AVL_grades(Dorm);
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "地面卫生     床铺卫生     物品摆放     其他     总和     宿舍号     宿舍成员     宿舍成员     宿舍成员     宿舍成员\n";
	avl.InorderTraversal(root);
	avl.clear(root);
}
bool Admin::load() {
	char ch;
	string mima(6, '\0');
	int i = 0;
	cout << "请输入管理员密码:";
	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (i > 0) {
				i--;
				cout << "\b \b";
			}
			else
				cout << "\a";
		}
		else {
			cout << "*";
			mima[i] = ch;
			i++;
		}
	}
	if (mima.compare(Admin::getpassword())) {
		cout << "\n密码错误!\n";
		system("pause");
		return 0;
	}
	else return 1;
}
string inputpassword() {
	char ch;
	int i = 0;
	string mima(6, '\0');
	while ((ch = _getch()) != '\r')
	{
		if (ch == '\b')
		{
			if (i > 0)
			{
				i--;
				cout << "\b \b";
			}
			else
				cout << "\a";
		}
		else
		{
			printf("*");
			mima[i] = ch;
			i++;
		}
	}
	return mima;
}
void Admin::changepassword() {
	string mima1, mima2;
	cout << "请输入你更改后的密码:";
	mima1 = inputpassword();
	cout << endl;
	cout << "请再次确认密码:";
	mima2 = inputpassword();
	if (mima1.compare(mima2)) {
		cout << "\n两次输入密码不同!\n";
		Admin::changepassword();
	}
	else
	{
		password = mima1;
		passwordfilesave();
		cout << "\n修改成功!" << endl;
	}
}
