#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector <ll> nc, np;

int main() {
    int n, m;
    cin >> n;
    ll temp;
    for(int i = 0; i < n; i ++) {
        cin >> temp;
        nc.push_back(temp);
    }
    cin >> m;
    for(int i = 0; i < m; i ++) {
        cin >> temp;
        np.push_back(temp);
    }
    ll sum = 0;
    sort(nc.begin(), nc.end());
    sort(np.begin(), np.end());
    for(int i = n - 1; i >= 0; i --) {
        if(m - n + i < 0) break;
        if(nc[i] > 0 && np[m - n + i] > 0) {
            sum += nc[i] * np[m - n + i];
        } else break;
    }
    for(int i = 0; i < n; i ++) {
        if(nc[i] < 0 && np[i] < 0) {
            sum += nc[i] * np[i];
        } else break;
    }
    cout << sum << endl;
    return 0;
}