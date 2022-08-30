int main() {
    int val = 1024;
    int val2 = 2048;
    //让ref指向val，引用自身不是对象，没有空间
    //而指针是对象，有自己的存储空间
    int &ref = val;
    //报错，引用只允许初始化1次
    //&ref = val;
    return 0;
}
