#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
using namespace std;

const int maxn = 200 + 5, inf = 0x3f3f3f3f;
int happiness[maxn];

int head[maxn], cnt;
struct Edge {
    int to, next, cost;
} edges[maxn * maxn];

void init() {
    cnt = 0;
    memset(head, -1, sizeof head);
}

void addedge(int u, int v, int cost) {
    edges[cnt].to = v; edges[cnt].cost = cost; edges[cnt].next = head[u];
    head[u] = cnt ++;
}

int s, t;
string ss, st = "ROM";

map <string, int> mp;
map <int, string> mp1;

int dist[maxn];

int pre[maxn];

bool vis[maxn];

void spfa(int u) {
    memset(vis, false, sizeof vis);
    memset(dist, inf, sizeof dist);
    vis[u] = true;
    dist[u] = 0;
    queue <int> que;
    que.push(u);
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int k = head[u]; ~k; k = edges[k].next) {
            int v = edges[k].to;
            if(dist[v] > dist[u] + edges[k].cost) {
                dist[v] = dist[u] + edges[k].cost;
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

int num;
struct A {
    vector <int> path;
    int happiness, num;
};
vector <A> ans;
vector <int> temp;

bool cmp(const A a, const A b) {
    if(a.happiness == b.happiness) {
        return a.num < b.num;
    } else {
        return a.happiness > b.happiness;
    }
}

void dfs(int u) {
    if(u == t) {
        int tot = 0;
        temp.clear();
        while(~u) {
            temp.push_back(u);
            tot += happiness[u];
            u = pre[u];
        }
        reverse(temp.begin(), temp.end());
        ans.push_back(A{temp, tot, int(temp.size())});
        return;
    }
    for(int k = head[u]; ~k; k = edges[k].next) {
        int v = edges[k].to;
        if(dist[v] == dist[u] + edges[k].cost) {
            pre[v] = u;
            dfs(v);
        }
    }
}

int main() {
    init();
    memset(pre, -1, sizeof pre);
    int n, k;
    cin >> n >> k >> ss;
    string name;
    int happ;
    s = 1;
    mp[ss] = 1;
    mp1[1] = ss;
    for(int i = 2; i <= n; i ++) {
        cin >> name >> happ;
        mp[name] = i;
        mp1[i] = name;
        happiness[i] = happ;
        if(name == "ROM") t = i;
    }
    string u, v;
    int w;
    while(k --) {
        cin >> u >> v >> w;
        addedge(mp[u], mp[v], w);
        addedge(mp[v], mp[u], w); 
    }
    spfa(1);
    dfs(1);
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << ' ' << dist[t] << ' ' << ans[0].happiness << ' ' << ans[0].happiness / (ans[0].num - 1) << endl;
    for(int i = 0; i < ans[0].path.size(); i ++) {
        if(i) cout << "->";
        cout << mp1[ans[0].path[i]];
    }
    cout << endl;
    return 0;
}