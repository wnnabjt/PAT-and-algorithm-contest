#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5, inf = 0x3f3f3f3f;

struct Edge {
    int data, ad;
} edges[maxn];

int p[maxn];

bool cmp(Edge a, Edge b) {
    return a.data < b.data;
}

int head[maxn];

int main() {
    memset(head, -1, sizeof head);
    memset(p, inf, sizeof p);
    int n, m;
    scanf("%d %d", &n, &m);
    int l, data, r;
    for(int i = 0; i < n; i ++) {
        scanf("%d %d %d", &l, &data, &r);
        p[l] = data;
        head[l] = r;
    }
    int now = 0;
    while(true) {
        if(m >= 0 && p[m] != inf)
            edges[now ++] = Edge {p[m], m};
        m = head[m];
        if(m == -1) break;
    }
    if(now == 0) {
        printf("0 -1\n");
    } else {
        sort(edges, edges + now, cmp);
        printf("%d %05d\n", now, edges[0].ad);
        for(int i = 0; i < now - 1; i ++) {
            printf("%05d %d %05d\n", edges[i].ad, edges[i].data, edges[i + 1].ad);
        }
        printf("%05d %d -1\n", edges[now - 1].ad, edges[now - 1].data);
    }
    return 0;
}