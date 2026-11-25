#pragma once
#include <string>
using namespace std;

class Student
{
private:
	string studentId;
	string name;
	float grade;

public:
	Student();
	Student(string id, string studentName, float studentGrade);

	void setStudentId(string id);
	void setName(string n);
	void setGrade(float g);
	void displayInfo() const;
	void increaseGrade(Student* student, float amount);

	string getStudentId() const;
	string getName() const;
	float getGrade() const;

};

void increaseGrade(Student* student, float amount);
Student* findHighestGrade(Student* students, int size);

