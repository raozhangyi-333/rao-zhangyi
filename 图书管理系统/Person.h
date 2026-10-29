#pragma once
#include <chrono>
#include <string>
#include <iostream>
#include<vector>
#include "Book.h"
using namespace std;
using namespace std::chrono;
struct BorrowRecord {
    Book* book;
    int count;
    year_month_day borrowDate;
    year_month_day dueDate;
};
class Person
{
	protected:
		string id;
		string name;
        int max_borrow = 0;          // 剩余额度（声明处默认值）
        double overdue_fee = 0.0;    // 累计欠费（未交的罚款总额）
        vector<BorrowRecord> borrowList;
public:
    Person();
    double getOverdueFee() const;   // 查当前累计欠费
    void setOverdueFee(double v);   // 加载文件时恢复欠费
    void clearOverdueFee();         // 欠费清零
    Person(string name1, string id1,int max_borrow1);
    
    // 通用借阅行为
    void borrowbook(Book& book, int num);
    void returnbook(Book& book, int num);
    string getid()const;
    string getname()const;     
    int getmax_borrow()const;
    void setMaxBorrow(int v);         //加载时恢复剩余额度
   
    // 供文件保存读取借阅记录
    int getBorrowSize() const;        // 借了几种书
    Book* getBorrowBook(int i) const; // 第i种是哪本书
    int getBorrowNum(int i) const;    // 第i种借了几本
    void addBorrowRecord(Book* book, int count);//供文件加载时重建借阅记录

    //供读取借阅/归还日期；读取借阅记录
    int getBorrowDateY(int i) const;
    int getBorrowDateM(int i) const;
    int getBorrowDateD(int i) const;
    int getDueDateY(int i) const;
    int getDueDateM(int i) const;
    int getDueDateD(int i) const;
    void addBorrowRecord(Book* book, int count,
        int by, int bm, int bd, int dy, int dm, int dd);
    
    // 虚函数：显示信息，子类重写
    virtual void show() const;
    virtual int borrowDays() const;
    virtual ~Person();
    
};