/**
 * 5:程序填空：打印数据
 * http://cxsjsxmooc.openjudge.cn/mid2014/5/
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 在此处补充你的代码
template <class T1, class T2, class F>
void my_for_each(T1 p, T2 end, F fn) {
    for (; p < end; p++) {
        fn(*p);
    }
}
// end

void Print(int n) {
    cout << n*n << ",";
}

struct MyPrint {
    void operator()( const string & s ) {
        cout << s << ",";
    }
};

int main() {
    int t;
    int a[5];
    vector<string> vt;
    cin >> t;
    while( t--) {
        vt.clear();
        for(int i = 0;i < 5; ++i)
            cin >> a[i];
        for(int i = 0;i < 5; ++i) {
            string s;
            cin >> s;
            vt.push_back(s);
        }
        my_for_each(a,a+5,Print);
        cout << endl;
        my_for_each(vt.begin(),vt.end(),MyPrint());
        cout << endl;
    }

    return 0;
}