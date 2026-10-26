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
    void show() const override;
    ~GeneralBook() override;
};
