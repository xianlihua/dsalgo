/**
 * 1:二进制位处理
 * http://cxsjsxmooc.openjudge.cn/mid2014/1/
 */
#include <iostream>
#include <cmath>
using namespace std;

const short BIT_LEN = 32;

int binary2int(bool b[]) {
    int result = 0;
    for (int i = 0; i < BIT_LEN; i++) {
        result += pow(2, i) * b[i];
    }
    return result;
}

int main () {
    int t;
    cin >> t;

    int n, i, j, k[t];
    for (int i_ = 0; i_ < t; i_++) {
        k[i_] = 0;
        cin >> n >> i >> j;

        // 计数求二进制位
        short bIndex = 0;

        // 存放 n 的二进制位
        bool nbinary[BIT_LEN] = {0}; // low -> high

        // 存放 k 的二进制位
        bool kbinary[BIT_LEN] = {0};

        while (n != 0) {
            nbinary[bIndex++] = n % 2;
            n /= 2;
        }

        kbinary[i] = nbinary[i];
        kbinary[j] = !nbinary[j];

        // 求二进制对应的整数
        k[i_] = binary2int(kbinary);
    }

    for (int i_ = 0; i_ < t; i_++) {
        cout << k[i_] << endl;
    }
    return 0;
}