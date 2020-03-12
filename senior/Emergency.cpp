#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 500 + 5, inf = 0x3f3f3f3f;

int rescues[maxn];

struct Edge {
    int to, w, _next;
} edges[maxn * maxn >> 1];

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

int ans;
bool vis[maxn];
bool vis2[maxn];

int dist[maxn];

void dijkstra(int s, int t) {
    queue <int> que;
    que.push(s);
    memset(dist, inf, sizeof dist);
    dist[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int u = que.front();    que.pop();
        if(vis[u]) continue;
        else vis[u] = true;
        for(int k = head[u]; ~k; k = edges[k]._next) {
            int v = edges[k].to;
            if(!vis[v] && dist[v] > dist[u] + edges[k].w) {
                dist[v] = dist[u] + edges[k].w;
                que.push(v);
            }
        }
    }
}

int main() {
    init();
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    for(int i = 0; i < n; i ++) {
        cin >> rescues[i];
    }
    int u, v, w;
    while(m --) {
        cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    dijkstra(c1, c2);

    return 0;
}
