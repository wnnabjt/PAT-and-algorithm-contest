#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;
struct Edge {
    int to, next, from;
} edges[maxn << 1];
int head[maxn], cnt;
bool isCover[maxn << 1];//对于每一条边

void addedge(int u, int v) {
    edges[cnt].from = u; edges[cnt].to = v; edges[cnt].next = head[u]; 
    head[u] = cnt ++;
}

int main() {
    int n, m, k, u, v;
    memset(head, -1, sizeof head);
    scanf("%d %d", &n, &m);
    while(m --) {
        scanf("%d %d", &u, &v);
        if(u > v) swap(u, v);
        addedge(u, v);
        addedge(v, u);
    }
    scanf("%d", &k);
    int num;
    for(int i = 0; i < k; i ++) {
        scanf("%d", &num);
        bool ans = true;
        memset(isCover, false, sizeof isCover);
        for(int i = 0; i < num; i ++) {
            scanf("%d", &u);
            for(int k = head[u]; ~k; k = edges[k].next) {
                isCover[k] = true;
            } 
        }
        for(int i = 0; i < cnt; i ++) {
            if(!isCover[i]) {
                if(edges[i].from < edges[i].to) {
                    if(!isCover[i + 1]) {
                        ans = false;
                        break;
                    }
                }
            }
        }
        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}