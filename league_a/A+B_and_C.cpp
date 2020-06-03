#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
    ll a, b, c;
    int t;
    scanf("%d", &t);
    int _case = 0;
    bool flag;
    while(t --) {
        scanf("%lld %lld %lld", &a, &b, &c);
        ll sum = a + b;
        if(a > 0 && b > 0 && sum < 0) flag = true;
        else if(a < 0 && b < 0 && sum >= 0) flag = false;
        else if(sum > c) flag = true;
        else flag = false;
        printf("Case #%d: ", ++ _case);
        if(flag) printf("true\n");
        else printf("false\n");
    }
    return 0;
}