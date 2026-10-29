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
	double price;
	string publisher;
public:
    Book();
    Book(int id1, string name1, string author1,
        string publisher1, double price1, int stock1);

    // 返回图书类型码（1一般图书 / 2杂志 / 3电子资源）
    virtual int bookkind() const = 0;

    int getid()const;
    string getname();
    string getauthor()const;
    string getpublisher()const;
    double getprice()const;
    int getstock()const;
    void addstock(int add1);
    void deplete(int dep1);
    bool isIdValid();
    virtual void show() const;
    virtual ~Book();

};
	//所借图书自超期之日起，按每天0.05元的标准收取超期使用费，10日内归还的免收超期使用费；
	// 超期11日(含)以上的图书， 自第11日起，按每天0.1元的标准收取超期使用费；归还日期若处于寒暑假期间，
	// 可在开学后2周内归还，2周内仍未归还的图书，将继续计算超期。