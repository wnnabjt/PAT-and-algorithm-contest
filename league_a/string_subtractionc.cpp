#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5;

char s1[maxn], s2[maxn];

bool vis[200];

int main() {
    scanf("%[^\n] %[^\n]", s1, s2);
    for(int i = 0; i < strlen(s2); i ++) {
        vis[s2[i]] = true;
    }
    for(int i = 0; i < strlen(s1); i ++) {
        if(!vis[s1[i]]) {
            printf("%c", s1[i]);
        }
    }
    printf("\n");
    return 0;
}