#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Stu {
    char id[9], name[9];
    int score;
};

const int maxn = 100000 + 5;

Stu stu[maxn];

bool cmp(const Stu a, const Stu b) {
    return strcmp(a.id, b.id) < 0;
}

bool cmp1(const Stu a, const Stu b) {
    return strcmp(a.name, b.name) == 0 ? strcmp(a.id, b.id) < 0 : strcmp(a.name, b.name) < 0;
}

bool cmp2(const Stu a, const Stu b) {
    return a.score == b.score ? strcmp(a.id, b.id) < 0: a.score < b.score;
}

int main() {
    int n, op;
    scanf("%d %d", &n, &op);
    for(int i = 0; i < n; i ++) {
        scanf("%s %s %d", &stu[i].id, &stu[i].name, &stu[i].score);
    }
    if(op == 1) {
        sort(stu, stu + n, cmp);
    } else if(op == 2) {
        sort(stu, stu + n, cmp1);
    } else {
        sort(stu, stu + n, cmp2);
    }
    for(int i = 0; i < n; i ++) {
        printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }
    return 0;
}