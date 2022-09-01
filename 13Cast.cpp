#include <iostream>

class B {
public:
    virtual void f() {};
};

class D : public B {
};

B *doUpCast(D *pd) {
    B *pb = dynamic_cast<B *>(pd);
    std::cout << "doUpCast convert pd:" << pd << " to pb=" << pb << std::endl;
    return pb;
}

D *doDownCast(B *pb) {
    D *pd = dynamic_cast<D *>(pb);
    if (pd == nullptr) {
        std::cout << "doDownCast convert pb=" << pb << " to pd failed" << std::endl;
    } else {
        std::cout << "doDownCast convert pb=" << pb << " to pd=" << pd << std::endl;
    }
    return pd;
}

int main() {
    long value = LONG_MAX;
    //static_cast在编译期转换，如果转换失败在编译时会报错
    int i = static_cast<int>(value);

    //const_cast是唯一能够去除 const 属性的运算符
    const std::string s = "test";
    auto *ps = const_cast<std::string *>(&s);

    //dynamic_cast主要用于有继承关系的多态类（基类必须有虚函数）的指针或引用之间的转换
    //具有类型检查的功能，如果转换的是指针，失败时会返回空指针；如果转换的是引用，会抛出std::bad_cast异常
    B b;
    D d;
    B *pb1 = doUpCast(&d);    //向上转型，输出：doUpCast convert pd:0x62fde0 to pb=0x62fde0
    D *pd1 = doDownCast(pb1); //向下转型，将指向d的B*指针安全的转换为D*，输出：doDownCast convert pb=0x62fde0 to pd=0x62fde0
    D *pd2 = doDownCast(&b);  //向下转型，将指向b的B*指针转换为D*失败，输出：doDownCast convert pb=0x62fdf0 to pd failed

    //reinterpret_cast对二进制位的重新解释，最危险，最灵活
    void *ptr = reinterpret_cast<void *>(value);
    long reinterpret_casted = reinterpret_cast<long>(ptr);
    std::cout << reinterpret_casted << std::endl;
    return 0;
}
