#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5;

struct Edge {
    int to, next;
} edges[maxn << 1];

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

bool flag;

int depth[maxn];

set <int> ans;

void dfs(int u) {
    vis[u] = true;
    for(int k = head[u]; ~k; k = edges[k].next) {
        int v = edges[k].to;
        if(!vis[v]) {
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

int main() {
    init();
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n - 1; i ++) {
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    int con_num = 0;
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            dfs(i);
            con_num ++;
        }
    }
    if(con_num > 1) printf("Error: %d components", con_num);
    else {
        int temp = max_element(depth + 1, depth + 1 + n) - depth;
        for(int i = 1; i <= n; i ++) if(depth[i] == depth[temp]) ans.insert(i);
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; i ++) depth[i] = 0;
        dfs(temp);
        temp = max_element(depth + 1, depth + 1 + n) - depth;
        for(int i = 1; i <= n; i ++) if(depth[i] == depth[temp]) ans.insert(i);
    }
    set <int> :: iterator i;
    for(i = ans.begin(); i != ans.end(); i ++) printf("%d\n", *i);
    return 0;
}
