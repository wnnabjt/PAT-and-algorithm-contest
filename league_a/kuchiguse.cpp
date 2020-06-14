#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
string s[maxn];

int main() {
    int n;
    cin >> n;
    getchar();
    int len = 300 + 5;
    for(int i = 0; i < n; i ++) {
        getline(cin, s[i]);
        if(s[i].size() < len) len = s[i].size();
        reverse(s[i].begin(), s[i].end());
    }
    int ans = 0;
    bool flag = true;
    for(int i = 0; i < len; i ++) {
        char c = s[0][i];
        for(int j = 0; j < n; j ++) {
            if(s[j][i] != c) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans ++;
        } else break;
    }
    if(ans) {
        for(int i = ans - 1; i >= 0; i --) {
            printf("%c", s[0][i]);
        }
    } else printf("nai");
    printf("\n");
    return 0;
}