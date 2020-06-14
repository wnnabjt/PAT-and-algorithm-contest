#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
bool vis[maxn];
int prime_list[maxn], cnt;

void init() {
    for(int i = 2; i < maxn; i ++) {
        if(!vis[i]) {
            prime_list[cnt ++] = i;
        }
        for(int j = 0; j < cnt; j ++) {
            if(i * prime_list[j] > maxn) break;
            vis[i * prime_list[j]] = true;
            if(i % prime_list[j] == 0) break;
        }
    }
}

bool _hash[maxn];

int main() {
    init();
    int n, prime, val;
    scanf("%d %d", &prime, &n);
    for(int i = 0; i < maxn; i ++) {
        if(prime_list[i] >= prime) {
            prime = prime_list[i];
            break;
        }
    }
    bool flag;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &val);
        flag = false;
        for(int j = 0; j < prime; j ++) {
            if(!_hash[(j * j + val) % prime]) {
                _hash[(j * j + val) % prime] = true;
                printf("%d%c", (j * j + val) % prime, i == n - 1 ? '\n' : ' ');
                flag = true;
                break;
            }
        }
        if(!flag) printf("-%c", i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
