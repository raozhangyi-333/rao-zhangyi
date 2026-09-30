#include"Student.h"
using namespace std;
Student::Student() {}
Student::Student(int num1, int id1,string name1,
	string department1, int borrow1) :stu_num(num1),stu_id(id1)
	, stu_name(name1), stu_department(department1),
	max_borrow(borrow1) {
}//初始化学生信息
int Student::getid()const {
	return stu_id;
}
void Student::show()const {
	cout << "name:" << stu_name << endl;
	cout << "id:" << stu_num << endl;
	cout << "department:" << stu_department << endl;
}//查询学生信息
int Student::getmax_borrow() const{
	return max_borrow;
}
void Student::borrowbook(Book& book, int borrowbook) {
	if (borrowbook <= 0) cout << "wrong quantity!" << endl;
	else if (book.getstock() >= borrowbook &&
		max_borrow >= borrowbook) {
		book.deplete(borrowbook);
		max_borrow -= borrowbook;
		cout << "successed!" << endl;
	}
	else {
		cout << "fail to borrow the book:" << book.getname() << endl;
	};
}//学生借书行为
void Student::returnbook(Book& book, int returnbook) {
	if (returnbook <= 0) cout << "wrong quantity!" << endl;
	else {
		book.addstock(returnbook);
		max_borrow += returnbook;
		cout << "successed!" << endl;
	}
} //学生还书行为
bool Student::addlikeBook(Book& book) 
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
//收藏图书行为

Student::~Student() {};