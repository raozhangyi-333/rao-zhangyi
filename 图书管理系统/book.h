#pragma once
#include<iostream>
#include<string>
using namespace std;
class Book
{
protected:
	int book_id;
	string book_name;
	int stock;
	string author;
	int price;
	string publisher;
public:
	Book();
	Book(int id1, string name1, string author1,
		string publisher1, double price1, int stock1);
	int getid()const;
	string getname();
	int getstock()const;
	void addstock(int add1);
	void deplete(int dep1);
	bool isIdValid();
	virtual void show() const;
	virtual ~Book();
};
//侧重点在于借阅管理

	//所借图书自超期之日起，按每天0.05元的标准收取超期使用费，10日内归还的免收超期使用费；
	// 超期11日(含)以上的图书， 自第11日起，按每天0.1元的标准收取超期使用费；归还日期若处于寒暑假期间，
	// 可在开学后2周内归还，2周内仍未归还的图书，将继续计算超期。

//改动：基类book只保留通用特性和各子类通用函数
