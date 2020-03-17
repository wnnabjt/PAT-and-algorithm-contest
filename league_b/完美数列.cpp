/*
    ����֮����������̰�ĵ���Ŀ���Ȱ����ִ�С��������Ȼ�����ÿ������i������ǰ���ҵ�һ����num
    ,num������k * num < i��������꣬Ȼ��i�������ȥnum����������Ǹ�����ƥ�䵽������С� ���Ӷ�O(nlgn)��
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
