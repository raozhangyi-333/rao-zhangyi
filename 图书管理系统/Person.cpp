#include"Person.h"
Person::Person() {}
Person::Person(string name1, string id1,int max_borrow1) {
	name = name1;
	id = id1;
	max_borrow = max_borrow1;
}//初始化信息
string Person::getid()const {
	return id;
}
int Person::getmax_borrow() const {
	return max_borrow;
}
string Person::getname()const { 
	return name; }
void Person::setMaxBorrow(int v) { 
	max_borrow = v; }
int Person::borrowDays() const {
	return 30;
}
int Person::getBorrowSize() const { 
	return (int)borrowList.size(); }
Book* Person::getBorrowBook(int i) const {
	return borrowList[i].book;
}
int Person::getBorrowNum(int i) const { 
	return borrowList[i].count; }
int Person::getBorrowDateY(int i) const {
	return int(borrowList[i].borrowDate.year()); }
int Person::getBorrowDateM(int i) const { 
	return unsigned(borrowList[i].borrowDate.month()); }
int Person::getBorrowDateD(int i) const { 
	return unsigned(borrowList[i].borrowDate.day()); }
int Person::getDueDateY(int i) const {
	return int(borrowList[i].dueDate.year()); }
int Person::getDueDateM(int i) const { 
	return unsigned(borrowList[i].dueDate.month()); }
int Person::getDueDateD(int i) const { 
	return unsigned(borrowList[i].dueDate.day()); }
void Person::addBorrowRecord(Book* book, int count,
	int by, int bm, int bd, int dy, int dm, int dd) {
	BorrowRecord r;
	r.book = book;
	r.count = count;
	r.borrowDate = year(by) / month(bm) / day(bd);
	r.dueDate = year(dy) / month(dm) / day(dd);
	borrowList.push_back(r);
}

void Person::show() const{
	cout << "name:" << name << endl;
	cout << "id:" << id << endl;
	cout << "max_borrow:" << max_borrow << endl;
}//展示信息
//==========借书行为=================
void Person::borrowbook(Book& book, int borrownum) {
	if (!book.isIdValid()) {
		cout << "wrong input：id " << book.getid() << " 错误！" << endl;
		return;
	}
	if (borrownum <= 0) {
		cout << "wrong quantity! 借阅数量必须大于零！" << endl;
		return;
	}

	bool isEResource = (book.bookkind() == 3);   // 判断是不是电子资源

	// 电子资源不查库存，普通图书才查库存
	if (!isEResource && book.getstock() < borrownum) {
		cout << "fail to borrow the book:" << book.getname() << "，图书库存不足！" << endl;
		return;
	}
	if (max_borrow < borrownum) {
		cout << "fail to borrow the book:" << book.getname() << "，您的可借额度不足！" << endl;
		return;
	}

	// 登记借阅记录（电子资源和普通图书都要记）
	bool found = false;
	for (int i = 0; i < borrowList.size(); i++) {
		if (borrowList[i].book == &book) {
			borrowList[i].count += borrownum;   // 已借过：只累加数量
			found = true;
			break;
		}
	}
	if (!found) {
		BorrowRecord r;
		r.book = &book;
		r.count = borrownum;
		r.borrowDate = year_month_day{ floor<days>(system_clock::now()) };
		r.dueDate = year_month_day{ sys_days(r.borrowDate) + days(borrowDays()) };
		borrowList.push_back(r);
	}

	// 扣库存（仅普通图书），扣额度（都要扣）
	if (!isEResource) {
		book.deplete(borrownum);   // 电子资源跳过这一步
	}
	max_borrow -= borrownum;
	cout << "succeeded!" << endl;
}
//=================还书行为===============
void Person::returnbook(Book& book, int returnNum) {
	if (!book.isIdValid()) {
		cout << "wrong input: id " << book.getid() << "错误！" << endl;
		return;
	}
	if (returnNum <= 0) {
		cout << "wrong quantity! 还书数量必须大于0" << endl;
		return;
	}

	bool isEResource = (book.bookkind() == 3);   // 和借书函数一样的判断

	// 查找这本书在借阅列表中的下标
	int index = -1;
	for (int i = 0; i < borrowList.size(); i++) {
		if (borrowList[i].book == &book) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "fail to return the book:《" << book.getname() << "》，您没有借阅本书！" << endl;
		return;
	}

	int alreadyBorrow = borrowList[index].count;
	if (returnNum > alreadyBorrow) {
		cout << "fail to return the book : 《" << book.getname() << "》，您只借了" << alreadyBorrow << "本！" << endl;
		return;
	}
	// 超期罚款
	year_month_day today = year_month_day{ floor<days>(system_clock::now()) };
	long overdue = (sys_days(today) - sys_days(borrowList[index].dueDate)).count();
	double fine = 0;
	if (overdue >= 11)
		fine = (10 * 0.05 + (overdue - 10) * 0.1) * returnNum;
	if (fine > 0) {
		overdue_fee += fine;  
		cout << "《" << book.getname() << "》超期 " << overdue
			<< " 天，本次罚款 " << fine << " 元，累计欠费 " << overdue_fee << " 元！" << endl;
	}

	// 加库存、加额度
	if (!isEResource) book.addstock(returnNum);
	max_borrow += returnNum;

	// 还清则删除这条记录，部分还则减数量
	if (returnNum == alreadyBorrow) {
		borrowList.erase(borrowList.begin() + index);
	}
	else {
		borrowList[index].count -= returnNum;
	}
	cout << "successed!" << endl;
}
//===============罚款保存与读写行为===============
double Person::getOverdueFee() const {
	return overdue_fee;
}
void Person::setOverdueFee(double v) {
	overdue_fee = v;
}
void Person::clearOverdueFee() {
	overdue_fee = 0;
	cout << "欠费已清零！" << endl;
}

Person::~Person() {}