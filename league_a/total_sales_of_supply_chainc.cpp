#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1e5 + 5;

int needs[maxn];
int d[maxn];

double p, r;
double ans;

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

void bfs(int s) {
    queue <int> que;
    que.push(s);
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        if(head[u] == -1) {
            ans += needs[u] * pow(1 + r, d[u]);
        }
        for(int k = head[u]; ~k; k = edges[k].next) {
            int v = edges[k].to;
            d[v] = d[u] + 1;
            que.push(v);
        }
    }
}

int main() {
    init();
    int n;
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    int num, v;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &num);
        if(num == 0) {
            scanf("%d", &v);
            needs[i] = v;
        } else {
            while(num --) {
                scanf("%d", &v);
                addedge(i, v);
            }
        }
    }
    bfs(0);
    printf("%.1f\n", ans * p);
    return 0 ;
}