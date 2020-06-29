#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5, maxe = 100 + 5;
int val[maxn];
int gaze[maxe][maxe];

bool cmp(const int a, const int b) {
    return a > b;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i ++) {
        scanf("%d", &val[i]);
    }
    sort(val + 1, val + N + 1, cmp);
    int b = sqrt(N);
    while(true) {
        if(N % b == 0) break;
        b --;
    }
    int n = N / b, m = b;
    int x = 1, y = 0, cnt = 0;
    while(cnt < N) {
        while(y + 1 <= m && !gaze[x][y + 1]) gaze[x][++ y] = val[++ cnt];
        while(x + 1 <= n && !gaze[x + 1][y]) gaze[++ x][y] = val[++ cnt];
        while(y - 1 > 0 && !gaze[x][y - 1]) gaze[x][-- y] = val[++ cnt];
        while(x - 1 > 0 && !gaze[x - 1][y]) gaze[-- x][y] = val[++ cnt];
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(j != 1) printf(" ");
            printf("%d", gaze[i][j]);
        }
        printf("\n");
    }
    return 0;
}