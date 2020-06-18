#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int maxn = 100000 +5 ;
int val[maxn];

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &val[i]);
    }
    ll temp;
    int ans = 0, r;
    sort(val, val + n);
    for(int i = 0; i < n; i ++) {
        temp = ll(p) * val[i];//乘法先乘出结果，然后赋值。
        if(temp > 1e9) {
            r = n - i;
        } else {
            r = upper_bound(val, val + n, temp) - val - i;
        }
        ans = max(ans, r);
    }
    printf("%d\n", ans);
    return 0;
}