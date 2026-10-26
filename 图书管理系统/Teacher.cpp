#include"Teacher.h"
using namespace std;
Teacher::Teacher() {};
Teacher::Teacher(string name, int id,  string department1) {
	t_department = department1;
}
void Teacher::show() const{
	Person::show();
	cout << "department:" << t_department << endl;
}
Teacher::~Teacher() {}