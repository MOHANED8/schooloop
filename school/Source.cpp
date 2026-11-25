#include <iostream>
#include "Student.h"
#include <string>
using namespace std;

int main()
{
	int size;
	cout << "Enter the number of students: ";
	while (!(cin >> size) || size <= 0)
	{
		cout << "Please enter a positive whole number: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	Student* students = new Student[size];

	for (int i = 0; i < size; ++i)
	{
		string studentId;
		string name;
		float grade;

		cout << "\nEnter details for student " << i + 1 << ":" << endl;
		cout << "Student ID: ";
		cin >> studentId;
		cout << "Name: ";
		cin >> ws;
		getline(cin, name);

		cout << "Grade (0-100): ";
		while (!(cin >> grade) || grade < 0.0f || grade > 100.0f)
		{
			cout << "Please enter a grade between 0 and 100: ";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		Student* currentStudent = students + i;
		currentStudent->setStudentId(studentId);
		currentStudent->setName(name);
		currentStudent->setGrade(grade);
	}

	cout << "\nAll students:" << endl;
	for (Student* currentStudent = students; currentStudent < students + size; ++currentStudent)
	{
		currentStudent->displayInfo();
		cout << endl;
	}

	Student* highest = findHighestGrade(students, size);
	if (highest != nullptr)
	{
		cout << "Highest grade:" << endl;
		highest->displayInfo();
	}

	int position;
	cout << "\nEnter the student position to update (1-" << size << "): ";
	while (!(cin >> position) || position < 1 || position > size)
	{
		cout << "Please enter a position between 1 and " << size << ": ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	float amount;
	cout << "Enter the grade increase: ";
	while (!(cin >> amount) || amount < 0.0f)
	{
		cout << "Please enter a non-negative amount: ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	Student* selectedStudent = students + (position - 1);
	increaseGrade(selectedStudent, amount);

	cout << "\nUpdated student:" << endl;
	selectedStudent->displayInfo();

	highest = findHighestGrade(students, size);
	if (highest != nullptr)
	{
		cout << "\nHighest grade after update:" << endl;
		highest->displayInfo();
	}

	delete[] students;
	students = nullptr;

	return 0;
}