#include <cstdio>
#include <cstring>
#include <string>
// #include <cctype>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 15, maxm = 10000 * 2 + 5, inf = 0x3f3f3f3f;
int head[maxn], cnt;

void init() {
    memset(head, -1,sizeof head);
    cnt = 0;
}

struct Edge {
    int to, next, cost;
} edges[maxm];

void addedge(int u, int v, int cost) {
    edges[cnt].to = v; edges[cnt].cost = cost;
    edges[cnt].next = head[u]; head[u] = cnt ++;
}

int n, m, k, min_d;

int dist[maxn];
bool vis[maxn];

void spfa(int s) {
    memset(dist, inf, sizeof dist);
    memset(vis, false, sizeof vis);   
    dist[s] = 0;
    vis[s] = true;
    queue <int> que;
    que.push(s);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        vis[u] = false;
        for(int k = head[u]; ~k; k = edges[k].next) {
            int v = edges[k].to;
            // if(v > n && v != s) continue;
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

struct A {
    string name;
    double Min, ave;
    int id;
};

vector <A> ans;

bool cmp(const A a, const A b) {
    if(a.Min + 0.05 > b.Min && a.Min - 0.05 < b.Min) {
        if(a.ave + 0.05 > b.ave && a.ave - 0.05 < b.ave) {
            return a.id < b.id;
        } else return a.ave < b.ave;
    } else return a.Min > b.Min;
}

int main() {
    init();
    scanf("%d %d %d %d", &n, &m, &k, &min_d);
    char u[10], v[10];
    string s1, s2;
    int cost, u1, v1;
    while(k --) {
        scanf("%s %s %d", u, v, &cost);
        u1 = v1 = 0;
        if(isdigit(u[0])) {
            s1.assign(&u[0]);
            u1 = stoi(s1);
        } else {
            s1.assign(&u[1]);
            u1 = stoi(s1) + n;
        }
        if(isdigit(v[0])) {
            s2.assign(&v[0]);
            v1 = stoi(s2);
        } else {
            s2.assign(&v[1]);
            v1 = stoi(s2) + n;
        }
        addedge(u1, v1, cost);
        addedge(v1, u1, cost);
    }
    double sum;
    int Min, Max;
    int id;
    double AVE;
    Max = 0;
    AVE = inf;
    for(int i = n + 1; i <= n + m; i ++) {
        spfa(i);
        sum = 0.0;
        Min = inf;
        for(int j = 1; j <= n; j ++) {
            if(dist[j] > min_d) {
                Min = -1;
                break;
            }
            if(dist[j] < Min) Min = dist[j];
            sum += dist[j] * 1.0;
        }
        sum /= n;
        if(Min > Max) {
            Max = Min;
            AVE = sum;
            id = i;
        } else if(Min == Max && sum < AVE) {
            id = i;
            AVE = sum;
        }
    }
    if(Max > 0) {
        printf("G%d\n%.1f %.1f\n", id - n, double(Max), AVE);
    } else printf("No Solution\n");
    return 0;
}