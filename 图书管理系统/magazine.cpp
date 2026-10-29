#include "magazine.h"
Magazine::Magazine() : Book() {}
Magazine::Magazine(int id, string name, string author, string publisher,
    double price, int stock, int issue, string issn)
    : Book(id, name, author, publisher, price, stock), 
    issue(issue),
    issn(issn)
{
    
}
int Magazine::bookkind() const { 
    return 2; }
int Magazine::getIssue() const { 
    return issue; }
string Magazine::getIssn() const { 
    return issn; }
void Magazine::show() const {
    cout << "=== 杂 志 ===" << endl;
    Book::show();
    cout << "期   数：" << issue << endl;
    cout << "ISSN号：" << issn << endl;
}
Magazine::~Magazine() {}
