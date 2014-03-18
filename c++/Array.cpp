#include <iostream>
using namespace std;

// 声明 Array 类
class Array {
    private:
        int size;
        int *ptr;
    public:
        Array ();
        Array (const Array &);
        ~Array ();
        const int length ();
        void push (int);
        Array & operator = (const Array &);
        int & operator [] (const int);
};

Array::Array (): ptr(NULL), size(0) {}

// Array 类具体实现
Array::Array (const Array & a) {
    if (ptr) delete [] ptr;

    if (!a.ptr) {
        ptr = NULL;
        size = 0;
        return;
    }

    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}

// 析构
Array::~Array () {
    if (ptr) delete [] ptr;
    ptr = NULL;
    size = 0;
}

// 取长度
const int Array::length () {
    return size;
}

// 添加值
void Array::push (const int i) {
    if (!ptr) {
        ptr = new int[1];
    } else {
        int *tmp = new int[size + 1];
        memcpy(tmp, ptr, sizeof(int) * size);
        delete [] ptr;
        ptr = tmp;
    }

    ptr[size++] = i;
}

// 重载 =
Array & Array::operator = (const Array & a) {
    // 自身赋值
    if (ptr == a.ptr) return *this;

    if (ptr) delete [] ptr;

    // 空对象赋值
    if (!a.ptr) {
        ptr = NULL;
        size = 0;
        return *this;
    }

    // 对象赋值
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}

// 重载 []
int & Array::operator [] (const int i) {
    return ptr[i];
}

// 主函数入口
int main () {
    // 编写一个可变长整型数组类，实现以下功能
    Array a;
    for (int i = 0; i < 5; i++) {
        a.push(i);
    }

    Array a2, a3;
    a2 = a;
    for (int i = 0; i < a.length(); i++) {
        cout << a2[i] << " "; // output: 0 1 2 3 4
    }

    a2 = a3;
    for (int i = 0; i < a2.length(); i++) {
        cout << a2[i] << " "; // no output because a2.length() == 0
    }

    cout << endl;

    a[3] = 100;
    Array a4(a);
    for (int i = 0; i < a4.length(); i++) {
        cout << a4[i] << " "; // output: 0 1 2 100 4
    }
    return 0;
}

/**
 * 分析需要做的事情：
 * 1. Array 类具有名为 push 的公开方法，在 Array 对象尾部增加数据并改变对象的长度
 * 2. 需要重载对象赋值运算符，实现深拷贝
 * 3. 需要实现自定义的复制构造函数，实现深拷贝
 * 4. Array 类具有名为 length 的公开方法，返回 Array 对象的长度
 * 5. 需要重载 [] 运算符，实现通过索引的方式取对象中指定偏移位置的值
 */