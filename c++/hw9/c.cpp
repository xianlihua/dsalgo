/**
 * C:字符串操作
 * http://cxsjsxmooc.openjudge.cn/hw9/C/
 */
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

static string * s = NULL;

int ReadInt();

// 判断字符串是否为整型数组成
bool isInt(const string & str) {
    for (int i = 0, len = str.length(); i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

// 读入字符串
string ReadString() {
    string input;
    cin >> input;

    if (input == "copy") {
        int N, X, L;
        N = ReadInt();
        X = ReadInt();
        L = ReadInt();
        return s[N].substr(X, L);
    }

    if (input == "add") {
        string S1, S2;
        char sum[6];
        S1 = ReadString();
        S2 = ReadString();
        if (S1.length() < 6 && S2.length() < 6 && isInt(S1) && isInt(S2)) {
            sprintf(sum, "%d", atoi(S1.c_str()) + atoi(S2.c_str()));
            return string(sum);
        }
        return S1 + S2;
    }

    return input;
}

// 读入整型数值
int ReadInt() {
    string S, input;
    int N, pos = 0;
    cin >> input;


    if (input == "find") {
        S = ReadString();
        N = ReadInt();
        pos = s[N].find(S);
    }

    if (input == "rfind") {
        S = ReadString();
        N = ReadInt();
        pos = s[N].rfind(S);
    }

    if (input == "find" || input == "rfind") return pos == string::npos ? S.length() : pos;

    return atoi(input.c_str());
}

int main() {
    int n;
    cin >> n;

    s = new string[++n];
    for (int i = 1; i < n; i++) {
        cin >> s[i];
    }

    string command;

    string S;
    int N, X;
    while (true) {
        cin >> command;

        if (command == "over") break;

        if (command == "insert") {
            S = ReadString();
            N = ReadInt();
            X = ReadInt();
            s[N].insert(X, S);
            continue;
        }

        if (command == "print") {
            N = ReadInt();
            cout << s[N] << endl;
            continue;
        }

        if (command == "reset") {
            S = ReadString();
            N = ReadInt();
            s[N] = S;
            continue;
        }

        if (command == "printall") {
            for (int i = 1; i < n; i++) cout << s[i] << endl;
            continue;
        }
    }
    return 0;
}
