/*
    本题大意：无向图，求结点之间的最短路的条数，并求出所有最短路中点权和最大的那条最短路的点权和。
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 500 + 5, inf = 0x3f3f3f3f;

struct edge {
    int to, w, _next;
} edges[maxn * maxn];

int n, m, c1, c2, u, v, w;
int head[maxn];
int cnt;

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}

void addedge(int u, int v, int w) {
    edges[cnt].to = v;
    edges[cnt].w = w;
    edges[cnt]._next = head[u];
    head[u] = cnt ++;
}


int dist[maxn];
bool vis[maxn];

void spfa(int s, int t) {
    memset(dist, inf, sizeof dist);
    memset(vis, false, sizeof vis);
    vis[s] = true;
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int k = head[u]; ~k; k = edges[k]._next) {
            int v = edges[k].to;
            if(dist[v] > dist[u] + edges[k].w) {
                dist[v] = dist[u] + edges[k].w;
                if(!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
}

int rescues[maxn];

int num, ans, temp;

void dfs(int u, int pre) {
    if(u == c2) {
        ans = max(ans, temp);
        num ++;
        return;
    };
    for(int k = head[u]; ~k; k = edges[k]._next) {
        int v = edges[k].to;
        if(edges[k].w + dist[u] == dist[v]) {
            temp += rescues[v];
            dfs(v, u);
            temp -= rescues[v];
        }
    }
}

int main() {
    init();
    cin >> n >> m >> c1 >> c2;
    for(int i = 0; i < n; i ++) cin >> rescues[i];
    while(m --) {
        cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    spfa(c1, c2);
    dfs(c1, c2);
    cout << num << ' ' << ans + rescues[c1] << endl;
    return 0;
}
