#include <iostream>
using namespace std;

const int maxn = 100000 + 5;

int sum[maxn << 1];

int main() {
    int n, temp;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    for(int i = 1; i <= n; i ++) {
        sum[i + n] = sum[i] + sum[n];
    }
    int m, l, r;
    cin >> m;
    while(m --) {
        cin >> l >> r;
        if(l > r) swap(l, r);
        cout << min(sum[r - 1] - sum[l - 1], sum[n + l - 1] - sum[r - 1]) << endl;
    }
    return 0;
}