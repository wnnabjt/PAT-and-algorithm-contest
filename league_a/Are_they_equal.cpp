#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
char a[maxn], b[maxn], a1[maxn] = "0.", b1[maxn] = "0.";

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d %s %s", &n, a, b);
    int point1 = 0, point2 = 0;
    int lena = strlen(a), lenb = strlen(b);
    for(int i = 0; i < lena; i ++) {
        if(a[i] == '.') {
            point1 = i;
            break;
        }
    }
    for(int i = 0; i < lenb; i ++) {
        if(b[i] == '.') {
            point2 = i;
            break;
        }
    }
    if(point1 == 0) {
        a[lena] = '.';
        a[lena + 1] = '\0';
        point1 = lena;
    }
    if(point2 == 0) {
        b[lenb] = '.';
        b[lenb + 1] = '\0';
        point2 = lenb;
    }
    int s1 = 0, s2 = 0;
    while(s1 < point1) {
        if(a[s1] != '0') break;
        s1 ++;
    }
    while(s2 < point2) {
        if(b[s2] != '0') break;
        s2 ++;
    }
    int cnt1 = 2;
    int mmm = 0;
    int tes1 = 0, tes2 = 0;
    if(point1 == s1 && point2 == s2) {
        for(int i = s1 + 1; i < lena; i ++) {
            if(a[i] == '0') {
                point1 = i + 1;
                s1 = i + 1;
                tes1 ++;
            }
        }
        for(int i = s2 + 1; i < lenb; i ++) {
            if(b[i] == '0') {
                point2 = i + 1;
                s2 = i + 1;
                tes2 ++;
            }
        }
    }
    for(int i = s1; i < min(s1 + n + mmm, lena); i ++) {
        if(a[i] == '.') {
            mmm = 1;
            continue;
        }
        a1[cnt1 ++] = a[i];
    }
    a1[cnt1 ++] = '\0';
    int cnt2 = 2;
    mmm = 0;
    for(int i = s2; i < min(s2 + n + mmm, lenb); i ++) {
        if(b[i] == '.') {
            mmm = 1;
            continue;
        }
        b1[cnt2 ++] = b[i];
    }
    b1[cnt2 ++] = '\0';
    int za = point1 - s1, zb = point2 - s2;
    if(strlen(a1) < n + 2) {
        for(int i = strlen(a1); i < n + 2; i ++) {
            a1[i] = '0';
        }
        a1[n + 2] = '\0';
    }
    if(strlen(b1) < n + 2) {
        for(int i = strlen(b1); i < n + 2; i ++) {
            b1[i] = '0';
        }
        b1[n + 2] = '\0';
    }
    if(point1 == s1 && point2 == s2) {
        za = -1 * tes1;
        zb = -1 * tes2;
    }
    bool ff = true;
    for(int i = 2; i < strlen(a1); i ++) {
        if(a1[i] == b1[i] && a1[i] != '0') {
            ff = false;
            break;
        }
    }
    if((za == zb || ff) && (!strcmp(a1, b1))) {
        printf("YES %s*10^%d\n", b1, za);
    } else {
        printf("NO %s*10^%d %s*10^%d\n", a1, za, b1, zb);
    }
    return 0;
}