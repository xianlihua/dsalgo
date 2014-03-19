#include <iostream>
using namespace std;

// Array2 类声明
class Array2 {
    private:
        int *p;
        int row, col;
    public:
        Array2 ();
        Array2 (int, int);
        Array2 (const Array2 &);
        ~Array2 ();
        Array2 & operator = (const Array2 &);
        int * operator [] (int);
        int & operator () (int, int);
};

// 无参构造函数
Array2::Array2 (): p(NULL), row(0), col(0) {}

// 初始化构造函数
Array2::Array2 (int a, int b): row(a), col(b) {
    // 分配存储空间
    p = new int[a * b];
    memset(p, 0, a * b);
}

// 复制构造函数
Array2::Array2 (const Array2 & a): row(a.row), col(a.col) {
    if (!a.p) {
        p = NULL;
        return;
    }

    p = new int[row * col];
    memcpy(p, a.p, sizeof(int) * row * col);
    memset(p, 0, row * col);
}

// 析构函数
Array2::~Array2 () {
    if (p) delete [] p;
}

// 重载 =
Array2 & Array2::operator = (const Array2 & a) {
    if (a.p == p) return *this;

    if (p) delete [] p;

    if (!a.p) {
        p = NULL;
        row = col = 0;
        return *this;
    }

    row = a.row;
    col = a.col;
    p = new int[row * col];
    memcpy(p, a.p, sizeof(int) * row * col);
    return *this;
}

// 重载 []
int * Array2::operator [] (int n) {
    return p + n * col;
}

// 重载 ()
int & Array2::operator () (int a, int b) {
    return p[a * col + b];
}

/**
 * output:
 * 0,1,2,3,
 * 4,5,6,7,
 * 8,9,10,11,
 * next
 * 0,1,2,3,
 * 4,5,6,7,
 * 8,9,10,11,
 */
int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;   b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
