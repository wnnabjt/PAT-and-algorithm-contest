#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 500 + 5, maxm = maxn * maxn;

struct Edge {
    int to, next;
} edges[maxm];
int head[maxn], cnt;

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}

void addedge(int u, int v) {
    edges[cnt].to = v; edges[cnt].next = head[u];
    head[u] = cnt ++;
}

int degree[maxn];
bool vis[maxn];

void dfs(int u, int pre) {
    vis[u] = true;
    for(int k = head[u]; ~k; k = edges[k].next) {
        int v = edges[k].to;
        if(!vis[v] && v != pre) {
            dfs(v, u);
        }
    }
}

int main() {

    int n, m, u, v;
    scanf("%d %d", &n, &m);
    init();
    memset(degree, 0, sizeof degree);
    while(m --) {
        scanf("%d %d", &u, &v);
        degree[u] ++;
        degree[v] ++;
        addedge(u, v);
        addedge(v, u);
    }
    int num = 0;
    for(int i = 1; i <= n; i ++) {
        if(degree[i] & 1) {
            num ++;
        }
        printf("%d", degree[i]);
        printf("%s", i == n ? "\n" : " ");
    }
    if(num ==0 || num == 2) {
        memset(vis, false, sizeof vis);
        dfs(1, -1);
        bool flag = true;
        for(int i = 1; i <= n; i ++) {
            if(!vis[i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(num == 0) {
                printf("Eulerian");
            } else {
                printf("Semi-Eulerian");
            }
        } else {
            printf("Non-Eulerian");
        }
    } else {
        printf("Non-Eulerian");
    }
    printf("\n");
    return 0;
}