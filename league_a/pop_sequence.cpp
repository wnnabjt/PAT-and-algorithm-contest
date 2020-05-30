#include <cstdio>
using namespace std;

const int maxn = 1000 + 5;

int val[maxn], stack[maxn];

int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int now, num, top, base;
    while(k --) {
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &val[i]);
        }
        num = 0, now = 1;
        top = 0, base = 0;
        stack[++ top] = ++ num;
        while(true) {
            if(top != base) {
                while(top > base && stack[top] == val[now]) {
                    // printf("%d\t", stack[top]);
                    top --;
                    now ++;
                }
            }
            if(num >= n) break;
            if(top - base < m) {
                stack[++ top] = ++ num;
            } else break;
        }
        if(top == base) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}