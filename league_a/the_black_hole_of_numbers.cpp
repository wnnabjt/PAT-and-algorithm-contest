#include <cstdio>
#include <algorithm>
using namespace std;

int Min, Max;

int a[4];

void update(int n) {
    for(int i = 0; i < 4; i ++) a[i] = 0;
    int cnt = 0;
    while(n) {
        a[cnt ++] = n % 10;
        n /= 10;
    }
    sort(a, a + 4);
    Min = Max = 0;
    for(int i = 0; i < 4; i ++) Min = Min * 10 + a[i];
    for(int i = 3; i >= 0; i --) Max = Max * 10 + a[i];
}

int main() {
    int n;
    scanf("%d", &n);
    while(true) {
        update(n);
        n = Max - Min;
        printf("%04d - %04d = %04d\n", Max, Min, n);
        if(n == 0 || n == 6174) break;
    }
    return 0;
}