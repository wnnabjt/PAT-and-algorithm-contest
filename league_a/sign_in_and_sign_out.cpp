#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;

struct Stu {
    char name[15];
    int bh, bm, bs, eh, em, es;
} stu[maxn];

bool cmp1(Stu a, Stu b) {
    if(a.bh == b.bh) {
        if(a.bm == b.bm) {
            return a.bs < b.bs;
        } else return a.bm < b.bm;
    } else return a.bh < b.bh;
}

bool cmp2(Stu a, Stu b) {
    if(a.eh == b.eh) {
        if(a.em == b.em) {
            return a.es > b.es;
        } else return a.em > b.em;
    } else return a.eh > b.eh;
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i ++) {
            scanf("%s %d:%d:%d %d:%d:%d", stu[i].name, &stu[i].bh, &stu[i].bm, &stu[i].bs,
                                                        &stu[i].eh, &stu[i].em, &stu[i].es);

        }
        sort(stu, stu + n, cmp1);
        printf("%s ", stu[0].name);
        sort(stu, stu + n, cmp2);
        printf("%s\n", stu[0].name);
    }
    return 0;
}
