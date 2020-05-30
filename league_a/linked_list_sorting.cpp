#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;

struct Edge {
    int data, ad;
} edges[maxn];

bool cmp(Edge a, Edge b) {
    return a.data < b.data;
}

struct A {
    int l, data, r;
} ans[maxn];

bool vis[maxn];
int head[maxn];

int main() {
    memset(head, -1, sizeof head);
    int n, m;
    scanf("%d %d", &n, &m);
    int l, data, r;
    for(int i = 0; i < n; i ++) {
        scanf("%d %d %d", &l, &data, &r);
        edges[i] = Edge {data, l};
        head[l] = r;
    }
    while(true) {
        vis[m] = true;
        m = head[m];
        if(m == -1) break;
    }
    sort(edges, edges + n, cmp);
    int now = 0;
    for(int i = 0; i < n - 1; i ++) {
        if(vis[edges[i].ad])
            ans[now ++] = A{edges[i].ad, edges[i].data, edges[i + 1].ad};
    }
    if(vis[edges[n - 1].ad])
        ans[now ++] = A{edges[n - 1].ad, edges[n - 1].data, -1};
    printf("%d %d\n", now, edges[0].ad);
    for(int i = 0; i < now - 1; i ++) {
        printf("%05d %d %05d\n", ans[i].l, ans[i].data, ans[i].r);
    }
    printf("%05d %d -1\n", ans[now - 1].l, ans[now - 1].data);
    return 0;
}