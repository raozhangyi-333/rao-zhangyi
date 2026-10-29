#include"Teacher.h"
using namespace std;
Teacher::Teacher() : Person() {}
Teacher::Teacher(string name, string id, string department1)
	: Person(name, id, 50),  t_department(department1) {
}
string Teacher::getDepartment() const { 
	return t_department; }
int Teacher::borrowDays() const { 
	return 60; }   // 教师借期60天

void Teacher::show() const{
	Person::show();
	cout << "department:" << t_department << endl;
}
Teacher::~Teacher() {}