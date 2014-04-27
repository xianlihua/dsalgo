/**
 * 2684:求阶乘的和
 * http://bailian.openjudge.cn/practice/2684/
 */
#include <iostream>
using namespace std;

int factorial(short n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(int argc, char const *argv[])
{
    short n;
    cin >> n;

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += factorial(i);
    }
    cout << result;
    return 0;
}
