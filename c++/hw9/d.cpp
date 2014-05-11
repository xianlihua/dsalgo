/**
 * D:热血格斗场
 * http://cxsjsxmooc.openjudge.cn/hw9/D/
 */
#include <cstdio>
#include <map>
using namespace std;

map<int, int> players;

void make_group(int power) {
    map<int, int>::const_iterator i, j, k;
    i = players.find(power);

    if (i == players.end()) {
        return;
    }

    if (i == players.begin()) {
        j = i;
        j++;
        printf("%d %d\n", i -> second, j -> second);
        return;
    }

    int upper, lower;
    j = i;
    j++;
    upper = j -> first - i -> first;
    k = i;
    k--;
    lower = i -> first - k -> first;
    if (lower <= upper) {
        printf("%d %d\n", i -> second, k -> second);
    } else {
        printf("%d %d\n", i -> second, j -> second);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    players.insert(make_pair(1000000000, 1));

    int id, power;
    while(n--) {
        scanf("%d%d", &id, &power);
        players.insert(make_pair(power, id));
        make_group(power);
    }
    return 0;
}