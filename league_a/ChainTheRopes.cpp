#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;
int ropes[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", ropes + i);
    }
    sort(ropes, ropes + n);
    int res = ropes[0];
    for(int i = 1; i < n; i ++) {
        res = (res + ropes[i]) / 2;
    }
    printf("%d\n", res);
    return 0;
}