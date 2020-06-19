#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100 + 5, inf = 0x3f3f3f3f;
int head[maxn], cnt;
struct Edge {
    int to, next;
} edges[maxn * 100];

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}

void addedge(int u, int v) {
    edges[cnt].to = v; edges[cnt].next = head[u];
    head[u] = cnt ++;
}

int dist[maxn];

void bfs(int s) {
    queue <int> que;
    que.push(s);
    memset(dist, inf, sizeof dist);
    dist[s] = 0;
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int k = head[u]; ~k; k = edges[k].next) {
            int v = edges[k].to;
            dist[v] = dist[u] + 1;
            que.push(v);
        }
    }
}

int ans[maxn];

int main() {
    init();
    int n ,m;
    scanf("%d %d", &n, &m);
    int u, num, v;
    for(int i = 0; i < m; i ++) {
        scanf("%d %d", &u, &num);
        while(num --) {
            scanf("%d", &v);
            addedge(u, v);
        }
    }
    bfs(1);
    for(int i = 1; i <= n; i ++) {
        ans[dist[i]] ++;
    }
    printf("%d %d\n", *max_element(ans, ans + n), max_element(ans, ans + n) - ans + 1);
    return 0;
}