#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
int idx[maxn];

int main() {
    int n, temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &temp);
        idx[temp] = i;
    }
    int cnt = 0, Min = 0;
    bool flag;
    while(true) {
        if(idx[0] != 0) {
            swap(idx[0], idx[idx[0]]);
            cnt ++;
        } else {
            flag = false;
            for(int i = Min; i < n; i ++) {
                if(idx[i] != i) {
                    swap(idx[0], idx[i]);
                    cnt ++;
                    Min = i;
                    flag = true;
                    break;
                }
            }
            if(!flag) break;
        }
    }
    printf("%d\n", cnt);
    return 0;
}