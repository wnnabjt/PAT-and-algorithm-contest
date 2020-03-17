#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 20 + 5;
int a[maxn];

int main() {
    int ans, k;// k：第一层的符号个数
    for(int i = 1; i < maxn; i ++) {
        a[i] = 2 * i * i - 1;
    }
    int n;
    char c;
    cin >> n >> c;
    for(int i = 1; i < maxn; i ++) {
        if(a[i] <= n) {
            ans = n - a[i];
            k = 2 * i - 1;
        } else break;
    }
    int temp = k;
    for(int i = 0; i <= k / 2; i ++) {
        for(int j = 0; j < i; j ++) cout << ' ';
        for(int j = 0; j < temp; j ++) cout << c;
        for(int j = 0; j < i; j ++) cout << ' ';
        cout << endl;
        temp -= 2;
    }
    temp = 3;
    for(int i = k / 2 - 1; i >= 0; i --) {
        for(int j = 0; j < i; j ++) cout << ' ';
        for(int j = 0; j < temp; j ++) cout << c;
        for(int j = 0; j < i; j ++) cout << ' ';
        cout << endl;
        temp += 2;
    }
    cout << ans << endl;
     return 0;
}
