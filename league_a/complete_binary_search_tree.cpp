#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
int val[maxn];

int tree[maxn << 2];

int cnt, n;

void build(int k) {
    if(k <= n) {
        build(k << 1);
        tree[k] = val[cnt ++];
        build(k << 1 | 1);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &val[i]);
    }
    sort(val, val + n);
    build(1);
    for(int i = 1; i <= n; i ++) {
        if(i != 1) printf(" ");
        printf("%d", tree[i]);
    }
    printf("\n");
    return 0;
}