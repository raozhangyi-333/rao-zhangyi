#include"Book.h"
#include"Person.h"
#include"Library.h"
using namespace std;
/*int main()
{   
    int choice1;
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
            Library lib;  // 创建图书馆对象
            lib.run();    // 启动系统
          
        case 2:
           
            cout << "请输入您的选择：" << endl;
            cin >> choice2;
            switch (choice2) {
            case 1:
            {
                cout << "请添加教师个人信息" << endl;
                string name, department;
                int id;
                cout << "请输入姓名：";
                cin >> name;
                cout << "请输入工号：";
                cin >> id;
                cout << "请输入所属部门：";
                cin >> department;

                // 动态创建教师对象，最大借阅额度由子类构造默认设为10
                Teacher* t1 = new Teacher(name, id, department);
                PersonList.push_back(t1);
                cout << "教师账号创建成功！" << endl;
                break;
            }
            case 2:
            {
                cout << "请输入待查询的书籍id" << endl;
                int search;
                cin >> search;
                bool found = false;
                for (const auto& b1 : BookList)
                {
                    if (b1->getid() == search) {
                        b1->show();
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
                for (auto& b1 : BookList)
                {
                    if (b1->getid() == search) {
                        t.borrowbook(*b1, borrownum);
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
                for (auto& b1 : BookList)
                {
                    if (b1->getid() == search) {
                        t.returnbook(*b1, returnnum);
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
                for (const auto& t : PersonList)
                {
                    if (t->getid() == search) {
                        t->show();
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
                string name, major;
                int id;
                cout << "请输入姓名：";
                cin >> name;
                cout << "请输入学号：";
                cin >> id;
                cout << "请输入专业：";
                cin >> major;
                Student* s1 = new Student(name, id, major);
                PersonList.push_back(s1);  // 存入读者管理容器

                cout << "学生账号创建成功！" << endl;
                break;
            }
            case 2:
            {
                cout << "请输入待查询的书籍id" << endl;
                int search;
                cin >> search;
                bool found = false;
                for (const auto& b1 : BookList)
                {
                    if (b1->getid() == search) {
                        b1->show();
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
                for (auto& b1 : BookList)
                {
                    if (b1->getid() == search) {
                        s.borrowbook(*b1, borrownum);
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
                for (auto& b1 : BookList)
                {
                    if (b1->getid() == search) {
                        s.returnbook(*b1, returnnum);
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
                for (const auto& s : PersonList)
                {
                    if (s->getid() == search) {
                        s->show();
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
}*/
int main()
{
    Library lib;    // 创建图书馆系统对象，所有数据和功能都封装在内部
    lib.run();      // 启动系统总入口：身份选择 → 对应菜单 → 业务调度
    return 0;
}
