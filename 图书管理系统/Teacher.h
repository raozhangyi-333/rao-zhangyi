#pragma once
#include"Person.h"
using namespace std;
class Teacher : public Person
{
private:
	string t_department;
public:
	Teacher();
	Teacher(string name, int id,string department1);
	void show()const override;
	~Teacher() override;
};