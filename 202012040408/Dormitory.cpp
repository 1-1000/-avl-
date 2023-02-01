#include "Dormitory.h"
using namespace std;
Dormitory::Dormitory() {
	floor_grades = 0;
	bed_grades = 0;
	items_grades = 0;
	other_grades = 0;
	sum_grades = 0;
	number = '/0';
	for (int i = 0; i < 4; i++) {
		member[i] = '\0';
	}
}
Dormitory::~Dormitory(){}
int Dormitory::getFloor_grades() {
	return this->floor_grades;
}
int Dormitory::getBed_grades() {
	return this->bed_grades;
}
int Dormitory::getItems_grades() {
	return this->items_grades;
}
int Dormitory::getOther_grades() {
	return this->other_grades;
}
int Dormitory::getSum_grades() {
	return this->sum_grades;
}
string Dormitory::getNumber() {
	return this->number;
}
string* Dormitory::getMember() {
	return this->member;
}
void Dormitory::setFloor_grades(const int&floorgrades) {
	this->floor_grades = floorgrades;
}
void Dormitory::setBed_grades(const int& bedgrades) {
	this->bed_grades = bedgrades;
}
void Dormitory::setItems_grades(const int& itemsgrades) {
	this->items_grades = itemsgrades;
}
void Dormitory::setOther_grades(const int& othergrades) {
	this->other_grades = othergrades;
}
void Dormitory::setSum_grades(const int& sumgrades) {
	this->sum_grades = sumgrades;
}
void Dormitory::setNumber(const string& Number) {
	this->number = Number;
}
void Dormitory::setMember(const string& Mem1, const string& Mem2, const string& Mem3, const string& Mem4) {
	this->member[0] = Mem1;
	this->member[1] = Mem2;
	this->member[2] = Mem3;
	this->member[3] = Mem4;
}