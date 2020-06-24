#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int maze[65][1300][130];
bool vis[65][1300][130];

int n, m, piece, limit;

int ans, num, cnt;

struct B {
    int p, x, y;
};

void bfs(int p, int x, int y) {
    queue <B> que;
    que.push(B{p, x, y});
    while(!que.empty()) {
        B u = que.front();
        que.pop();
        if(u.p < 0 || u.p >= piece || u.x < 0 || u.x >= n || u.y < 0 || u.y >= m || vis[u.p][u.x][u.y] || !maze[u.p][u.x][u.y]) {
            continue;
        }
        num ++;
        vis[u.p][u.x][u.y] = true;
        for(int dx = -1; dx <= 1; dx ++) {
            for(int dy = -1; dy <= 1; dy ++) {
                if(abs(dx - dy) == 1) {
                    que.push(B{u.p, u.x + dx, u.y + dy});
                }
            }
        }
        for(int dp = -1; dp <= 1; dp ++) {
            if(dp != 0) {
                que.push(B{u.p + dp, u.x, u.y});
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &piece, &limit);
    for(int i = 0; i < piece; i ++) {
        for(int j = 0; j < n; j ++) {
            for(int k = 0; k < m; k ++) {
                scanf("%d", &maze[i][j][k]);
            }
        }
    }
    for(int i = 0; i < piece; i ++) {
        for(int j = 0; j < n; j ++) {
            for(int k = 0; k < m; k ++) {
                if(!vis[i][j][k] && maze[i][j][k]) {
                    num = 0;
                    bfs(i, j, k);
                    if(num >= limit) ans += num;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}