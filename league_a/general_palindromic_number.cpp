#include <iostream>
#include <cstring>
using namespace std;

int a[100000 + 5];

int main() {
    int n, cnt = 0;
    int base;
    cin >> n >> base;
    while(n) {
        a[cnt ++] = n % base;
        n /= base;
    }
    bool flag = true;
    for(int i = 0; i <= cnt / 2; i ++) {
        if(a[i] != a[cnt - i - 1]) flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    for(int i = cnt - 1; i >= 0; i --) {
        if(i != cnt - 1) cout << ' ';
        cout << a[i];
    }
    cout << endl;
    return 0;
}
