#include"Student.h"
using namespace std;
Student::Student() : Person() {}
Student::Student(string name1, string id1, string major1)
	: Person(name1, id1, 10),  major(major1) {
}
string Student::getMajor() const {
	return major; }
int Student::borrowDays() const {
	return 30; }

void Student::show()const {
	Person::show();
	cout << "major:" << major << endl;
}//查询学生信息


Student::~Student() {};