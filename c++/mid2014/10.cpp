/**
 * 10:编程填空：数值计算
 * http://cxsjsxmooc.openjudge.cn/mid2014/10/
 */
#include <iostream>
#include <string>
using namespace std;

class A {
    int n;
    public:
// 在此处补充你的代码
        A(int value): n(value) {}
        A & operator ++ () {
            n++;
            return *this;
        }
        A operator ++ (int) {
            A tmp = *this;
            n++;
            return tmp;
        }
        friend ostream & operator << (ostream & os, const A & a) {
            return os << a.n;
        }
        A & operator = (int value) {
            n = value;
            return *this;
        }
        operator int() {
            return n;
        }
};

class B {
    private:
    static int k;
    static int Square(int n)
    {
        cout <<  "k=" << k <<endl;
        return n * n;
    }
    friend int main();
};
int B::k;

int main() {
    A a1(1),a2(2);
    cout << a1++ << endl; // 1
    (++a1) = 100;
    cout << a1 << endl; // 100
    cout << ++ a1 << endl; // 101
    cout << a1 << endl; // 101
    int n;
    cin >> n;
    while( n --) {
        cin >> B::k;
        A a3(B::k);
        cout << B::Square(a3) << endl;
    }
    return 0;
}