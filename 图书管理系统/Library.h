#include <iostream>
#include <vector>
#include"EResource.h"
#include"GeneralBook.h"
#include"magazine.h"
#include"Student.h"
#include"Teacher.h"
#include <string>
#include"Person.h"
#include "Book.h"   // 包含你的Book基类及派生类头文件
using namespace std;
class Library {
private:
    vector<Person*> PersonList;
    vector<Book*> BookList;
    // 核心数据：图书列表（基类指针容器）
public:
    void addBook();       // 添加图书
    void searchBook();    // 查询图书
    void deleteBook();    // 删除图书
    void showAllBooks();  // 显示全部图书
    void loadBooks();//读取图书
    void saveBooks();   // 保存所有图书到文件 books.txt
    void saveUsers();   // 保存所有用户到 users.txt
    void loadUsers();   // 读取用户
    void showMenu();//图书馆功能菜单
    void run();//系统主循环
    void borrowBook();
    void returnBook();
    void searchUser();
    Person* findUser(string id);
    void addStudent();
    void addTeacher();
    Book* findBook(int id);
    void showMenu_t();
    void showMenu_s();
    void runAdminMenu();   // 图书管理员系统（需密钥）
    void runTeacherMenu();       // 教师端功能菜单
    void runStudentMenu();       // 学生端功能菜单
    Library();
    ~Library();
};