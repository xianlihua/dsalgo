/**
 * 9:编程填空：输出相应结果
 * http://cxsjsxmooc.openjudge.cn/mid2014/9/
 */
#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        int id;
        static int count;
    public:
        // 在此处补充你的代码
        Student() {
            count++;
        }
        Student(int id_) {
            id = id_;
            count += 2;
        }
        Student(const Student & student) {
            id = student.id;
        }
        static void InitCount() {
            count = 0;
        }
        friend void PrintCount();
        friend void Print(Student);
        // end
};

int Student::count;

void PrintCount() {
    cout << "Total " << Student::count << " students" << endl;
}

void Print(Student s) {
    cout << "the id is " << s.id << endl;
}

int main() {
    Student::InitCount();
    Student s;
    PrintCount(); // 1
    Student s1(10);
    Student s2(s1);
    PrintCount(); // 3
    Print(s2); // 10
    PrintCount(); // 3
    return 0;
}