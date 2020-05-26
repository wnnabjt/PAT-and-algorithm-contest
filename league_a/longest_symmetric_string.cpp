#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;

int dp[maxn][maxn];

int main() {
    for(int i = 0; i < maxn; i ++) {
        dp[i][i] = 1;
    }
    string s;
    getline(cin, s);
    int n = s.length();
    int ans = 1;
    for(int len = 1; len < n; len ++) {
        for(int i = 0; i < n - 1; i ++) {
            int j = i + len;
            if(s[i] == s[j]) {
                if(len == 1) {
                    dp[i][j] = 2;
                } else if(dp[i + 1][j - 1] > 0) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}