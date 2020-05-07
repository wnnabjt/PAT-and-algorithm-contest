#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 500 + 5;

int head[maxn], cnt;

struct Edge {
    int to, next, w, cost;
} edges[maxn << 2];

void init() {
    memset(head, -1, sizeof head);
    cnt = 2;   
}

void addedge(int u, int v, int w, int cost) {
    edges[cnt].to = v; edges[cnt].w = w; edges[cnt].cost = cost;
    edges[cnt].next = head[u];
    head[u] = cnt ++;
}

int dist[maxn];
bool vis[maxn];

const int inf = 0x3f3f3f3f;

int s, d;

void spfa(int s, int d) {
    memset(dist, inf, sizeof dist);
    dist[s] = 0;
    vis[s] = true;
    queue <int> que;
    que.push(s);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        vis[u] = false;
        for(int k = head[u]; ~k; k = edges[k].next) {
            int v = edges[k].to;
            if(dist[v] > dist[u] + edges[k].w) {
                dist[v] = dist[u] + edges[k].w;
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

int pre[maxn]; // 记录路径中每个节点的父亲节点
int num; // 记录最短路条数
int tot_cost; // 记录总花费
vector <int> path[maxn];
int ans, min_cost;

void dfs(int u) {
    int temp;
    if(u == d) {
        path[num].push_back(d);
        temp = pre[d];
        while(~temp) {
            path[num].push_back(temp);
            temp = pre[temp];
        }
        if(tot_cost < min_cost) {
            min_cost = tot_cost;
            ans = num;
        }
        num ++;
    }
    for(int k = head[u]; ~k; k = edges[k].next) {
        int v = edges[k].to;
        if(dist[v] == dist[u] + edges[k].w) {
            temp = pre[v];
            pre[v] = u;
            tot_cost += edges[k].cost;
            dfs(v);
            tot_cost -= edges[k].cost;
            pre[v] = temp;
        }
    }
}

int main() {
    int n, m, u, v, w, cost;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    init();
    while(m --) {
        scanf("%d %d %d %d", &u, &v, &w, &cost);
        addedge(u, v, w, cost);
        addedge(v, u, w, cost);
    }
    min_cost = inf;
    spfa(s, d);
    memset(pre, -1, sizeof pre);
    dfs(s);
    vector <int> :: reverse_iterator i;
    for(i = path[ans].rbegin(); i != path[ans].rend(); i ++) {
        printf("%d ", *i);
    }
    printf("%d %d\n", dist[d], min_cost);
    return 0;
}