#include <iostream>
#include<vector>
#include<fstream>
#include<stack>

using namespace std;
ifstream f("Students.txt");

struct Student
{
	string firstName, lastName;
	int yearOfStudy;
	int numarMaterii;
	struct CalendaristicDate
	{
		int zi, luna, an;
	} dateOfBirth;
	struct Grade
	{
		char numeMaterie[15];
		float nota;
	};
	Grade grades[3];
	enum StudyProgram
	{
		ID,
		IF,
		IFR
	}studyProgram;
	friend ifstream& operator>>(ifstream& input, Student& student)
	{
		input >> student.firstName >> student.lastName;
		input >> student.yearOfStudy;
		input >> student.dateOfBirth.zi >> student.dateOfBirth.luna >> student.dateOfBirth.an;
		int studiu;
		input >> studiu;
		student.studyProgram = static_cast<StudyProgram>(studiu);
		input >> student.numarMaterii;
		for (int i = 0; i < student.numarMaterii; i++) {
			input >> student.grades[i].numeMaterie;
			input >> student.grades[i].nota;

		}
		return input;
	}
	friend ostream& operator << (ostream& output, Student& student)
	{
		output << student.firstName << " " << student.lastName << " " << student.yearOfStudy << " " << student.dateOfBirth.zi << " " << student.dateOfBirth.luna << " " << student.dateOfBirth.an << " ";

		for (int i = 0; i < student.numarMaterii; i++)
		{
			output << student.grades[i].numeMaterie << " " << student.grades[i].nota << " ";


		}
		return output;

	}

	float operator /(Student& s)
	{
		int Suma = 0;
		for (int i = 0; i < s.numarMaterii; i++)
			Suma = Suma + s.grades[i].nota;
		return static_cast<float>(Suma) / s.numarMaterii;
	}
};

int main()
{
	int n;
	f >> n;
	Student elevi[10];
	char SubpunctEx;

	for (int i = 0; i < n; i++)
	{
		f >> elevi[i];
	}

	do
	{
		cout << "Subpunctul: ";
		cin >> SubpunctEx;
		switch (SubpunctEx)
		{
		case 'a':
		{
			for (int i = 0; i < n; i++)
			{
				cout << elevi[i] << endl;
			}
			break;
		}

		case 'b':
		{
			int ok = 0;
			cout << "Studenti cu numele Popescu: " << endl;
			for (int i = 0; i < n; i++)
			{
				if (elevi[i].lastName == "Popescu")
				{
					ok++;
					cout << elevi[i].firstName << " " << elevi[i].lastName << endl;
				}
			}
			if (ok == 0)
				cout << "0" << endl;
			break;
		}


		case 'c':
		{
			int ok = 0;
			cout << "Studenti nascuti in luna Mai: " << endl;
			for (int i = 0; i < n; i++)
			{
				if (elevi[i].dateOfBirth.luna == 5)
				{
					ok++;
					cout << elevi[i].firstName << " " << elevi[i].lastName << " " << elevi[i].dateOfBirth.zi << " " << elevi[i].dateOfBirth.luna << " " << elevi[i].dateOfBirth.an << endl;
				}

			}
			if (ok == 0)
				cout << "0" << endl;
			break;
		}


		case 'd':
		{
			int ok = 0;
			cout << "Studeti care au zodia Rac: " << endl;
			for (int i = 0; i < n; i++)
			{
				if ((elevi[i].dateOfBirth.luna == 6 && elevi[i].dateOfBirth.zi >= 22) || (elevi[i].dateOfBirth.luna == 7 && elevi[i].dateOfBirth.zi <= 22))
				{
					ok++;
					cout << elevi[i].firstName << " " << elevi[i].lastName << " " << elevi[i].dateOfBirth.zi << " " << elevi[i].dateOfBirth.luna << " " << elevi[i].dateOfBirth.an << endl;
				}
			}
			if (ok == 0)
				cout << "0" << endl;
			break;
		}

		case 'e':
		{
			int ok = 0;
			cout << "Studenti la IF: " << endl;
			for (int i = 0; i < n; i++)
			{
				if (elevi[i].studyProgram == 1)
				{
					ok++;
					cout << elevi[i].firstName << " " << elevi[i].lastName << endl;
				}

			}
			if (ok == 0)
				cout << "0" << endl;
			break;
		}

		case 'f':
		{

			int ID = 0, IF = 0, IFR = 0;
			for (int i = 0; i < n; i++)
			{
				if (elevi[i].studyProgram == 0)
					ID++;
				if (elevi[i].studyProgram == 1)
					IF++;
				if (elevi[i].studyProgram == 2)
					IFR++;
			}
			cout << "Studenti la programul ID: " << ID << endl;
			cout << "Studenti la programul IF: " << IF << endl;
			cout << "Studenti la programul IFR: " << IFR << endl;
			break;
		}

		case 'g':
		{
			for (int i = 0; i < n; i++)
			{

			}

		}


		case 'h':
		{
			string materie;
			cout << "Materia: ";
			cin >> materie;
			int pozitia = 0, pozitienota = 0, ok = 0;
			int min = 10;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < elevi[i].numarMaterii; j++)
				{
					if (elevi[i].grades[j].numeMaterie == materie && elevi[i].grades[j].nota <= min)
					{
						min = elevi[i].grades[j].nota;
						pozitia = i;
						pozitienota = j;
						ok++;
					}
				}
			if (ok == 0)
				cout << "Nu exista studenti la materia " << materie << endl;
			else
				cout << "Studentul cu cea mai mica nota la materia " << materie << " este " << elevi[pozitia].firstName << " " << elevi[pozitia].lastName << " " << elevi[pozitia].grades[pozitienota].nota << endl;

			break;
		}


		case 'i':
		{
			for (int i = 0; i < n; i++)
			{
				cout << "Media studentului " << elevi[i].firstName << " " << elevi[i].lastName << " " << elevi[i].operator/(elevi[i]) << endl;
			}
			break;
		}


		}
	} while (SubpunctEx != '0');
	return 0;
}