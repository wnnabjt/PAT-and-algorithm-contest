#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int maxn = 1000 + 5, maxm = 1000 * 100 + 5;

struct Edge {
    int to, next;
} edges[maxm];
int head[maxn], cnt;

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}

void addedge(int u, int v) {
    edges[cnt].to = v;
    edges[cnt].next = head[u];
    head[u] = cnt ++;
}

bool vis[maxn];
vector <int> vec, temp;

int num;

void bfs() {
    for(int i = 0; i < vec.size(); i ++) {
        int u = vec[i];
        vis[u] = true;
        for(int k = head[u]; ~k; k = edges[k].next) {
            int v = edges[k].to;
            if(!vis[v]) {
                vis[v] = true;
                num ++;
                temp.push_back(v);
            }
        }
    }
}

int main() {
    init();
    int n, levels, k, op;
    scanf("%d %d", &n, &levels);
    int tot, v;
    for(int u = 1; u <= n; u ++) {
        scanf("%d", &tot);
        while(tot --) {
            scanf("%d", &v);
            addedge(v, u);
        }
    }
    scanf("%d", &k);
    while(k --) {
        scanf("%d", &op);
        vec.clear();
        vec.push_back(op);
        num = 0;
        memset(vis, false, sizeof vis);
        for(int l = 0; l < levels; l ++) {
            bfs();
            vec = temp;
            temp.clear();
        }
        printf("%d\n", num);
    }
    return 0;
}