#include <cstdio>
using namespace std;

const int maxn = 100 + 5;
int a[maxn], b[maxn];

typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int numerator, denominator;

void _add(int a, int b) {
    numerator = numerator * b + a * denominator;
    denominator *= b;
    if(numerator == 0) return;
    int g = gcd(numerator, denominator);
    // if(g < 0) g = -g;
    if(g != 1) {
        numerator /= g;
        denominator /= g;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d/%d", &a[i], &b[i]);
    }
    numerator = a[0];
    denominator = b[0];
    for(int i = 1; i < n; i ++) {
        _add(a[i], b[i]);
    }
    if(numerator == 0) {
        printf("0\n");
    } else if(numerator / denominator) {
        printf("%d", numerator / denominator);
        if(numerator % denominator) {
            printf(" %d/%d\n", numerator % denominator, denominator);
        }
    } else if(numerator % denominator) {
        printf("%d/%d\n", numerator, denominator);
    }
    return 0;
}