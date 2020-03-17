#include <iostream>
using namespace std;

const int maxn = 100000 + 5;

int val[maxn];
int main() {
    int n;
    while(cin >> n) {
        bool flag = false;
        for(int i = 0; i < n; i ++) {
            cin >> val[i];
            if(val[i] == 0) flag = true;
        }
        int sum = 0, b = 0, e = 0, ans = 0, pre = 0;
        for(int i = 0; i < n; i ++) {
            sum += val[i];
            if(sum > ans) {
                ans = sum;
                e = i;
                b = pre;
            } else if(sum < 0) {
                sum = 0;
                pre = i + 1;
            }
        }
        if(ans == 0 && !flag) b = 0, e = n - 1;
        else if(ans == 0 && flag) {// 注意题意，题目说全是负数答案从左到右，但有负数有零的情况下，还是要输出零的。
            cout << "0 0 0" << endl;
            continue;
        }
        cout << ans << ' ' << val[b] << ' ' << val[e] << endl;
    }
    return 0;
}
