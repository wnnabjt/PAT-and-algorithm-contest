#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5;
char s[maxn];

int main() {
    scanf("%s", s);
    int points, e = maxn, exp = 0;
    bool flag1, flag2;
    int len = strlen(s);
    for(int i = 0; i < len; i ++) {
        if(i == 0) {
            if(s[i] == '+') flag1 = true;
            else flag1 = false;
        } else if(s[i] == '.') {
            points = i;
        } else if(s[i] == 'E') {
            e = i;
        } else if(i == e + 1) {
            if(s[i] == '+') flag2 = true;
            else flag2 = false;
        } else if(i > e + 1) {
            exp = exp * 10 + s[i] - '0';
        }
    }
    if(!flag1) printf("-");
    if(flag2) {
        int end = points + exp + 1;
        for(int i = 1; i < e; i ++) {
            if(i == end) printf(".");
            if(i != points)
                printf("%c", s[i]);
        }
        for(int i = e; i < end; i ++) {
            printf("0");
        }
    } else {
        printf("0.");
        for(int i = 1; i < exp; i ++) printf("0");
        for(int i = 1; i < e; i ++) {
            if(i != points) {
                printf("%c", s[i]);
            }
        }
    }
    printf("\n");
    return 0;
}