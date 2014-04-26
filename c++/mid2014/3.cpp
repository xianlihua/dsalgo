/**
 * 3:程序填空：成绩单
 * http://cxsjsxmooc.openjudge.cn/mid2014/3/
 */
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

// 在此处补充你的代码
class Student {
    private:
        string name;
        short score;
    public:
        bool operator < (const Student &) const;
        friend istream & operator >> (istream &, Student &);
        friend ostream & operator << (ostream &, const Student &);
};

bool Student::operator < (const Student & student) const {
    return score < student.score;
}

istream & operator >> (istream & is, Student & student) {
    return is >> student.name >> student.score;
}

ostream & operator << (ostream & os, const Student & student) {
    return os << student.name;
}

int main()
{
    int t;
    vector<Student> v;
    cin >> t;

    while( t--) {
        int n;
        cin >> n;
        Student st;
        v.clear();
        for( int i = 0;i < n; ++i ) {
            cin >> st;
            v.push_back(st);
        }
        sort(v.begin(),v.end());
        for( int i = 0;i < v.size(); ++ i)
            cout << v[i] << endl;
        cout << "****" << endl;
    }
    return 0;
}