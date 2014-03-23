#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 200;

class BigInt {
    private:
        int bigint[N]; // 逆向存储，个位在左
        int length; // 总长度(含符号)
        bool sign; // 符号

    public:
        BigInt ();
        BigInt (const char *);
        BigInt (const BigInt &);

        friend ostream & operator << (ostream &, const BigInt &);
        int & operator [] (int i);

        BigInt operator + (const BigInt &);
        BigInt operator - (const BigInt &);
        BigInt operator * (const BigInt &);
        BigInt operator / (const BigInt &);
        BigInt & operator = (const BigInt &);

        bool operator > (const BigInt &);
        bool operator == (const BigInt &);
        bool operator < (const BigInt &);
        bool operator >= (const BigInt &);
        bool operator <= (const BigInt &);
        bool operator != (const BigInt &);
};

// 构造函数
BigInt::BigInt () {
    memset(bigint, 0, sizeof(int) * N);
    length = 0;
    sign = false;
}

// 使用字符串初始化构造函数
BigInt::BigInt (const char *str) {
    sign = false;
    length = strlen(str);
    memset(bigint, 0, sizeof(int) * N);
    for (int i = 0; i < length; i++) {
        bigint[i] = str[length - i - 1] - '0';
    }
    while (length && bigint[length - 1] == 0) {
        length--;
    }
}

// 复制构造函数
BigInt::BigInt (const BigInt & bi) {
    length = bi.length;
    sign = bi.sign;
    memcpy(bigint, bi.bigint, sizeof(int) * N);
}

// 重载流提取运算符
ostream & operator << (ostream & os, const BigInt & bi) {
    int len = bi.length;
    while (len && bi.bigint[len - 1] == 0) {
        len--;
    }
    if (bi.sign && len) {
        os << "-";
    }
    if (!len) {
        os << "0";
    }
    for (int i = 0; i < len; i++) {
        os << bi.bigint[len - i - 1];
    }
    return os;
}

// 重载取元素运算符
int & BigInt::operator [] (int i) {
    return bigint[i];
}

// 重载赋值运算符
BigInt & BigInt::operator = (const BigInt & bi) {
    sign = bi.sign;
    length = bi.length;
    memcpy(bigint, bi.bigint, sizeof(int) * N);
    return *this;
}

// 手算正整数加法
BigInt BigInt::operator + (const BigInt & bi) {
    BigInt b;
    int i = 0;
    b.length = length > bi.length ? length : bi.length;
    for (; i < b.length + 1; i++) {
        b.bigint[i] += bigint[i] + bi.bigint[i];
        b.bigint[i + 1] += b.bigint[i] / 10;
        b.bigint[i] = b.bigint[i] % 10;
    }
    if (b.bigint[b.length] > 0) b.length++;
    return b;
}

// 手算正整数减法
BigInt BigInt::operator - (const BigInt & bi) {
    BigInt b, max(*this), min(bi);
    if (max == min) {
        return b;
    }
    if (max < min) {
        BigInt tmp = max;
        max = min;
        min = tmp;
        b.sign = true;
    }
    b.length = max.length;
    for (int i = 0; i < max.length; i++) {
        if (max.bigint[i] < min.bigint[i]) {
            max.bigint[i] += 10;
            max.bigint[i + 1] -= 1;
        }
        b.bigint[i] = max.bigint[i] - min.bigint[i];
    }
    while (b.length && b.bigint[b.length - 1] == 0) {
        b.length--;
    }
    return b;
}

// 手算正整数乘法
BigInt BigInt::operator * (const BigInt & bi) {
    BigInt b;
    if (bi.length == 0 || length == 0) return b;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < bi.length; j++) {
            b.bigint[i + j] += bigint[i] * bi.bigint[j];
            if (b.bigint[i + j] > 9) {
                b.bigint[i + j + 1] += b.bigint[i + j] / 10;
            }
            b.bigint[i + j] = b.bigint[i + j] % 10;
        }
    }
    b.length = length + bi.length;
    while (b.length && b.bigint[b.length - 1] == 0) {
        b.length--;
    }
    return b;
}

// 手算正整数除法 减法 效率超低
/*BigInt BigInt::operator / (const BigInt & bi) {
    BigInt b, tmp(*this);
    if (tmp < bi) return b;
    if (tmp == bi) return b = "1";

    int i = 0;
    while (tmp > bi) {
        tmp = tmp - bi;
        b.length = 1;
        b.bigint[i] += 1;
        while (b.bigint[i] > 9) {
            b.bigint[i] = 0;
            b.bigint[++i] += 1;
            b.length++;
        }
        i = 0;
    }
    b.length++;
    while (b.length && b.bigint[b.length - 1] == 0) {
        b.length--;
    }
    return b;
}*/

// 试商求大树除法
BigInt BigInt::operator / (const BigInt & bi) {
    BigInt b;
    if (*this < bi) return b;
    if (*this == bi) return b = "1";

    // 被除数，除数，临时商，临时被除数
    BigInt dividend(*this), divisor(bi), quotient, tmp, one("1"), zero, ten("10");
    int dividendLength = dividend.length, divisorLength = divisor.length;

    // 先取出与除数长度一样的数
    int n = divisorLength - 1;
    while (n >= 0) {
        tmp.bigint[n--] = dividend.bigint[--dividendLength];
    }
    tmp.length = divisorLength;

    // 开始试商
    while (dividendLength > 0) {
        while (tmp < divisor && dividendLength > 0) {
            int tmplen = ++tmp.length;
            while (tmplen) {
                tmp.bigint[tmplen] = tmp.bigint[tmplen - 1];
                tmplen--;
            }
            tmp.bigint[0] = dividend.bigint[--dividendLength];
            b = b * ten;
        }

        // 试商
        while (quotient * divisor <= tmp) {
            quotient = quotient + one;
        }
        quotient = quotient - one;
        tmp = tmp - quotient * divisor;
        b = b + quotient;
        quotient = zero;
    }

    return b;
}

// 比较谁更大
bool BigInt::operator > (const BigInt & bi) {
    if (length > bi.length) return true;
    if (length < bi.length) return false;
    for (int i = length - 1; i > -1; i--) {
        if (bigint[i] > bi.bigint[i]) {
            return true;
        } else if (bigint[i] < bi.bigint[i]) {
            return false;
        }
    }
    return false;
}

// 比较相等
bool BigInt::operator == (const BigInt & bi) {
    if (length == bi.length) {
        for (int i = 0; i < length; i++) {
            if (bigint[i] != bi.bigint[i]) return false;
        }
        return true;
    }
    return false;
}

// 比较谁更小
bool BigInt::operator < (const BigInt & bi) {
    BigInt b(*this);
    if (b > bi || b == bi) return false;
    return true;
}

// 比较大于等于
bool BigInt::operator >= (const BigInt & bi) {
    BigInt b(*this);
    return b > bi || b == bi || false;
}

// 比较小于等于
bool BigInt::operator <= (const BigInt & bi) {
    BigInt b(*this);
    return b < bi || b == bi || false;
}

// 重载不等于
bool BigInt::operator != (const BigInt & bi) {
    return !(*this == bi);
}

// 主函数入口
int main () {
    char a[101], b[101], c;
    cin >> a >> c >> b;
    BigInt b1(a), b2(b);
    switch (c) {
        case '+': cout << (b1 + b2); break;
        case '-': cout << (b1 - b2); break;
        case '*': cout << (b1 * b2); break;
        case '/': cout << (b1 / b2); break;
    }
    return 0;
}