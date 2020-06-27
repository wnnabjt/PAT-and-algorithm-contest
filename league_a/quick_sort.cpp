#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5, inf = 1e9 + 5;
int val[maxn], _min[maxn], _max[maxn];

vector <int> ans;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &val[i]);
    }
    memset(_max, 0, sizeof _max);
    memset(_min, inf, sizeof _min);
    _max[0] = val[0];
    for(int i = 1; i < n; i ++) {
        _max[i] = _max[i - 1];
        if(val[i] > _max[i - 1]) {
            _max[i] = val[i];
        }
    }
    _min[n - 1] = val[n - 1];
    for(int i = n - 2; i >= 0; i --) {
        _min[i] = _min[i + 1];
        if(val[i] < _min[i + 1]) {
            _min[i] = val[i];
        }
    }
    for(int i = 0; i < n; i ++) {
        if(_max[i] <= val[i] && _min[i] >= val[i]) {
            ans.push_back(val[i]);
        }
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i ++) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}