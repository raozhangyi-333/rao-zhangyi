#pragma once
#include"Person.h"
using namespace std;
class Student : public Person
{
private:
	string major;
public:
	Student();
	Student(string name1, string id1, string major1);
	string getMajor() const;  
	int borrowDays() const override;
	void show()const override;
	~Student() override;
};

