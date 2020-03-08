#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, ans;

typedef long long ll;

const ll maxn = 2014 * 10000 + 9 * 100 + 6, minn = 1814 * 10000 + 9 * 100 + 6;

const int maxm = 100000 + 5;

struct Peo {
    char name[10];
    ll _hash;
} peo[maxm];

bool cmp(Peo a, Peo b) {
    return a._hash < b._hash;
}

int main() {
    char s[10];
    ll yy, mm, dd;
    scanf("%d", &n);
    while(n --) {
        scanf("%s %lld/%lld/%lld", s, &yy, &mm, &dd);
        yy = yy * 10000 + mm * 100 + dd;
        if(yy <= maxn && yy >= minn) {
            strcpy(peo[ans].name, s);
            peo[ans ++]._hash = yy;
        }
    }
    sort(peo, peo + ans, cmp);
    printf("%d %s %s\n", ans, peo[0].name, peo[ans - 1].name);
    return 0;
}
