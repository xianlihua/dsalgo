/**
 * 2679:整数的立方和
 * http://bailian.openjudge.cn/practice/2679/
 */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    short k;
    int m = 0;
    cin >> k;
    for (short i = 1; i <= k; i++) {
        m += i * i * i;
    }
    cout << m;
    return 0;
}
