#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Book.h"
using namespace std;
class Teacher
{
private:
	string t_name;
	int t_id;
	string t_department;
	int max_borrow;
	vector<Book> likeBook;//组合关系
public:
	Teacher();
	Teacher(string name1, int id1, string department1, int borrow1);
	void show()const;
	int getid()const;
	void borrowbook(Book& book, int borrowbook);
	void returnbook(Book& book, int returnbook1);
	bool addlikeBook(const Book& book);
	~Teacher();
};