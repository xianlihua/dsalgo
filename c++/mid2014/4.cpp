/**
 * 4:程序填空：原样输出
 * http://cxsjsxmooc.openjudge.cn/mid2014/4/
 */
#include <iostream>
using namespace std;

// 在此处补充你的代码
class Base {
    public:
        virtual void print() = 0;
};

class A: public Base {
    private:
        short a;
    public:
        A(short v): a(v) {}
        void print() {
            cout << "A " << a << endl;
        }
};

class B: public Base {
    private:
        short b;
    public:
        B(short v): b(v) {}
        void print() {
            cout << "B " << b << endl;
        }
};

void PrintInfo(Base * p) {
    p -> print();
}

Base * a[] = {0};
// end

int main() {
    int t;
    cin >> t;
    while( t -- ) {
        int n;
        cin >> n;
        for( int i = 0;i < n; ++i)  {
            char c; int k;
            cin >> c >> k;
            if( c == 'A')
                a[i] = new A(k);
            else
                a[i] = new B(k);
        }
        cout << n << endl;
        for( int i = 0;i < n; ++i)
            PrintInfo(a[i]);
        cout << "****" << endl;
    }
}
