/**
 * 8:编程填空：输出学生信息
 * http://cxsjsxmooc.openjudge.cn/mid2014/8/
 */
#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
class Student {
    private:
        string name;
        short id;
    public:
        Student();
        Student(string, short);
        void Read();
        void Print();
};

Student::Student(): name(""), id(0) {}
Student::Student(string name_, short id_) {
    name = name_;
    id = id_;
}
void Student::Read() {
    cin >> name >> id;
}
void Student::Print() {
    cout << id << " " << name << endl;
}
// end

int main() {
    int t;
    cin >> t;
    Student s("Tom",12);
    while( t-- )    {
        int n;
        cin >> n;
        Student st;
        for( int i = 0;i < n; ++i) {
            st.Read();
            st.Print();
        }
        cout << "****" << endl;
    }
    return 0;
}
