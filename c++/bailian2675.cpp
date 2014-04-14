/**
 * 2675:计算书费
 * http://bailian.openjudge.cn/practice/2675/
 */
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int k;
    cin >> k;
    double prices[10] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
    double amount[k];
    for (int i = 0; i < k; i++) {
        int tmp, j = 0;
        amount[i] = 0;
        while (j < 10) {
            cin >> tmp;
            amount[i] += double(prices[j] * tmp);
            j++;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << fixed << setprecision(2) << amount[i] << endl;
    }
    return 0;
}
