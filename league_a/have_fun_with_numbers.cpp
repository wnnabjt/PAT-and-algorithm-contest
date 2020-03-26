#include <iostream>
#include <string>
using namespace std;

int double_s[30];

int vis[10];

int main() {
    string s;
    cin >> s;
    for(int i = s.size() - 1; i >= 0; i --) {
        double_s[i] = ((s[i] - '0') * 2) / 10;
        double_s[i + 1] += ((s[i] - '0') * 2) % 10;
        vis[s[i] - '0'] ++;
    }
    bool flag = false;
    for(int i = 1; i <= s.size(); i ++) if(-- vis[double_s[i]]< 0) flag = true;

    if(double_s[0] != 0 && -- vis[double_s[0]] < 0) flag = true;

    if(flag) cout << "No" << endl;
    else cout << "Yes" << endl;

    if(double_s[0] != 0) cout << double_s[0];
    for(int i = 1; i <= s.size(); i ++) {
        cout << double_s[i];
    }
    cout << endl;
    return 0;
}
