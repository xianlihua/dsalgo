/**
 * 2811:熄灯问题
 * http://bailian.openjudge.cn/practice/2811/
 * 程序抄写
 */
#include <cstdio>

int puzzle[6][8], press[6][8];

bool guess() {
    int c, r;
    // 根据 press 第一行和 puzzle 数组，计算 press 其他行的值
    for(r = 1; r < 5; r++) {
        for(c = 1; c < 7; c++) {
            press[r + 1][c] = (puzzle[r][c] + press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;
        }
    }

    // 判断所计算的 press 数组能否熄灭第五行的灯
    for(c = 1; c < 7; c++) {
        if((press[5][c - 1] + press[5][c] + press[5][c + 1] + press[4][c]) % 2 != puzzle[5][c]) {
            return false;
        }
    }

    return true;
}

void enumerate() {
    int c;
    bool success;
    for(c = 1; c < 7; c++) {
        press[1][c] = 0;
    }

    while(guess() == false) {
        press[1][1]++;
        c = 1;

        // 对 press 第一行的灯的取值情况进行枚举
        while(press[1][c] > 1) {
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
    }
}

int main() {
    int cases, i, r, c;
    scanf("%d", &cases);

    // 初始化开关二维数组
    for(r = 0; r < 6; r++) {
        press[r][0] = press[r][7] = 0;
    }
    for(c = 1; c < 7; c++) {
        press[0][c] = 0;
    }

    for(i = 0; i < cases; i++) {
        for(r = 1; r < 6; r++) {
            for(c = 1; c < 7; c++) {
                scanf("%d", &puzzle[r][c]);
            }
        }
        enumerate();
        printf("PUZZLE #%d\n", i + 1);
        for(r = 1; r < 6; r++) {
            for(c = 1; c < 7; c++) {
                printf("%d ", press[r][c]);
            }
            printf("\n");
        }
    }
    return 0;
}