/**
 * hw9B:Set
 * http://cxsjsxmooc.openjudge.cn/hw9/B/
 */
#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;

    set<int> record; // 记录是否出现过
    multiset<int> ms; // 存储数据
    int value;
    multiset<int>::iterator mit;

    for (int i = 0; i < n; i++) {
        char command[4];
        cin >> command;

        char cc = command[2];
        // add
        if (cc == 'd') {
            cin >> value;
            ms.insert(value);
            cout << ms.count(value) << endl;
            record.insert(value);

        // del
        } else if (cc == 'l') {
            cin >> value;
            cout << ms.count(value) << endl;
            ms.erase(ms.lower_bound(value), ms.upper_bound(value));

        // ask
        } else if (cc == 'k') {
            cin >> value;
            int count = record.count(value);
            cout << bool(count) << " " << ms.count(value) << endl;
        }
    }
    return 0;
}
