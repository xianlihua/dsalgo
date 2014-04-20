/**
 * hw9A:List
 * http://cxsjsxmooc.openjudge.cn/hw9/A/
 */
#include <iostream>
#include <list>
using namespace std;
int main() {
    int n;
    cin >> n;

    list<int> lists[10000];
    char command[7];
    for (int i = 0; i < n; i++) {
        cin >> command;

        int id;
        char cc = command[0];

        // new
        if (cc == 'n') {
            cin >> id;
            list<int> lst;
            lists[id] = lst;

        // add
        } else if (cc == 'a') {
            int value;
            cin >> id >> value;
            lists[id].push_back(value);

        // merge
        } else if (cc == 'm') {
            int id2;
            cin >> id >> id2;
            lists[id].merge(lists[id2]);

        // unique
        } else if (cc == 'u') {
            cin >> id;
            lists[id].sort();
            lists[id].unique();

        // out
        } else if (cc == 'o') {
            cin >> id;
            list<int> tmp = lists[id];
            tmp.sort();
            list<int>::const_iterator it;
            for (it = tmp.begin(); it != tmp.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
