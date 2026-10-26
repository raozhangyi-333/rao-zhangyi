#include "EResource.h"

// 默认构造：统一用初始化列表
EResource::EResource() : Book(), format(""), size(0.0) {}

// 带参构造：初始化列表调用基类 + 初始化子类成员
EResource::EResource(int id, string name, string author, string publisher,
    double price, int stock, string format, double size)
    : Book(id, name, author, publisher, price, stock),
    format(format),
    size(size) {
}

void EResource::show() const {
    cout << "=== 电子资源 ===" << endl;
    Book::show();
    cout << "文件格式：" << format << endl;
    cout << "文件大小：" << size << " MB" << endl;
}
EResource::~EResource() {}