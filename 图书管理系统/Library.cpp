#include"Library.h"
#include <fstream>
#include <limits>
#include <iostream>
const string ADMIN_KEY = "swust666";   // 管理员密钥，可自行修改
using namespace std;
Library::Library() {}
static string readQuoted(istream& in) {
    char c;
    in >> c;              // 读掉开头的 "
    string s;
    getline(in, s, '"');  // 读到下一个 " 为止
    return s;
}
void Library::showMenu()
{
    cout << "===========图书管理系统===========" << endl;
    cout << "1.增加图书 " << endl;
    cout << "2. 显示全部图书" << endl;
    cout << "3. 查询图书" << endl;
    cout << "4. 删除图书" << endl;
    cout << "0. 退出系统" << endl;
}
void Library::addBook() {
    cout << "============添加新图书===========" << endl;
    cout << "请选择资源类型：" << endl;
    cout << "1. 一般图书" << endl;
    cout << "2. 杂志" << endl;
    cout << "3. 电子资源" << endl;
    cout << "请输入您的选择：";//“”

    int type;
    cin >> type;

    // 通用属性输入
    int id, stock;
    string name, author, publisher;
    double price;
    cout << "请输入图书编号：";
    cin >> id;
    cout << "请输入图书名称：";
    cin.ignore();                 // 清掉上一条 cin>> 留下的换行符
    getline(cin, name);           
    cout << "请输入作者：";
    getline(cin, author);
    cout << "请输入出版社：";
    getline(cin, publisher);
    cout << "请输入价格：";
    cin >> price;
    cout << "请输入库存数量：";
    cin >> stock;

    Book* newBook = nullptr;  // 基类指针接收子类对象

    // 根据类型创建对应子类对象
    switch (type) {
    case 1: {
        string isbn;
        cout << "请输入ISBN号：";
        cin >> isbn;
        newBook = new GeneralBook(id, name, author, publisher, price, stock, isbn);
        break;
    }
    case 2: {
        int issue;
        string issn;
        cout << "请输入期数：";
        cin >> issue;
        cout << "请输入ISSN刊号：";
        cin >> issn;
        newBook = new Magazine(id, name, author, publisher, price, stock, issue, issn);
        break;
    }
    case 3: {
        string format;
        double size;
        cout << "请输入文件格式：";
        cin >> format;
        cout << "请输入文件大小(MB)：";
        cin >> size;
        newBook = new EResource(id, name, author, publisher, price, stock, format, size);
        break;
    }
    default: {
        cout << "类型选择错误，添加失败！" << endl;
        return;
     }
    }
           if (newBook != nullptr) {
               BookList.push_back(newBook);  // 存入成员容器
               cout << "添加成功！" << endl;
           }
    }


// ========== 2. 查询图书功能 ==========
void Library::searchBook() {
    cout << "\n请输入待查询的书籍id：" << endl;
    int search;
    cin >> search;
    bool found = false;

    for (const auto& book : BookList) {
        if (book->getid() == search) {
            book->show();  // 调用虚函数，多态展示
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "没有找到该图书" << endl;
    }
}

// ========== 3. 删除图书功能 ==========
void Library::deleteBook() {
    cout << "\n请输入待删除的书籍id：" << endl;
    int search;
    cin >> search;
    bool found = false;

    for (auto it = BookList.begin(); it != BookList.end(); ) {
        if ((*it)->getid() == search) {
            // 先释放堆内存，再删除容器元素
            delete* it;
            it = BookList.erase(it);
            found = true;
            cout << "删除成功" << endl;
            break;
        }
        else {
            ++it;
        }
    }
    if (!found) {
        cout << "没有找到该图书" << endl;
    }
}
//========显示全部图书==============
void Library::showAllBooks() {
    if (BookList.empty()) {
        cout << "当前没有任何图书！" << endl;
        return;
    }
    cout << "========= 全部图书列表 =========" << endl;
    for (const auto& b : BookList) {
        b->show();   // 虚函数多态：每种资源显示各自信息
        cout << "-----------------------------" << endl;
    }
    cout << "共 " << BookList.size() << " 本图书" << endl;
}
//============保存用户==============
void Library::saveUsers() {
    ofstream fout("users.txt");
    if (!fout.is_open()) {
        cout << "打开 users.txt 失败，无法保存用户！" << endl;
        return;
    }
    for (const auto& p : PersonList) {
        if (Student* s = dynamic_cast<Student*>(p)) {
            fout << "1 " << s->getid() << " \"" << s->getname() << "\" "
                << s->getmax_borrow() << " " << s->getOverdueFee()
                << " \"" << s->getMajor() << "\"";

        }
        else if (Teacher* t = dynamic_cast<Teacher*>(p)) {
            fout << "2 " << t->getid() << " \"" << t->getname() << "\" "
                << t->getmax_borrow() << " " << t->getOverdueFee() 
                << " \"" << t->getDepartment() << "\"";
        }
        // 借阅记录：先写借了几种，再写 (图书id, 数量)
        fout << " " << p->getBorrowSize();
        for (int i = 0; i < p->getBorrowSize(); i++) {
            fout << " " << p->getBorrowBook(i)->getid()
                << " " << p->getBorrowNum(i)
                << " " << p->getBorrowDateY(i)
                << " " << p->getBorrowDateM(i)
                << " " << p->getBorrowDateD(i)
                << " " << p->getDueDateY(i)
                << " " << p->getDueDateM(i)
                << " " << p->getDueDateD(i);
        }

        fout << endl;
    }
    fout.close();
    cout << "用户数据已保存到 users.txt" << endl;
}
//=============读取用户==============
void Library::loadUsers() {
    ifstream fin("users.txt");
    if (!fin.is_open()) {
        return;   // 首次运行文件不存在，正常
    }
    int kind;
    while (fin >> kind) {
        string id;
        int max_borrow, borrowSize;
        string name;
        fin >> id;
        name = readQuoted(fin);
        fin >> max_borrow;
        double overdue_fee;
        fin >> overdue_fee;
        Person* np = nullptr;
        if (kind == 1) {
            string major = readQuoted(fin);
            np = new Student(name, id, major);
        }
        else if (kind == 2) {
            string dept = readQuoted(fin);
            np = new Teacher(name, id, dept);
        }
        else {
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

  
        np->setMaxBorrow(max_borrow);
        np->setOverdueFee(overdue_fee);  

        // 读借阅记录：每一条按图书id在BookList里找回书，重建Book*
        fin >> borrowSize;
        for (int i = 0; i < borrowSize; i++) {
            int bid, cnt, by, bm, bd, dy, dm, dd;
            fin >> bid >> cnt >> by >> bm >> bd >> dy >> dm >> dd;
            Book* b = findBook(bid);
            if (b) np->addBorrowRecord(b, cnt, by, bm, bd, dy, dm, dd);
        }
        PersonList.push_back(np);
    }
    fin.close();
    cout << "已从 users.txt 读取 " << PersonList.size() << " 位用户" << endl;
}
//==============保存图书============
void Library::saveBooks() {
    ofstream fout("books.txt");
    if (!fout.is_open()) {
        cout << "打开 books.txt 失败，无法保存图书！" << endl;
        return;
    }
    for (const auto& b : BookList) {
        fout << b->bookkind();                          // 类型码
        fout << " " << b->getid();                      // id
        fout << " \"" << b->getname() << "\"";          // 书名
        fout << " \"" << b->getauthor() << "\"";        // 作者
        fout << " \"" << b->getpublisher() << "\"";     // 出版社
        fout << " " << b->getprice();                   // 价格
        fout << " " << b->getstock();                   // 库存
        switch (b->bookkind()) {
        case 1: {   // 一般图书
            GeneralBook* gb = dynamic_cast<GeneralBook*>(b);
            fout << " \"" << gb->getIsbn() << "\"";
            break;
        }
        case 2: {   // 杂志
            Magazine* mg = dynamic_cast<Magazine*>(b);
            fout << " " << mg->getIssue();
            fout << " \"" << mg->getIssn() << "\"";
            break;
        }
        case 3: {   // 电子资源
            EResource* er = dynamic_cast<EResource*>(b);
            fout << " \"" << er->getFormat() << "\"";
            fout << " " << er->getSize();
            break;
        }
        }
        fout << endl;
    }
    fout.close();
    cout << "图书数据已保存到 books.txt" << endl;
}

//=============读取图书==============
void Library::loadBooks() {
    ifstream fin("books.txt");
    if (!fin.is_open()) {
        return;   // 首次运行文件不存在
    }
    int kind;
    while (fin >> kind) {
        int id, stock;
        double price;
        string name, author, publisher;
        fin >> id;
        name = readQuoted(fin);
        author = readQuoted(fin);
        publisher = readQuoted(fin);
        fin >> price >> stock;

        Book* nb = nullptr;
        switch (kind) {
        case 1: {
            string isbn = readQuoted(fin);
            nb = new GeneralBook(id, name, author, publisher, price, stock, isbn);
            break;
        }
        case 2: {
            int issue;
            string issn;
            fin >> issue;
            issn = readQuoted(fin);
            nb = new Magazine(id, name, author, publisher, price, stock, issue, issn);
            break;
        }
        case 3: {
            string format;
            double size;
            format = readQuoted(fin);
            fin >> size;
            nb = new EResource(id, name, author, publisher, price, stock, format, size);
            break;
        }
        default:
            fin.ignore(numeric_limits<streamsize>::max(), '\n'); // 跳过未知类型的本行
            break;
        }
        if (nb) BookList.push_back(nb);
    }
    fin.close();
    cout << "已从 books.txt 读取 " << BookList.size() << " 本图书" << endl;
}

    // 按ID查找用户，找不到返回nullptr
    Person* Library::findUser(string id) {
        for (auto& user : PersonList)
        {
            if (user->getid() == id)
            {
                return user;
            }
        }
        return nullptr;
    }

    // 按ID查找图书，找不到返回nullptr
    Book* Library::findBook(int id) {
        for (auto& book : BookList) {
            if (book->getid() == id) {
                return book;
            }
        }
        return nullptr;
    }
    //==========系统内借书程序==========
    void Library::borrowBook() {
        string userId;
        int bookId, borrowNum;
        cout << "请输入用户编号：";
        cin >> userId;
        cout << "请输入图书编号：";
        cin >> bookId;
        cout << "请输入借阅数量：";
        cin >> borrowNum;

        // 复用工具函数查找
        Person* user = findUser(userId);
        Book* book = findBook(bookId);

        if (!user) {
            cout << "错误：未找到对应用户！" << endl;
            return;
        }
        if (!book) {
            cout << "错误：未找到对应图书！" << endl;
            return;
        }

        // 多态调用：自动匹配学生/教师的借阅规则
        user->borrowbook(*book, borrowNum);
    }
    //================系统内还书程序=========
    void Library::returnBook() {
        string userId;
        int bookId, returnNum;
        cout << "请输入用户编号：";
        cin >> userId;
        cout << "请输入图书编号：";
        cin >> bookId;
        cout << "请输入归还数量：";
        cin >> returnNum;

        Person* user = findUser(userId);
        Book* book = findBook(bookId);

        if (!user) {
            cout << "错误：未找到对应用户！" << endl;
            return;
        }
        if (!book) {
            cout << "错误：未找到对应图书！" << endl;
            return;
        }

        // 多态调用：自动匹配对应身份的归还逻辑
        user->returnbook(*book, returnNum);
    }

   
// =============系统主循环============
    void Library::run() {
        int choice;
        while (true) {
            cout << "===== 图书借阅管理系统 =====" << endl;
            cout << "1. 教师身份登录" << endl;
            cout << "2. 学生身份登录" << endl;
            cout << "3. 图书管理员登录" << endl;
            cout << "0. 退出系统" << endl;
            cout << "请选择登录身份：";
            cin >> choice;

            switch (choice) {
            case 1:
                runTeacherMenu();  // 进入教师端完整操作循环
                break;
            case 2:
                runStudentMenu();  // 进入学生端完整操作循环
                break;
            case 3: 
                runAdminMenu(); 
                break;
            case 0:
                cout << "感谢使用图书馆管理系统，再见！" << endl;
                return;
            default:
                cout << "输入错误，请选择 0~2 的选项！" << endl;
                break;
            }
        }
    }

void Library::searchUser() {
    string id;
    cout << "请输入用户编号：";
    cin >> id;

    Person* user = findUser(id);
    if (user) {
        user->show();  // 多态显示：学生显示专业，教师显示部门
    }
    else {
        cout << "未找到对应用户" << endl;
    }
}

// ================教师端主循环=============
void Library::addTeacher() {
    cout << "\n=== 添加教师账号 ===" << endl;

    string name, department;
    string id;

    cout << "请输入教师姓名：";
    cin >> name;
    cout << "请输入工号：";
    cin >> id;
    cout << "请输入所属部门：";
    cin >> department;

    // 动态创建教师对象，向上转型为 Person* 存入统一用户容器
    Person* newTeacher = new Teacher(name, id, department);
    PersonList.push_back(newTeacher);

    cout << "教师账号创建成功！" << endl;
}

void Library::runTeacherMenu() {
    int choice2;
    while (true) {
        showMenu_t();  // 显示教师端功能菜单
        cout << "请输入您的选择：";
        cin >> choice2;

        switch (choice2) {
        case 1:
            addTeacher();    // 添加教师账号
            break;
        case 2:
            searchBook();    // 查询图书
            break;
        case 3:
            borrowBook();    // 借阅图书（通用函数，自动匹配教师规则）
            break;
        case 4:
            returnBook();    // 归还图书
            break;
        case 5:
            searchUser();    // 查询教师信息
            break;
        case 0:
            cout << "已退出教师端，返回身份选择界面" << endl;
            return;  // 退出教师端循环，回到上一层身份选择
        default:
            cout << "输入错误，请选择 0~5 的选项！" << endl;
            break;
        }
    }
}

void Library::showMenu_t()
{
    cout << "==图书馆管理系统==" << endl;
    cout << "1.注册个人信息 " << endl;
    cout << "2. 查询图书" << endl;
    cout << "3. 借阅图书" << endl;
    cout << "4. 归还图书" << endl;         
    cout << "5. 查询个人信息" << endl;
    cout << "0. 退出系统" << endl;
}
void Library::showMenu_s()
{
    cout << "==图书馆管理系统==" << endl;
    cout << "1. 注册个人信息 " << endl;
    cout << "2. 查询图书" << endl;
    cout << "3. 借阅图书" << endl;
    cout << "4. 归还图书" << endl;     
    cout << "5. 查询个人信息" << endl;
    cout << "0. 退出系统" << endl;
}
//============= 学生端主循环===============
void Library::addStudent() {
    cout << "=== 添加学生账号 ===" << endl;

    string name, majorname;
    string id;

    cout << "请输入学生姓名：";
    cin >> name;
    cout << "请输入学号：";
    cin >> id;
    cout << "请输入所在专业：";
    cin >> majorname;

    Person* newStudent = new Student(name, id, majorname);
    PersonList.push_back(newStudent);

    cout << "学生账号创建成功！" << endl;
}

void Library::runStudentMenu() {
        int choice2;
        while (true) {
            showMenu_s();  // 显示功能菜单
            cout << "请输入您的选择：";
            cin >> choice2;

            switch (choice2) {
            case 1:
                addStudent();    // 添加账号
                break;
            case 2:
                searchBook();    // 查询图书
                break;
            case 3:
                borrowBook();    // 借阅图书（通用函数，自动匹配教师规则）
                break;
            case 4:
                returnBook();    // 归还图书
                break;
            case 5:
                searchUser();    // 查询学生信息
                break;
            case 0:
                cout << "已退出学生端，返回身份选择界面" << endl;
                return;  // 退出循环，回到上一层身份选择
            default:
                cout << "输入错误，请选择 0~5 的选项！" << endl;
                break;
            }
        }
    }
//============图书管理员端主循环===========
void Library::runAdminMenu() {
    string key;
    cout << "请输入管理员密钥：";
    cin >> key;
    if (key != ADMIN_KEY) {
        cout << "密钥错误，无权限进入管理员系统！" << endl;
        return;
    }
    cout << "管理员验证通过，进入图书管理系统" << endl;

    while (true) {
        showMenu();   
        cout << "请输入您的选择：";
        int c;
        cin >> c;
        switch (c) {
        case 1: addBook(); break;      // 增加图书
        case 2: showAllBooks(); break; // 显示全部图书
        case 3: searchBook(); break;   // 查询图书
        case 4: deleteBook(); break;   // 删除图书
        case 0:
            cout << "已退出管理员系统" << endl;
            return;
        default:
            cout << "输入错误，请选择 0~4 的选项！" << endl;
            break;
        }
    }
}

Library::~Library() {
    for (auto book : BookList) {
        delete book;          // 释放图书对象
    }
    BookList.clear();

    for (auto p : PersonList) {   // 释放学生/教师对象
        delete p;
    }
    PersonList.clear();
}
