#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 400000 + 5;

int num[maxn];

int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i ++) {
        scanf("%d", num + n + i);
    }
    sort(num, num + n + m);
    int mid = (n + m) & 1 ? (n + m) / 2 : (n + m - 1) / 2;
    printf("%d\n", num[mid]);
    return 0;
}