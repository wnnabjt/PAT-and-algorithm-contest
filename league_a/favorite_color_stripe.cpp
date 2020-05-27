#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;

int Hash[200 + 5];

int colors[maxn];

int dp[maxn];

int main() {
    int n, m, l, favorites;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> favorites;
        Hash[favorites] = i;
    }
    cin >> l;
    int temp, cnt = 0;
    for(int i = 1; i <= l; i ++) {
        cin >> temp;
        if(Hash[temp] > 0) {
            colors[++ cnt] = Hash[temp];
        }
    }
    int ans = 0;
    for(int i = 1; i <= cnt; i ++) {
        dp[i] = 1;
        for(int j = 1; j < i; j ++) {
            if(colors[i] >= colors[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    
    cout << ans << endl;
    return 0;
}