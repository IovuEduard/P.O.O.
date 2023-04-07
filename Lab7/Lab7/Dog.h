#pragma once
#pragma warning(disable : 4996)
#include "DateOfBirth.h"
#include<fstream>
#include<iostream>
using namespace std;
 ifstream f("Bread.txt");
enum Bread {
	Bulldog,
	Labrador,
	Poodle
};
enum Vaccines {
	AnnualVaccine,
	vaccine1,
	vaccine2
};
class Dog {
public:
	Bread bread;
	char* name;
	char* ownerName;
	CalendaristicDate dateOfBirth;
	Vaccines vaccines;
	void setName(const char* c) {
		strcpy(this->name, c);
	}
	void setOwnerName(const char* c) {
		strcpy(this->ownerName, c);
	}
	Dog(char* name, char* ownerName, CalendaristicDate date, Bread bread, Vaccines vaccines) :name(name), ownerName(ownerName), dateOfBirth(date), bread(bread), vaccines(vaccines) {}
	friend  ostream& operator<<( ostream& output, const  Dog& d) {
		output << d.name << " " << d.bread << " " << d.dateOfBirth << " " << d.ownerName << " " << d.vaccines;
		return output;
	}
	friend  istream& operator>>( istream& input, Dog& d) {
		input >> d.name >> d.dateOfBirth;
		int x;
		f >> x;
		d.bread = static_cast<Bread>(x);
		input >> d.ownerName;
		return input;
	}
	Dog() = default;

};
void verif_rasa(Bread bread, Dog d1, Dog d2, Dog d3)
{
	if (d1.bread == bread)
		cout << d1 << '\n';
	if (d2.bread == bread)
		cout << d2 << '\n';
	if (d3.bread == bread)
		cout << d3 << '\n';
}
void Human_Years(Dog d)
{
	
	cout<< 2023 - d.dateOfBirth.an;
}
void Dog_Years(Dog d)
{

	cout << (2023 - d.dateOfBirth.an)*7;
}