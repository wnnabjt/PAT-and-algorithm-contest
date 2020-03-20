#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

const int maxn = 1000 + 5;

typedef pair<int, int> pii;

deque <pii> que[25];
int _add[25], ans[maxn], val[maxn];

int main() {
    int n, m, k, q, op, temp;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 0; i < k; i ++) {
        scanf("%d", &val[i]);
        if(i < n * m) {
            que[i % n].push_back(make_pair(i, val[i]));
        } else {
            for(int j = 0; j < n; j ++) {
                _add[j] += que[j].front().second;
            }
            temp = min_element(_add, _add + n) - _add;
            for(int j = 0; j < n; j ++) {
                if(_add[j] == _add[temp] && j < temp) {
                    temp = j;
                    break;
                }
            }
            for(int j = 0; j < n; j ++) {
                if(j != temp) _add[j] -= que[j].front().second;
            }
            ans[que[temp].front().first] = _add[temp] - val[que[temp].front().first];
            que[temp].push_back(make_pair(i, val[i]));
            que[temp].pop_front();
        }
    }
    for(int i = 0; i < n; i ++) {
        while(!que[i].empty()) {
            ans[que[i].front().first] = _add[i];
            _add[i] += que[i].front().second;
            que[i].pop_front();
        }
    }
    while(q --) {
        scanf("%d", &op);
        if(ans[op - 1] < 540 && op <= k)
            printf("%02d:%02d\n", 8 + (ans[op - 1] + val[op - 1]) / 60, (ans[op - 1] + val[op - 1]) % 60);
        else printf("Sorry\n");
    }
    return 0;
}