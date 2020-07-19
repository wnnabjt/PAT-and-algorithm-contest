#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5;
struct Edge {
    int to, next;
} edges[maxn];
int head[maxn], cnt;

void addedge(int u, int v) {
    edges[cnt].to = v; edges[cnt].next = head[u]; head[u] = cnt ++;
    edges[cnt].to = u; edges[cnt].next = head[v]; head[v] = cnt ++;
}

bool vis[maxn];

void dfs(int u) {
    
}

int main() {
    int n, m, k, u, v;
    scanf("%d %d", &n, &m);
    while(m --) {
        scanf("%d %d", &u, &v);
        addedge(u, v);
    }
    for(int i = 0; i < n; i ++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    return 0;
}