#include<iostream>
#include<string>
#include"book.h"
using namespace std;
Book::Book(string id1, string name1, string author1,
	string publisher1, double price1, bool state1) {
	book_id = id1;
	book_name = name1;
	author = author1;
	publisher = publisher1;
	price = price1;
	book_state = state1;
};//创建书本
bool Book::getstate() {
	return book_state;
};//true=已借出, false=在馆
string Book::getnamne() {
	return book_name;
};
string Book::getauthor() {
	return author;
};
string Book::getpublisher() {
	return publisher;
 };
double Book::getprice() {
	return price;
};//查询书本
void Book::addstock(int add1) {
	stock += add1;

};
Book::~Book() {};//析构函数

Student::Student(int num1, string name1,
	string department1, int borrow1) {
	stu_num = num1;
	stu_name = name1;
	stu_department = department1;
	max_borrow = borrow1;


};//创建学生

string Student::getnamne() {
	return stu_name;
};
int Student::getnum() {
	return stu_num;
};
string Student::getdepartment() {
	return stu_department;
};
int Student::getmax_borrow() {
	return max_borrow;
};
Student::~Student() {};
Teacher::Teacher(string name1, int num1, string department1, int borrow1) {
	t_name = name1;
	t_num = num1;
	t_department = department1;
	max_borrow = borrow1;
};
void Teacher::show() {
	cout<<"name:"<< t_name << endl;
	cout << "id:" << t_num << endl;
	cout << "department:" << t_department << endl;
	cout << "max_borrow:" << max_borrow << endl;
};
Teacher::~Teacher() {};