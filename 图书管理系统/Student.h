#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Book.h"
using namespace std;
class Student
{
private:
	int stu_num = 0;
	int stu_id;
	string stu_name;
	string stu_department;
	int max_borrow = 0;
	int bookCount;
	vector<Book> likeBook;;//组合关系
public:
	Student();
	Student(int num1,int id1, string name1,
		string department1, int borrow1);
	void show()const;
	int getid()const;
	int getmax_borrow()const;
	void borrowbook(Book& book, int borrowbook);
	void returnbook(Book& book, int returnbook);
	bool addlikeBook(Book& book);
	~Student();
};

