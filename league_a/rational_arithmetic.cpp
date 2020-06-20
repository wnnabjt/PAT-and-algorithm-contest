#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void func(ll m, ll n) {
    if(m * n == 0) {
        printf("%s", n == 0 ? "Inf" : "0");
        return;
    }
    bool flag = ((m < 0 && n > 0) || (m > 0 && n < 0));
    m = abs(m), n = abs(n);
    ll x = m / n;
    printf("%s", flag ? "(-" : "");
    if(x) printf("%lld", x);
    if(!(m % n)) {
        if(flag) printf(")");
        return;
    }
    if(x) printf(" ");
    m = m % n;
    ll t = gcd(m, n);
    m /= t, n /= t;
    printf("%lld/%lld%s", m, n, flag ? ")" : "");
}

int main() {
    ll a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    func(a, b); printf(" + "); func(c, d); printf(" = "); func(a * d + b * c, b * d); printf("\n");
    func(a, b); printf(" - "); func(c, d); printf(" = "); func(a * d - b * c, b * d); printf("\n");
    func(a, b); printf(" * "); func(c, d); printf(" = "); func(a * c, b * d); printf("\n");\
    func(a, b); printf(" / "); func(c, d); printf(" = "); func(a * d, b * c);
    return 0;
}