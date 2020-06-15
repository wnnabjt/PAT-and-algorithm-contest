#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 40000 + 5;

struct Stu {
    int ge, gi, sum, id;
    int prefer[6];
    int _rank;
} stu[maxn];

bool cmp(const Stu a, const Stu b) {
    if(a.sum == b.sum) {
        return a.ge > b.ge;
    } else {
        return a.sum > b.sum;
    }
}

struct G_school {
    int quota, num;
    vector <int> admit;
} sch[100 + 5];

int n, m, k;

bool cmp1(int a, int b) {
    return stu[a].id < stu[b].id;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i ++) {
        scanf("%d", &sch[i].quota);
    }
    for(int i = 0; i < n; i ++) {
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        stu[i].sum = stu[i].ge + stu[i].gi;
        stu[i].id = i;
        for(int j = 0; j < k; j ++) {
            scanf("%d", &stu[i].prefer[j]);
        }
    }
    sort(stu, stu + n, cmp);
    stu[0]._rank = 1;
    int cnt = 1;
    for(int i = 1; i < n; i ++) {
        if(stu[i].sum != stu[i - 1].sum || stu[i].ge != stu[i - 1].ge) cnt = i + 1;
        stu[i]._rank = cnt;
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < k; j ++) {
            G_school &temp = sch[stu[i].prefer[j]];
            if(temp.quota > temp.num) {
                temp.admit.push_back(i);
                temp.num ++;
                break;
            } else if(stu[i]._rank == stu[temp.admit.back()]._rank) {
                temp.admit.push_back(i);
                temp.num ++;
                break;
            }
        }
    }
    for(int i = 0; i < m; i ++) {
        sort(sch[i].admit.begin(), sch[i].admit.end(), cmp1);
        for(int j = 0; j < sch[i].admit.size(); j ++) {
            if(j) printf(" ");
            printf("%d", stu[sch[i].admit[j]].id);
        }
        printf("\n");
    }
    return 0;
}