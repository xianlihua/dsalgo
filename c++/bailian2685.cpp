/**
 * 2685:打印水仙花数
 * http://bailian.openjudge.cn/practice/2685/
 */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    for (short i = 100; i < 10000; i++) {
        short x = i % 10;
        short y = i / 10 % 10;
        short z = i / 100 % 10;
        if (i == x * x * x + y * y * y + z * z * z) {
            cout << i << endl;
        }
    }
    return 0;
}
