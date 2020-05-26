#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map <string, int> mp1;
map <int, string> mp2;

const int maxn = 2000 + 5;

struct Edge {
    int to, w, next;
} edges[maxn];

int head[maxn], cnt, maze[maxn][maxn];

void init() {
    memset(head, -1, sizeof head);
}

void addedge(int u, int v, int w) {
    edges[cnt].to = v; edges[cnt].w = w; edges[cnt].next = head[u];
    head[u] = cnt ++;
}

int k;

int price[maxn];

bool vis[maxn], vis2[maxn][maxn];

int Max_id, tot_call, max_num, num;

void dfs(int u, int pre) {
    vis[u] = true;
    for(int k = head[u]; ~k; k = edges[k].next) {
        int v = edges[k].to;
        if(!vis2[u][v]) {
            vis2[u][v] = vis2[v][u] = true;
            if(price[v] > max_num) {
                max_num = price[v];
                Max_id = v;
            }
            tot_call += maze[u][v];
            if(!vis[v])
                num ++;
            dfs(v, u);
        }
    }
}

struct Ans {
    string s;
    int num;
};

vector <Ans> ans;

bool cmp(const Ans a, const Ans b) {
    return a.s < b.s;
}

int main() {
    init();
    int n;
    cin >> n >> k;

    string s, t;
    int u, v, w;
    int tot_peo = 1;
    for(int i = 0; i < n; i ++) {
        cin >> s >> t >> w;
        if(!mp1[s]) {
            mp2[tot_peo] = s;
            mp1[s] = tot_peo ++;
        }
        if(!mp1[t]) {
            mp2[tot_peo] = t;
            mp1[t] = tot_peo ++;
        }
        u = mp1[s];
        v = mp1[t];
        price[u] += w;
        price[v] += w;
        addedge(u, v, w);
        addedge(v, u, w);
        maze[u][v] += w;
        maze[v][u] += w;
    }
    for(int i = 1; i < tot_peo; i ++) {
        if(!vis[i]) {
            Max_id = i;
            max_num = price[i];
            tot_call = 0;
            num = 1;
            dfs(i, -1);
            if(tot_call > k && num > 2) {
                ans.push_back(Ans{mp2[Max_id], num});
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for(unsigned int i = 0; i < ans.size(); i ++) {
        cout << ans[i].s << ' ' << ans[i].num << endl;
    }
    return 0;
}