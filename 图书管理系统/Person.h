#pragma once
#include <string>
#include <iostream>
#include<vector>
#include "Book.h"
using namespace std;
class Person
{
	protected:
		int id;
		string name;
		int max_borrow = 50;//初始化最大借阅量
		int borrowed_sum;//已借阅书籍数量
		vector<Book> likelist;//组合关系
        vector<Book*> borrowList;   // 书籍指针数组
        vector<int> borrowCount;     // 和上面一一对应，存借阅数量
public:
    Person();
    Person(string name1, int id1);
    // 通用借阅行为：基类实现，子类直接继承复用
    void borrowbook(Book& book, int num);
    void returnbook(Book& book, int num);
    int getid()const;
    int getmax_borrow()const;
    bool addlikeBook(const Book& book);
    // 虚函数：显示信息，子类重写
    virtual void show() const;
    virtual ~Person();
    virtual void run();
    
};