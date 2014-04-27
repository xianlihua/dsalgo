/**
 * 2687:数组逆序重放
 * http://bailian.openjudge.cn/practice/2687/
 */
#include <iostream>
using namespace std;

void reverse(int *a, short n) {
    int *start = a, *end = a + n - 1;
    for (; start < end; start++, end--) {
        int tmp = *start;
        *start = *end;
        *end = tmp;
    }
}

int main(int argc, char const *argv[])
{
    short n;
    cin >> n;

    int a[n];
    for (short i = 0; i < n; i++) {
        cin >> a[i];
    }

    reverse(a, n);

    for (short i = 0; i < n; i++) {
        cout << a[i];
        if (i != n - 1) {
            cout << " ";
        }
    }

    return 0;
}
