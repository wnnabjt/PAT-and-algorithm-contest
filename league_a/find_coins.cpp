#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;

int num[maxn];

int main() {
    int n, k, coins;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &coins);
        if(coins > 0 && coins < maxn) {
            num[coins] ++;
        }
    }

    int ans = 0;
    for(int i = 0; i < maxn; i ++) {
        if(i == k - i) {
            if(num[i] > 1) {
                ans = i;
            }
            break;
        }
        if(num[i] && num[k - i]) {
            ans = i;
            break;
        }
    }
    if(ans) {
        printf("%d %d\n", ans, k - ans);
    } else printf("No Solution\n");
    return 0;
}