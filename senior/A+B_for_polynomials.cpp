#include <cstdio>
using namespace std;

const int maxn = 1111 + 5;
double num[maxn];

int main() {
    int k, n;
    double an;
    scanf("%d", &k);
    int ans = 0;
    while(k --) {
        scanf("%d %lf", &n, &an);
        num[n] += an;
    }
    scanf("%d", &k);
    while(k --) {
        scanf("%d %lf", &n, &an);
        num[n] += an;
    }
    for(int i = 0; i < maxn; i ++) {
        if(num[i] != 0) ans ++;
    }
    printf("%d", ans);
    for(int i = maxn - 1; i >= 0; i --) {
        if(num[i]) {
            printf(" %d %.1f", i, num[i]);
        }
    }
    return 0;
}
