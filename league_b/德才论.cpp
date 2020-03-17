/*
    PAT�Ҽ���������
    �²��ۣ���Ŀ���������Ǹ��򵥵Ľṹ������
    ������vectorҲ���������飬�����������vector�ˡ�
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Stu {
    Stu() {}
    Stu(ll  id, int d, int c, int tot) : id(id), d(d), c(c), tot(tot) {}
    ll id;
    int d, c, tot;
};

vector <Stu> A, B, C, D;
Stu stu;

bool cmp(Stu a, Stu b) {
    if(a.tot == b.tot) {
        if(a.d == b.d) return a.id < b.id;
        else return a.d > b.d;
    } else return a.tot > b.tot;
}

int main() {
    int n, l, h;
    cin >> n >> l >> h;
    while(n --) {
        cin >> stu.id >> stu.d >> stu.c ;
        stu.tot = stu.d + stu.c;
        if(stu.d >= l && stu.c >= l) {
            if(stu.d >= h && stu.c >= h) {
                A.push_back(stu);
            } else if(stu.c < h && stu.d >= h) {
                B.push_back(stu);
            } else if(stu.d < h && stu.c < h && stu.d >= stu.c) {
                C.push_back(stu);
            } else {
                D.push_back(stu);
            }
        } else {
            continue;
        }
    }
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    sort(C.begin(), C.end(), cmp);
    sort(D.begin(), D.end(), cmp);
    printf("%d\n", A.size() + B.size() + C.size() + D.size());
    vector <Stu> :: iterator i;
    for(i = A.begin(); i != A.end(); i ++) {
        printf("%lld %d %d\n", i -> id, i -> d, i -> c);
    }
    for(i = B.begin(); i != B.end(); i ++) {
        printf("%lld %d %d\n", i -> id, i -> d, i -> c);
    }
    for(i = C.begin(); i != C.end(); i ++) {
        printf("%lld %d %d\n", i -> id, i -> d, i -> c);
    }
    for(i = D.begin(); i != D.end(); i ++) {
        printf("%lld %d %d\n", i -> id, i -> d, i -> c);
    }
    return 0;
}
