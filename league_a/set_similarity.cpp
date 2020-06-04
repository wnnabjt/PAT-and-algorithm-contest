/*
    Nc是两个集合的交集的大小。
    Nt是两个集合的并集的大小。
*/
#include <cstdio>
#include <set>
using namespace std;

const int maxn = 50 + 5;
set <int> s[maxn], temp;

int main() {
    int n, k, cnt, num, l, r, sum1, sum2;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &cnt);
        while(cnt --) {
            scanf("%d", &num);
            s[i].insert(num);
        }
    }
    scanf("%d", &k);
    set <int> :: iterator i;
    while(k --) {
        scanf("%d %d", &l, &r);
        sum1 = 0;
        sum2 = s[r].size();
        for(i = s[l].begin(); i != s[l].end(); i ++) {
            if(s[r].find(*i) != s[r].end()) sum1 ++;
            else sum2 ++;
        }
        char c = '%';
        printf("%.1f%c\n", sum1 * 100.0 / sum2, c);
        temp.clear();
    }
    return 0;
}