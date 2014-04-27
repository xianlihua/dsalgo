/**
 * X:思考题最后一题，不计分，供测试
 * http://cxsjsxmooc.openjudge.cn/hw9/X/
 */
#include <iostream>
#include <string>
using namespace std;
template <class T>
class CMyistream_iterator {
    // 在此处补充你的代码
    private:
        T * input;
    public:
        CMyistream_iterator(istream & is) {
            input = new T[3];
            is >> *input;
        }
        T operator * () {
            return *input;
        }
        CMyistream_iterator operator ++ (int) {
            CMyistream_iterator tmp = *this;
            cin >> *++input;
            return tmp;
        }
    // end
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        CMyistream_iterator<int> inputInt(cin);
        int n1,n2,n3;
        n1 = * inputInt;
        int tmp = * inputInt;
        cout << tmp << endl;
        inputInt ++; //
        n2 = * inputInt;
        inputInt ++; //
        n3 = * inputInt;
        cout << n1 << "," << n2<< "," << n3 << ",";
        CMyistream_iterator<string> inputStr(cin);
        string s1,s2;
        s1 = * inputStr;
        inputStr ++;
        s2 = * inputStr;
        cout << s1 << "," << s2 << endl;
    }
    return 0;
}
