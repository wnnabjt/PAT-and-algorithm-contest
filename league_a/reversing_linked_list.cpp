#include <cstdio>
using namespace std;

const int maxn = 1e6 + 5, maxm = 1e5 + 5;

struct Linked {
    int pre, next, data;
} lists[maxn];
int val[maxm], cnt;

int main() {
    int head, n, k, u, v, data;
    scanf("%d %d %d", &head, &n, &k);
    for(int i = 0; i < n; i ++) {
        scanf("%d %d %d", &u, &data, &v);
        lists[u].next = v;
        lists[v].pre = u;
        lists[u].data = data;
        if(u == head) lists[u].pre = -1;
    }
    while(~head) {
        Linked temp = lists[head];
        val[++ cnt] = head;
        head = temp.next;
    }
    if(cnt >= k) {
        for(int i = 1; i <= cnt / k; i ++) {
            for(int j = i * k; j > (i - 1) * k + 1; j --) {
                Linked temp = lists[val[j]];
                printf("%05d %d %05d\n", val[j], temp.data,temp.pre);
            }
            Linked temp = lists[val[k * (i - 1) + 1]];
            if(i < cnt / k) printf("%05d %d %05d\n", val[k * (i - 1) + 1], temp.data, val[k * (i + 1)]);
            else {
                if(cnt % k) {
                    printf("%05d %d %05d\n", val[k * (i - 1) + 1], temp.data, val[k * i + 1]);
                    int flag = (cnt / k) * k;
                    for(int j = 1; j < cnt % k; j ++) {
                        Linked temp = lists[val[flag + j]];
                        printf("%05d %d %05d\n", val[flag + j], temp.data, temp.next);
                    }
                    printf("%05d %d -1\n", val[flag + cnt % k], lists[val[flag + cnt % k]].data);
                } else {
                    printf("%05d %d -1\n", val[k * (i - 1) + 1], temp.data);
                }
            }
        }
    } else {
        for(int i = 1; i < cnt; i ++) {
            printf("%05d %d %05d\n", val[i], lists[val[i]].data, lists[val[i]].next);
        }
        printf("%05d %d -1\n", val[cnt], lists[val[cnt]].data);
    }
    return 0;
}