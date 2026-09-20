#include<string>
using namespace std;
class Book
{
private:
	string book_id;
	string book_name;
	string author;
	string publisher;
	double price;
	bool book_state;
	int stock;
public:
	Book(string id1, string name1, string author1,
		string publisher1, double price1, bool state1);
	//创建书本
	bool getstate();
	string getnamne();
	string getauthor();
	string getpublisher();
	double getprice();//查询书本
	void addstock(int add1);//添加库存
	~Book();
};//图书信息管理
class Student
{
private:
	//学号，姓名，院系，最大借阅图书数量属性等
	int stu_num = 0;
	string stu_name;
	string stu_department;
	int max_borrow = 0;
public:
	Student(int num1, string name1,
		string department1, int borrow1);//创建学生
	
	string getnamne();
	int getnum();
	string getdepartment();
	int getmax_borrow();//查询学生
	~Student();

};
class Teacher
{
private:
	string t_name;
	int t_num;
	string t_department;
	int max_borrow;
public:
	Teacher(string name1, int num1, string department1, int borrow1);
	void show();
}
	//教师基本信息包括工号，姓名，院系，最大借阅图书数量属性，

		/*实现一个简单的图书馆借阅管理系统，管理维护已有图书资源，图书资源有不同的类型，有一般图书，杂志，电子资源等。不同资源有不同的属性和操作。
1) 增加新的图书或资源
2) 增加已有图书或资源的数量
3) 显示某一图书或资源情况，根据资源类型不同显示的信息也不一样。
4) 显示所有图书或资源情况。
5) 减少已有图书或资源的数量。
6) 删除某一图书或资源。
7) 学生借阅图书或资源
8) 学生归还图书或资源*/




