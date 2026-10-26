#include"Person.h"
Person::Person() {}
Person::Person(string name1, int id1) {
	name = name1;
	id = id1;
}//初始化信息
int Person::getid()const {
	return id;
}
int Person::getmax_borrow() const {
	return max_borrow;
}
void Person::show() const{
	cout << "name:" << name << endl;
	cout << "id:" << id << endl;
	cout << "max_borrow:" << max_borrow << endl;
}//展示信息
void Person::borrowbook(Book& book, int borrownum) {
	if (!book.isIdValid()) {
		cout << "wrong input：id " << book.getid() << " 错误！" << endl;
		return;
	}
	if (borrownum <= 0) {
		cout << "wrong quantity!借阅数量必须大于零！" << endl;
		return;
	}
	else if (book.getstock() < borrownum) {
		cout << "fail to borrow the book:" << book.getname() << "，图书库存不足！" << endl;
	}
	
	else if (book.getstock() >= borrownum &&
		max_borrow >= borrownum) {
		// 检查这本书是否已经在借阅列表
		bool found = false;
		for (int i = 0; i < borrowList.size(); i++) {
			if (borrowList[i] == &book) {
				// 已经借过这本书，直接累加数量
				borrowCount[i] += borrownum;
				found = true;
				break;
			}
		}
		if (!found) {
			// 新增一条借阅记录
			borrowList.push_back(&book);
			borrowCount.push_back(borrownum);
		}
		book.deplete(borrownum);
		max_borrow -= borrownum;
		cout << "succeeded!" << endl;
	}
	else {
		cout << "fail to borrow the book:" << book.getname() << "，您的可借额度不足！" << endl;
	}
}//借书行为
void Person::returnbook(Book& book, int returnNum) {
	// 校验图书ID
	if (!book.isIdValid()) {
		cout << "wrong input: id " << book.getid() << "错误！" << endl;
		return;
	}
	// 校验还书数量
	if (returnNum <= 0) {
		cout << "wrong quantity! 还书数量必须大于0" << endl;
		return;
	}

	// 查找这本书在借阅列表中的下标
	int index = -1;
	for (int i = 0; i < borrowList.size(); i++) {
		if (borrowList[i] == &book) {
			index = i;
			break;
		}
	}
	// index == -1 说明没有借这本书
	if (index == -1) {
		cout << "fail to return the book:《" << book.getname() << "》，您没有借阅本书！" << endl;
		return;
	}
	// 获取当前已借数量
	int alreadyBorrow = borrowCount[index];
	if (returnNum > alreadyBorrow) {
		cout << "fail to return the book : 《" << book.getname() << "》，您只借了" << alreadyBorrow << "本！" << endl;
		return;
	}
	else {
		book.addstock(returnNum);
		max_borrow += returnNum;
		cout << "successed!" << endl;
	}
}//还书行为
bool Person::addlikeBook(const Book& book) {
	{
		for (int i = 0;i < likelist.size();i++)
		{
			if (likelist[i].getid() == book.getid()) {
				cout << "该书已经收藏，不能重复添加！" << endl;
				return false;
			}
		}
		likelist.push_back(book);
		cout << "收藏成功！" << endl;
		return true;
	}

}//收藏图书行为
void Person::run() {
	

}
Person::~Person() {}