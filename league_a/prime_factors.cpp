#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

const int maxn = 1e7;
bool isprime[maxn];
int prime_list[maxn];
int cnt;

void init() {
    for(int i = 2; i < maxn; i ++) {
        if(!isprime[i])
            prime_list[cnt ++] = i;
        for(int j = 0; j < cnt; j ++) {
            if(ll(i * prime_list[j]) > maxn) break;
            if(ll(i * prime_list[j]) < maxn)
                isprime[i * prime_list[j]] = true;//每个合数都被他的最小质因数标记
            if(i % prime_list[j] == 0)   break; //当发现某个合数存在更小的质因数时就停止标记
        }
    }
}

int main() {
    init();
    ll n;
    scanf("%lld", &n);
    bool flag = true;
    for(int i = 2; i <= sqrt(n); i ++) {
        if(n % i == 0) {
            flag = false;
            break;
        }
    }
    if(n != 0 && n != 1 && !flag) {
        int now = 0;
        printf("%lld=", n);
        while(true) {
            if(prime_list[now] > n) break;
            if(n % prime_list[now] == 0) {
                n /= prime_list[now];
                int ans = 1;
                while(n && n % prime_list[now] == 0) {
                    ans ++;
                    n /= prime_list[now];
                }
                if(flag) printf("*");
                flag = true;
                printf("%d", prime_list[now]);
                if(ans > 1) printf("^%d", ans);
            }
            now ++;
        }
    } else printf("%lld=%lld\n", n, n);
    return 0;
}