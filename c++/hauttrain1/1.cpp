/**
 * 1:把一个二进制的串转换为整数
 * http://haut.openjudge.cn/train1/1/
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    string binary;
    getline(cin, binary);
    int result = 0;
    for (short i = 0, len = binary.length(); i < len; i++) {
        if (binary[i] == '1') {
            result += pow(2, len - i - 1);
        }
    }
    cout << result;
    return 0;
}
