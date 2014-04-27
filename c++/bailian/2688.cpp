/**
 * 2688:求字母的个数
 * http://bailian.openjudge.cn/practice/2688/
 */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char input[80];
    cin.getline(input, 80);

    short times[5] = {0};
    for (short i = 0; i < 80; i++) {
        switch (input[i]) {
            case 'a':
                ++times[0]; break;
            case 'e':
                ++times[1]; break;
            case 'i':
                ++times[2]; break;
            case 'o':
                ++times[3]; break;
            case 'u':
                ++times[4]; break;
            default: break;
        }
    }

    for (short i = 0; i < 5; i++) {
        cout << times[i];
        if (i != 4) {
            cout << " ";
        }
    }
    return 0;
}
