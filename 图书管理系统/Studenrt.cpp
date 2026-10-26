#include"Student.h"
using namespace std;
Student::Student() {}
Student::Student(string name1, int id1, string major1){
	major = major1;
}//初始化学生信息

void Student::show()const {
	Person::show();
	cout << "major:" << major << endl;
}//查询学生信息


Student::~Student() {};