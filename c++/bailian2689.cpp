/**
 * 2689:大小写字母互换
 * http://bailian.openjudge.cn/practice/2689/
 */
#include <iostream>
using namespace std;

bool isUpper(char c) {
    return c > 64 && c < 91;
}

bool isLower(char c) {
    return c > 96 && c < 123;
}



int main(int argc, char const *argv[]) {
    char cstr[80];
    cin.getline(cstr, 80);

    for (short i = 0; i < 80 && cstr[i] != '\0'; i++) {
        if (isLower(cstr[i])) {
            cout << char(cstr[i] - 32);
        } else if (isUpper(cstr[i])) {
            cout << char(cstr[i] + 32);
        } else {
            cout << cstr[i];
        }
    }
    return 0;
}
