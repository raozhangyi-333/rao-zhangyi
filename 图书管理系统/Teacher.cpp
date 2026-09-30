#include"Teacher.h"
using namespace std;
Teacher::Teacher() {};
Teacher::Teacher(string name1, int id1, string department1, int borrow1) {
	t_name = name1;
	t_id = id1;
	t_department = department1;
	max_borrow = borrow1;
}//初始化教师信息
void Teacher::show()const {
	cout << "name:" << t_name << endl;
	cout << "id:" << t_id << endl;
	cout << "department:" << t_department << endl;
	cout << "max_borrow:" << max_borrow << endl;
}
int Teacher::getid()const {
	return t_id;
};//查询教师信息
void Teacher::borrowbook(Book& book, int borrowbook) {
	if (borrowbook <= 0) cout << "wrong quantity!" << endl;
	else if (book.getstock() >= borrowbook &&
		max_borrow >= borrowbook) {
		book.deplete(borrowbook);
		max_borrow -= borrowbook;
		cout << "succeeded!" << endl;
	}
	else {
		cout << "fail to borrow the book:" << book.getname() << endl;
	}
}//教师借书行为
	void Teacher::returnbook(Book & book, int returnbook1){
		if (returnbook1 <= 0) cout << "wrong quantity!" << endl;
		else {
			book.addstock(returnbook1);
			max_borrow += returnbook1;
			cout << "successed!" << endl;
		}
	} //教师还书行为
bool Teacher::addlikeBook(const Book& book) {
	{
		for (int i = 0;i < likeBook.size();i++)
		{
			if (likeBook[i].getid() == book.getid()) {
				cout << "该书已经收藏，不能重复添加！" << endl;
				return false;
			}
		}
		likeBook.push_back(book);
		cout << "收藏成功！" << endl;
		return true;
	}

}//收藏图书行为

Teacher::~Teacher() {}