#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int maxn = 1e6 + 5;

struct Edge {
    int to;
    char c;
} edges[maxn];

typedef pair <char, int> pci;

vector <pci> path1, path2;
bool vis[maxn];

int main() {
    memset(edges, -1, sizeof edges);
    int s1, s2, n, u, v;
    char c;
    scanf("%d %d %d", &s1, &s2, &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d %c %d", &u, &c, &v);
        edges[u].to = v;
        edges[u].c = c;
    }
    while(~s1) {
        vis[s1] = true;
        s1 = edges[s1].to;
    }
    int ans = -1;
    while(~s2) {
        if(vis[s2]) {
            ans = s2;
            break;
        }
        s2 = edges[s2].to;
    }
    if(~ans) printf("%05d\n", ans);
    else printf("%d\n", ans);
    return 0;
}