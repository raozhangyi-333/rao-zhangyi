#pragma once
#include "Book.h"

class Magazine : public Book
{
private:
    int issue;         // 期数（如 202610 表示2026年第10期）
    string issn;       // ISSN刊号

public:
    Magazine();
    Magazine(int id, string name, string author, string publisher,
        double price, int stock, int issue, string issn);
    int bookkind() const override;   // 返回2
    int getIssue() const;
    string getIssn() const;
    void show() const override;
    ~Magazine() override;
};
