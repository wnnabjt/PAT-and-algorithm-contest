/*
    本题思路：
        1：求出最短路径
        2：利用dfs，求出每条最短路的具体路径，以及在某条路径上需要派遣和遣返
            的自行车的数量。
        3：将所有路径按照，派遣数目增序进行排序，派遣数目相同的按照遣返数目
            的增序进行排列，输出第一个答案。
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 500 + 5, inf = 0x3f3f3f3f;

int t, c;

struct Edge {
    int to, cost, next;
} edges[maxn * maxn];

int head[maxn], cnt;

void addedge(int u, int v, int w) {
    edges[cnt] = Edge{v, w, head[u]};
    head[u] = cnt ++;
    edges[cnt] = Edge{u, w, head[v]};
    head[v] = cnt ++;
}

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}

bool vis[maxn];

int dist[maxn], cap[maxn];

void spfa(int s, int t) {
    memset(dist, inf, sizeof dist);
    memset(vis, false, sizeof vis);
    queue <int> que;
    que.push(s);
    vis[s] = true;
    dist[s] = 0;
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int k = head[u]; ~k; k = edges[k].next) {
            int v = edges[k].to;
            if(dist[v] > dist[u] + edges[k].cost) {
                dist[v] = dist[u] + edges[k].cost;
                if(!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
}

struct Ans {
    int sent, back;
    vector <int> path;
} ans[maxn * maxn];
int num;

bool cmp(Ans a, Ans b) {
    if(a.sent == b.sent) return a.back < b.back;
    else return a.sent < b.sent;
}

int pre[maxn];

void dfs(int u) {
    if(u == t) {
        int now = u;
        while(~ now) {
            ans[num].path.push_back(now);
            now = pre[now];
        }
        num ++;
        return;
    }
    for(int k = head[u]; ~k; k = edges[k].next) {
        int v = edges[k].to;
        int temp1 = ans[num].sent;
        int temp2 = ans[num].back;
        if(dist[v] == dist[u] + edges[k].cost) {
            pre[v] = u;
            if(cap[v] > c / 2) {
                ans[num].back += cap[v] - c / 2;
            }
            else {
                if(ans[num].back  > c / 2 - cap[v]) ans[num].back  -= (c / 2 - cap[v]);
                else {
                    ans[num].sent += c / 2 - cap[v] - ans[num].back ;
                    ans[num].back  = 0;
                }
            }
            dfs(v);
            ans[num].sent = temp1;
            ans[num].back = temp2;
        }
    }
}

int main() {
    init();
    int n, m, u, v, w;
    scanf("%d %d %d %d", &c, &n, &t, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &cap[i]);
    while(m --) {
        scanf("%d %d %d", &u, &v, &w);
        addedge(u, v, w);
    }
    memset(pre, -1, sizeof pre);
    spfa(0, t);
    num = 0;
    dfs(0);
    sort(ans, ans + num, cmp);
    printf("%d ", ans[0].sent);
    for(int i = ans[0].path.size() - 1; i > 0; i --) {
        printf("%d->", ans[0].path[i]);
    }
    printf("%d", t);
    printf(" %d\n", ans[0].back);
    return 0;
}
