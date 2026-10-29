#pragma once
#include "Book.h"

class GeneralBook : public Book
{
private:
    string isbn;

public:
    GeneralBook();
    GeneralBook(int id, string name, string author, string publisher,
        double price, int stock, string isbn);
    int bookkind() const override;   // 返回1
    string getIsbn() const;          // 供保存读取

    void show() const override;
    ~GeneralBook() override;
};
