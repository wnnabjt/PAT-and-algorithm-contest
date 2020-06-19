#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5, inf = 0x3f3f3f3f;;

double p, r;

int head[maxn], cnt;

void init() {
    cnt = 0;
    memset(head, -1, sizeof head);
}

struct Edge {
    int to, next;
} edges[maxn * 100];

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

int s;

int main() {
    init();
    int n;
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    int v;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &v);
        if(v == -1) s = i;
        else {
            addedge(v, i);
        }
    }
    bfs(s);
    int num = 0;
    int M = *max_element(dist, dist + n);
    for(int i = 0; i < n; i ++) {
        if(M == dist[i]) num ++;
    }
    printf("%.2f %d\n", p * pow((1 + r), M), num);
    return 0 ;
}