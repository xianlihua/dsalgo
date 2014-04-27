/**
 * 7:编程填空：实现特定功能的数据结构
 * http://cxsjsxmooc.openjudge.cn/mid2014/7/
 */
#include <iostream>
#include <set>
using namespace std;
// 在此处补充你的代码
template <class Key, class Compare = less<Key>, class Alloc = allocator<Key> >
class MySet: public set<Key, Compare, Alloc> {
    public:
        typedef typename MySet<Key>::iterator mi;
        typedef pair<mi, mi> pi;

        MySet(): set<Key, Compare, Alloc>() {}

        template<class InputIterator>
        MySet(InputIterator begin, InputIterator end) : set<Key, Compare, Alloc>(begin, end) {}

        pi FindInterval(int start_, int end_) {
            return make_pair(this -> upper_bound(start_), this -> lower_bound(end_));
        }
};

template <class T>
void MyPrint(T begin, T end) {
    for (; begin != end; begin++) cout << *begin << " ";
}
// end

int main() {
    int t;
    cin >> t;
    MySet<int> stInt;
    int a[100];
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0;i < n; ++i )
            cin >> a[i];
        MySet<int> stInt(a,a+n);
        MyPrint(stInt.begin(),stInt.end()); //输出全部内容
        cout << endl;
        int s,e;
        cin >> s >> e; // 后面要输出位于 s 和 e 之间的元素
        pair<MySet<int>::iterator, MySet<int>::iterator> p;
        p  = stInt.FindInterval(s,e);
        if( p.first != p.second) {
            MyPrint(p.first,p.second);
            cout << endl;
        }
        else
            cout << "Interval Not Found" << endl;
        cin >> n;
        MySet<double,greater<double> > stDouble;
        for( int i = 0;i < n; ++i)  {
            double d;
            cin >> d;
            stDouble.insert(d);
        }
        MyPrint(stDouble.begin(),stDouble.end());
        cout << endl;
        double w;
        cin >> w;
        cout << * stDouble.upper_bound(w) << endl;
    }
}