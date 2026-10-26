#include "GeneralBook.h"
GeneralBook::GeneralBook(int id, string name, string author, string publisher,
    double price, int stock, string isbn)
    : Book(id, name, author, publisher, price, stock) {
    this->isbn = isbn;
}

void GeneralBook::show() const {
    cout << "=== 一般图书 ===" << endl;
    Book::show();
    cout << "ISBN号：" << isbn << endl;
}
GeneralBook::~GeneralBook() {}