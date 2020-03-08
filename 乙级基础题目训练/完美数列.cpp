/*
    读题之后发现类似于贪心的题目，先把数字从小到大排序，然后对于每个数字i，在他前面找到一个数num
    ,num是满足k * num < i的最大坐标，然后i的坐标减去num的坐标就是那个数字匹配到的最长数列。 复杂度O(nlgn)。
    */
#include <iostream>
#include <algorithm>
#define mid ((l + r) >> 1)
using namespace std;

const int maxn = 1e5 + 5;

int n, k, ans;

int num[maxn];

int _find(int l, int r, int x) {
    while(l <= r) {
        if(k * num[mid] >= x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
        cin >> num[i];
    }
    sort(num, num + n);
    for(int i = n - 1; i > 0; i --) {
        ans = max(ans, i - _find(0, i, num[i]));
    }
    cout << ans << endl;
    return 0;
}
