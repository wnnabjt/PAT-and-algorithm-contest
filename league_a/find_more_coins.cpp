/*
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 100 + 5;
int val[maxn];
int n, m;
int now;

int pre[maxn];
int num[maxn];

bool ans;
vector <int> vec;

void dfs(int u) {
    if(now > m || ans) return;
    if(now == m) {
        ans = true;
        while(true) {
            if(u == -1) break;
            for(int i = 1; i <= num[u]; i ++) {
                vec.push_back(u);
            }
            u = pre[u];
        }
        return;
    }
    for(int v = u + 1; v <= 100; v ++) {
        for(int i = val[v]; i > 0; i --) {
            now += v * i;
            pre[v] = u;
            num[v] = i;
            dfs(v);
            now -= v * i;
        }
    }
}

int main() {
    memset(pre, -1, sizeof pre);
    int coins, min = maxn;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &coins);
        if(coins < min) min = coins;
        if(coins <= 100) val[coins] ++;
    }
    for(int i = val[min]; i >= 0; i --) {
        now = min * i;
        num[min] = i;
        dfs(min);
    }
    if(!ans) printf("No Solution\n");
    else {
        for(int i = vec.size() - 1; i >= 0; i --) {
            printf("%d", vec[i]);
            if(i) printf(" ");
        }
    }
    return 0;
}
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5, maxm = 100 + 5;

bool cmp(int a, int b) {
    return a > b;
}

int dp[maxm], val[maxn];
bool vis[maxn][maxm];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &val[i]);
    }
    sort(val + 1, val + n + 1, cmp);
    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= val[i]; j --) {
            if(dp[j] <= dp[j - val[i]] + val[i]) {
                vis[i][j] = true;
                dp[j] = dp[j - val[i]] + val[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution\n");
    else {
        vector <int> ans;
        int idx = n;
        while(m) {
            if(vis[idx][m]) {
                ans.push_back(val[idx]);
                m -= val[idx];
            }
            idx --;
        }
        for(int i = 0; i < ans.size(); i ++) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
    }
    return 0;
}
