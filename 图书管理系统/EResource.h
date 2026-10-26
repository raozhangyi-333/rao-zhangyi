#pragma once
#include "Book.h"

class EResource : public Book
{
private:
    string format;  // 特有：文件格式 PDF/EPUB
    double size;    // 特有：文件大小 MB

public:
    EResource();
    EResource(int id, string name, string author, string publisher,
        double price, int stock, string format, double size);
    void show() const override;
    ~EResource()override;
};

