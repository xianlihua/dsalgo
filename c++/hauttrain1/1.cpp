/**
 * 1:把一个二进制的串转换为整数
 * http://haut.openjudge.cn/train1/1/
 */
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char binary[65];
    cin >> binary;
    int result = 0;
    for (short i = 0, len = strlen(binary); i < len; i++) {
        result += (binary[i] - 48) << (len - i - 1);
    }
    cout << result;
    return 0;
}
