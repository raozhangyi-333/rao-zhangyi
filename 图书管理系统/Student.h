#pragma once
#include"Person.h"
using namespace std;
class Student : public Person
{
private:
	string major;
public:
	Student();
	Student(string name1, int id1, string major1);
	void show()const override;
	int getmax_borrow()const;
	
	~Student() override;
};

