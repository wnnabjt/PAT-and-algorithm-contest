#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector <string> ans;

string digit[10] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", 
    "ba", "jiu",
};

string _log[10] = {
    "", "Shi", "Bai", "Qian", "Wan", "Yi",
};

int main() {
    int n;
    scanf("%d", &n);
    if(n < 0) {
        ans.push_back("Fu");
        n = -n;
    }
    int yi, wan, ge;
    yi = n / 100000000;
    n %= 100000000;
    wan = n / 10000;
    ge = n % 10000;
    if(yi) {
        ans.push_back(digit[yi]);
        ans.push_back(_log[5]);
    }
    string fyi = to_string(wan);
    if(wan < 1000 && yi && wan) ans.push_back(digit[0]);
    bool flag;
    if(wan) {
        flag = false;
        for(int i = 0; i < fyi.size(); i ++) {
            if(fyi[i] == '0') {
                flag = true;
                continue;
            } else {
                if(flag) ans.push_back(digit[0]);
                flag = false;
                ans.push_back(digit[fyi[i] - '0']);
                ans.push_back(_log[fyi.size() - i - 1]);
            }
        }
        ans.push_back(_log[4]);
    }
    if(ge < 1000) ans.push_back(digit[0]);
    flag = false;
    string fge = to_string(ge);
    for(int i = 0; i < fge.size(); i ++) {
        if(fge[i] == '0') {
            flag = true;
            continue;
        } else {
            if(flag) ans.push_back(digit[0]);
            flag = false;
            ans.push_back(digit[fge[i] - '0']);
            ans.push_back(_log[fge.size() - i - 1]);
        }
    }
    for(int i = 0 ;i < ans.size(); i ++) {
        if(ans[i] == "") continue;
        if(i) printf(" ");
        printf("%s", ans[i].c_str());
    }
    printf("\n");
    return 0;
}