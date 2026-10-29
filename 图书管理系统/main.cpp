#include"Book.h"
#include"Person.h"
#include"Library.h"
using namespace std;
int main()
{
    Library lib;
    lib.loadBooks();   //读图书：loadUsers 读借阅记录时要用 findBook 找书
    lib.loadUsers();   //读用户
    lib.run();
    lib.saveBooks();
    lib.saveUsers();
    return 0;
}


