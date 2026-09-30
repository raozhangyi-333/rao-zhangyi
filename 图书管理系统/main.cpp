#include"Book.h"
#include"Teacher.h"
#include"Student.h"
using namespace std;
void showMenu_s()
{
    cout << "==图书馆管理系统==" << endl;
    cout << "1.注册个人信息 " << endl;
    cout << "2. 查询图书" << endl;
    cout << "3. 借阅图书" << endl;
    cout << "4. 归还图书" << endl;
    cout << "5. 查询个人信息" << endl;
    cout << "0. 退出系统" << endl;
}
void showMenu_t()
{
    cout << "==图书馆管理系统==" << endl;
    cout << "1. 注册个人信息" << endl;
    cout << "2. 查询图书" << endl;
    cout << "3. 借阅图书" << endl;
    cout << "4. 归还图书" << endl;
    cout << "5. 查询个人信息" << endl;
    cout << "0. 退出系统" << endl;
   
}
void showMenu()
{
    cout << "==图书管理系统==" << endl;
    cout << "1.增加图书 " << endl;
    cout << "2. 查询图书" << endl;
    cout << "3. 删除图书" << endl;
    cout << "0. 退出系统" << endl;
}
int main() 
{
    vector<Student> studentlist;//学生列表
    vector<Book> booklist;//存放图书
    vector<Teacher> teacherlist;//教师列表
    int choice1,choice2;
    while (true)
    {
        cout << "==图书管理系统==" << endl;
        cout << "1.图书管理员登录" << endl;
        cout << "2.教师登录" << endl;
        cout << "3.学生登录" << endl;
        cout << "==请输入您的选择==" << endl;
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            showMenu();
            cout << "请输入您的选择：";
            cin >> choice2;
            switch (choice2) {
                Book b1();
            case 1:
            {
                cout << "请添加书籍信息" << endl;
                int id1, stock1;
                string name1, author1, publisher1;
                double price1;
                cin >> id1 >> name1 >> author1 >> publisher1 >> price1 >> stock1;
                Book b1(id1, name1, author1, publisher1, price1, stock1);
                //4.把对象存入vector容器保存
                booklist.push_back(b1);
                break;
            }
            case 2:
            {
                cout << "请输入待查询的书籍id" << endl;
                int search;
                cin >> search;
                bool found = false;
                for (const auto& b1 : booklist)
                {
                    if (b1.getid() == search) {
                        b1.show();
                        found = true;
                        break;
                    }
                }
                if (!found)cout << "没有找到该图书";
                break;
            }
            case 3:
            {
                cout << "请输入待删除的书籍id" << endl;
                int search;
                cin >> search;
                bool found = false;
                for (auto it = booklist.begin();it != booklist.end();)
                {
                    if (it->getid() == search) {
                        booklist.erase(it);
                        found = true;
                        cout << "删除成功" << endl;
                        break;
                    }
                }
                if (!found) cout << "没有找到该图书" << endl;
                break;
            }
            case 0:
                cout << "退出图书馆管理系统，再见！" << endl;
                return 0;
            default:
                cout << "输入错误，请选择 0~3 的选项！" << endl;
                break;
            }
        case 2:
            showMenu_t();
            cout << "请输入您的选择：" << endl;
            cin >> choice2;
            switch (choice2) {
            case 1:
            {
                cout << "请添加个人信息" << endl;
                Teacher t1(string name1, int id1, string department1, int borrow1);
                break;
            }
            case 2:
            {
                cout << "请输入待查询的书籍id" << endl;
                int search;
                cin >> search;
                bool found = false;
                for (const auto& b1 : booklist)
                {
                    if (b1.getid() == search) {
                        b1.show();
                        found = true;
                        break;
                    }
                    if (!found) cout << "没有找到该图书" << endl;
                    break;
                }
            }
            case 3:
            {
                int search, borrownum;
                Teacher t;
                cout << "请输入需借阅图书编号：" << endl;
                cin >> search;
                cout << "借阅数量为：" << endl;
                cin >> borrownum;
                bool found = false;
                for (auto& b1 : booklist)
                {
                    if (b1.getid() == search) {
                        t.borrowbook(b1, borrownum);
                        found = true;
                        break;
                    }
                    if (!found)cout << "没有找到该图书" << endl;
                    break;
                }
            }
            case 4:
            {
                int search, returnnum;
                Teacher t;
                cout << "请输入需归还图书编号：" << endl;
                cin >> search;
                cout << "归还数量为：" << endl;
                cin >> returnnum;
                bool found = false;
                for (auto& b1 : booklist)
                {
                    if (b1.getid() == search) {
                        t.returnbook(b1, returnnum);
                        found = true;
                        break;
                    }
                    if (!found)cout << "没有找到该图书" << endl;
                    break;
                }
            }
            case 5:
            {
                cout << "请输入教师工号：" << endl;
                int search;
                cin >> search;
                bool found = false;
                for (const auto& t : teacherlist)
                {
                    if (t.getid() == search) {
                        t.show();
                        found = true;
                        break;
                    }
                }
                if (!found)cout << "没有找到该教师" << endl;
                break;
            }
            case 0:
                cout << "退出图书馆管理系统，再见！" << endl;
                return 0;
            default:
                cout << "输入错误，请选择 0~3 的选项！" << endl;
                break;
            }

        case 3:
            showMenu_s();
            cout << "请输入您的选择：" << endl;
            cin >> choice2;
            switch (choice2) {
            case 1:
            {
                cout << "请添加个人信息" << endl;
                Student s1(string name1, int id1, string department1, int borrow1);
                break;
            }
            case 2:
            {
                cout << "请输入待查询的书籍id" << endl;
                int search;
                cin >> search;
                bool found = false;
                for (const auto& b1 : booklist)
                {
                    if (b1.getid() == search) {
                        b1.show();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "没有找到该图书" << endl;
                break;

            }
            case 3:
            {
                int search, borrownum;
                Student s;
                cout << "请输入需借阅图书编号：" << endl;
                cin >> search;
                cout << "借阅数量为：" << endl;
                cin >> borrownum;
                bool found = false;
                for (auto& b1 : booklist)
                {
                    if (b1.getid() == search) {
                        s.borrowbook(b1, borrownum);
                        found = true;
                        break;
                    }
                }
                if (!found)   cout << "没有找到该图书" << endl;

                break;

            }
            case 4:
            {
                int search, returnnum;
                Student s;
                cout << "请输入需归还图书编号：" << endl;
                cin >> search;
                cout << "归还数量为：" << endl;
                cin >> returnnum;
                bool found = false;
                for (auto& b1 : booklist)
                {
                    if (b1.getid() == search) {
                        s.returnbook(b1, returnnum);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "没有找到该图书" << endl;

                break;

            }
            case 5:
            {
                cout << "请输入学生学号：" << endl;
                int search;
                cin >> search;
                bool found = false;
                for (const auto& s : studentlist)
                {
                    if (s.getid() == search) {
                        s.show();
                        found = true;
                        break;
                    }
                }
                if (!found)  cout << "没有找到该学生" << endl;

                break;

            }
            case 0:
                cout << "退出图书馆管理系统，再见！" << endl;
                return 0;
            default:
                cout << "输入错误，请选择 0~3 的选项！" << endl;
                break;
            }
        }
    }
        return 0;
}