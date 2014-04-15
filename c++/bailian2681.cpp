/**
 * 2681:求字符串长度
 * http://bailian.openjudge.cn/practice/2681/
 */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char c[100];
    cin.getline(c, 100);

    char *pc = c;
    short length = 0;
    while (*pc != '\0') {
        length++;
        pc++;
    }

    cout << length;
    return 0;
}
