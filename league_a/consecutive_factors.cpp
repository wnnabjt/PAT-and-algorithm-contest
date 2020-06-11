#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct A {
    int l, r;
};
vector <A> ans;

bool cmp(A a, A b) {
    if(a.r - a.l == b.r - b.l) return a.l < b.l;
    else return a.r - a.l > b.r - b.l;
}

int main() {
    int n;
    scanf("%d", &n);
    int temp;
    for(int i = 2; i <= sqrt(n); i ++) {
        int now = i;
        temp = n;
        while(temp % now == 0) {
            temp /= now;
            now ++;
        }
        if(now > i) {
            ans.push_back(A{i, now - 1});
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    if(ans.size() > 0 && ans[0].r - ans[0].l >= 0) {
        printf("%d\n", ans[0].r - ans[0].l + 1);
        for(int i = ans[0].l; i <= ans[0].r; i ++) {
            if(i != ans[0].l) printf("*");
            printf("%d", i);
        }
    } else printf("1\n%d", n);
    printf("\n");
    return 0;
}