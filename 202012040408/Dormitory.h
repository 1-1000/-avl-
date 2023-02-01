#pragma once
#include<iostream>
#include<string>
using namespace std;
class Dormitory
{
protected:
	int floor_grades;
	int bed_grades;
	int items_grades;
	int other_grades;
	int sum_grades;
	string number;
	string member[4];
public:
	Dormitory();
	~Dormitory();
	int getFloor_grades();
	int getBed_grades();
	int getItems_grades();
	int getOther_grades();
	int getSum_grades();
	string getNumber();
	string* getMember();
	void setFloor_grades(const int&);
	void setBed_grades(const int&);
	void setItems_grades(const int&);
	void setOther_grades(const int&);
	void setSum_grades(const int&);
	void setNumber(const string&);
	void setMember(const string&,const string&,const string&,const string&);
};

