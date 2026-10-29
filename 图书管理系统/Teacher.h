#pragma once
#include"Person.h"
using namespace std;
class Teacher : public Person
{
private:
	string t_department;
public:
	Teacher();
	Teacher(string name, string id,string department1);
	string getDepartment() const;
	void show()const override;
	int borrowDays() const override;
	~Teacher() override;
};