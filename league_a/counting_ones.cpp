#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int temp = n;
    int cnt = 1;
    long long ans = 0;
    int yu = 0;
    while(temp) {
        if(temp % 10 > 1) {
            ans += (temp / 10 + 1) * cnt;
        }
        else if(temp % 10 == 1) {
            ans += (temp / 10) * cnt + (yu + 1);
        }
        else {
            ans += (temp / 10) * cnt; 
        }
        yu = (temp % 10) * cnt + yu;
        cnt *= 10;
        temp /= 10;
    }
    printf("%lld\n", ans);
    return 0;
}