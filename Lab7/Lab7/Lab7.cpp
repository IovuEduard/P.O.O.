#include"Dog.h"
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	int x;
	CalendaristicDate Date1(15, 10, 2020), Date2(8, 4, 2019), Date3(9, 2, 2022);
	char* a2 = new char[20];
	char* b2 = new char[20];
	char* c2 = new char[20];
	char* a1 = new char[20];
	char* b1 = new char[20];
	char* c1 = new char[20];
	strcpy(a1, "Max");
	strcpy(b1, "Rex");
	strcpy(c1, "Luky");
	strcpy(a2, "Chris Daniels");
	strcpy(b2, "Richard Jefferson");
	strcpy(c2, "Blake Griffin");
	Dog dog1(a1, a2, Date1, Bulldog, vaccine1), dog2(b1, b2, Date2, Labrador, AnnualVaccine), dog3(c1, c2, Date3, Bulldog, vaccine2);
	do {
		cout << "Subpunctul:";
		cin >> x;
		switch (x)
		{
		case 1:
		{
			CalendaristicDate date1(25, 10, 2021), date2(3, 1, 2023);
			char* a = new char[20];
			char* b = new char[20];
			char* c = new char[20];
			char* d = new char[20];
			strcpy(a, "Sasha");
			strcpy(b, "John Snow");
			strcpy(c, "Nicky");
			strcpy(d, "Marie Lu");
			Dog d1(a, b, date1, Bulldog, vaccine1), d2(c, d, date2, Labrador, vaccine2);
			Dog d3 = d1;
			d1.setName("Kim");
			cout << "Dog 1:" << d1 << '\n';
			cout << "Dog 2:" << d2 << '\n';
			cout << "Dog 3:" << d3 << '\n';
			d2 = d3;
			d2.setOwnerName("Xhu Xiang");
			d3.vaccines = Vaccines::vaccine2;
			cout << "Dog 1:" << d1 << '\n';
			cout << "Dog 2:" << d2 << '\n';
			cout << "Dog 3:" << d3 << '\n';
			break;
		}

		case 2:
			
		{
			verif_rasa(Bulldog, dog1, dog2, dog3);
			break;
		}

		case 3:
		{
			cout << "Cainele are ";
			Human_Years(dog1);
			cout << " ani, in ani omenesti. \n";
			break;
		}

		case 4:
			
			cout << "Cainele are ";
			Dog_Years(dog1);
			cout<< " ani, in dog years. \n";
			break;
			
		}
		} while (x);
	
	return 0;
	
}