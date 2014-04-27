/**
 * 2676:整数的个数
 * http://bailian.openjudge.cn/practice/2676/
 */
#include <iostream>
using namespace std;
int main() {
    short k, repeats[11] = {0};
    cin >> k;
    for (short i = 0; i < k; i++) {
        short tmp;
        cin >> tmp;
        repeats[tmp]++;
    }
    cout << repeats[1] << endl << repeats[5] << endl << repeats[10];
    return 0;
}
