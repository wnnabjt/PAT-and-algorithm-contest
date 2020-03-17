#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;

int head[maxn], cnt, op;

struct Edge {
    int to, _next;
} edges[maxn * (maxn - 200)];

void init() {
    cnt = 2;
    memset(head, -1, sizeof head);
}

bool vis[maxn];

void addedge(int u, int v) {
    edges[cnt].to = v;
    edges[cnt]._next = head[u];
    head[u] = cnt ++;
}

void dfs(int u) {
    vis[u] = true;
    for(int i = head[u]; ~i; i = edges[i]._next) {
        int v = edges[i].to;
        if(!vis[v] && v != op) {
            dfs(v);
        }
    }
}

int main() {
    init();
    int n, m, k, u, v, ans;
    cin >> n >> m >> k;
    while(m --) {
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    while(k --) {
        ans = 0;
        memset(vis, false, sizeof vis);
        cin >> op;
        for(int i = 1; i <= n; i ++) {
            if(!vis[i] && i != op) {
                dfs(i);
                ans ++;
            }
        }
        cout << ans - 1 << endl;
    }
    return 0;
}