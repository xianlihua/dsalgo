/**
 * 2:编程填空：排序
 * http://cxsjsxmooc.openjudge.cn/mid2014/2/
 */
#include <iostream>
#include <list>
using namespace std;

class MyLess {
    public:
        bool operator () (const int &a, const int &b) {
            short tmpa = a % 10, tmpb = b % 10;
            return tmpa == tmpb ? a > b : tmpa > tmpb;
        }
};

int main()
{
    int t;
    cin >> t;
    list<int> lst;
    while( t--) {
        int n;
        cin >> n;
        lst.clear();
        int m;
        for( int i = 0;i < n; ++i) {
            cin >> m;
            lst.push_back(m);
        }
        lst.sort(MyLess());
        list<int>::iterator it;
        for( it = lst.begin(); it != lst.end(); ++ it) {
            cout << * it  << " ";
        }
        cout << endl;
    }
    return 0;
}