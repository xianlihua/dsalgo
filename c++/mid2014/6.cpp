/**
 * 6:编程填空：学生信息处理
 * http://cxsjsxmooc.openjudge.cn/mid2014/6/
 */
#include <iostream>
#include <map>
using namespace std;

struct Student {
    int id;
    string name;
    int score;
    Student(int id_,const string & nm,int sc):
        id(id_),name(nm),score(sc) { }
    Student() { }


};


struct Info {
    string name;
    int score;
    Info(const string & s,int sc):name(s),score(sc) { }
};

// 在此处补充你的代码
pair<int, Info> MyMakePair(const Student & student) {
    Info info = Info(student.name, student.score);
    return make_pair(student.id, info);
}

Student MyFind(const map<int, Info> & mp, int id) {
    map<int, Info>::const_iterator i = mp.find(id);
    Info info = i -> second;
    Student student(id, info.name, info.score);
    return student;
}
// end

int main() {
    map<int,Info>  mp;
    int t;
    cin >> t;
    while( t -- ) {
        mp.clear();
        int n;
        cin >> n;
        Student st;
        for( int i = 0;i < n; ++i) {
            cin >> st.id >> st.name >> st.score;
            mp.insert(MyMakePair(st));
        }
        cin >> n;
        st = MyFind(mp,n) ;
        cout << st.name << " " << st.score  << endl;
    }
    return 0;
}
