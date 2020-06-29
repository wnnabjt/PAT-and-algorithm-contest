#include <cstdio>
using namespace std;

const int maxn = 1e5 + 5;
int n;
double val[maxn];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%lf", &val[i]);
    }
    long double sum = 0;
    for(int i = 0; i < n; i ++) {
        sum += val[i] * (i + 1) * (n - i);
    }
    printf("%.2Lf\n", sum);
    return 0;
}