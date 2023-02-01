#include "Menu.h"
Menu::Menu() {

}
Menu::~Menu() {

}
void Menu::menu1() {
	system("cls");
	cout << "欢迎使用宿舍卫生管理系统!(本系统会在使用前自动读取本地数据哦!)\n";
	cout << "请选择您的身份\n";
	cout << "1.管理员\n";
	cout << "2.客户\n";
	cout << "3.退出\n";
}
void Menu::menu2() {
	system("cls");
	cout << "说明：本系统有自动保存功能当修改，删除或录入后系统会自动保存数据到本地!\n";
	cout << "请输入您所需功能的前缀数字\n";
	cout << "0.返回\n";
	cout << "1.录入信息\n";
	cout << "2.修改信息\n";
	cout << "3.浏览全部信息\n";
	cout << "4.删除信息\n";
	cout << "5.按照总成绩升序输出\n";	
	cout << "6.修改密码\n";
}
void Menu::menu3() {
	system("cls");
	cout << "0.返回\n";
	cout << "1.显示所有的寝室信息（按照宿舍成绩排序）\n";
	cout << "2.显示所有的寝室信息（按照宿舍号排序）\n";
	cout << "3.查询宿舍信息\n";
	cout << "4.本周文明寝室\n";
	cout << "5.本周差评寝室\n";
}