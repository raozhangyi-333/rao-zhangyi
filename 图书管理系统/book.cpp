#include"Book.h"
using namespace std;
Book::Book(){}
Book::Book(int id1, string name1, string author1,
	string publisher1, double price1, int stock1) {
	book_id = id1;
	book_name = name1;
	author = author1;
	publisher = publisher1;
	price = price1;
	stock = stock1;

}//初始化书本
int Book::getstock()const {
	return stock;
}
int Book::getid() const{
	return book_id;
};
string Book::getname() {
	return book_name;
};
void Book::show() const{
	cout << "name:" << book_name << endl;
	cout << "id:" << book_id << endl;
	cout << "publisher:" << publisher << endl;
	cout << "stock:" << stock << endl;
	cout << "price:" << price << endl;
}
//查询书本信息
void Book::addstock(int add1) {
	stock += add1;

}
void Book::deplete(int dep1) {
	stock -= dep1;
}//修改书本信息

bool Book::isIdValid()
{
	if (book_id >= 10000 && book_id <= 19999)
	{
		return true;  // 合法
	}
	else
	{
		return false; // 非法
	}
}

Book::~Book() {}