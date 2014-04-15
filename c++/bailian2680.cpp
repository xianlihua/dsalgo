/**
 * 2680:化验诊断
 * http://bailian.openjudge.cn/practice/2680/
 */
#include <iostream>
#include <string>
using namespace std;

const float WBC[2] = {4.0, 10.0};
const float RBC[2] = {3.5, 5.5};
const short HGB[2][2] = {120, 160, 110, 150};
const short HCT[2][2] = {42, 48, 36, 40};
const short PLT[2] = {100, 300};

int main(int argc, char const *argv[]) {
    short k;
    cin >> k;

    short result[k];

    for (short i = 0; i < k; i++) {
        string sex;
        float wbc, rbc;
        short hgb, hct, plt;
        short count = 0;

        cin >> sex >> wbc >> rbc >> hgb >> hct >> plt;

        if (wbc < WBC[0] || wbc > WBC[1]) count++;
        if (rbc < RBC[0] || rbc > RBC[1]) count++;
        if (plt < PLT[0] || plt > PLT[1]) count++;
        if (sex == "male") {
            if (hgb < HGB[0][0] || hgb > HGB[0][1]) count++;
            if (hct < HCT[0][0] || hct > HCT[0][1]) count++;
        }
        if (sex == "female") {
            if (hgb < HGB[1][0] || hgb > HGB[1][1]) count++;
            if (hct < HCT[1][0] || hct > HCT[1][1]) count++;
        }

        result[i] = count;
    }

    for (short i = 0; i < k; i++) {
        if (result[i] > 0) {
            cout << result[i] << endl;
            continue;
        }
        cout << "normal" << endl;
    }

    return 0;
}
