#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100 + 5;

int weight[maxn];

int n, m, s;

struct Edge {
    int to, next;
} edges[maxn * maxn];

int head[maxn], cnt;

void init() {
    memset(head, -1, sizeof head);
    cnt = 2;
}

void addedge(int u, int v) {
    edges[cnt].to = v; edges[cnt].next= head[u];
    head[u] = cnt ++;
}

vector <int> path;
vector <int> ans[maxn];

int tot, tot_path;


void dfs(int u) {
    if(tot == s && !~head[u]) {
        ans[tot_path ++] = path;
        return;
    } else if(tot > s) {
        return;
    }
    for(int k = head[u]; ~k; k = edges[k].next) {
        int v = edges[k].to;
        tot += weight[v];
        path.push_back(weight[v]);
        dfs(v);
        tot -= weight[v];
        path.pop_back();
    }
}

bool cmp(vector <int> a, vector <int> b) {
    for(int i = 0; i < min(a.size(), b.size()); i ++) {
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return a.size() > b.size();
}

int main() {
    init();
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &weight[i]);
    }
    int u, v, num;
    while(m --) {
        scanf("%d %d", &u, &num);
        while(num --) {
            scanf("%d", &v);
            addedge(u, v);
        }
    }
    for(int i = 0; i < 1; i ++) {
        path.clear();
        tot = weight[i];
        path.push_back(weight[i]);
        dfs(i);
    }
    sort(ans, ans + tot_path, cmp);
    for(int i = 0; i < tot_path; i ++) {
        for(int j = 0; j < ans[i].size(); j ++) {
            if(j) printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}