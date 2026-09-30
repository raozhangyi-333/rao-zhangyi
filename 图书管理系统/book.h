#pragma once
#include<iostream>
#include<string>
using namespace std;
class Book
{
private:
	int book_id;
	string book_name;
	string author;
	string publisher;
	double price;
	int stock;
public:
	Book();
	Book(int id1, string name1, string author1,
		string publisher1, double price1, int stock1);
	int getid()const;
	string getname();
	int getstock()const;
	void addstock(int add1);
	void deplete(int dep1);
	bool check_id(int id1) const;//检查id合法性
	void show()const;
	~Book();
};
