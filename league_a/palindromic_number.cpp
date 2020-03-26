#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

string n;
int k;

bool is_palindromic(string s) {
    int len = s.size();
    for(int i = 0; i <= len / 2; i ++) {
        if(s[i] != s[len - i - 1]) return false;
    }
    return true;
}

string _add(string s1, string s2) {
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    //cout << s1 << ' ' << s2 << endl;
    char c1 = '0', c2 = '0';
    for(int i = 0; i < s1.size(); i ++) {
        c1 = (c2 + s1[i] + s2[i] - 3 * '0') % 10 + '0';
        c2 = (s1[i] + s2[i] + c2 - 3 * '0') / 10 + '0';
        s1[i] = c1;
    }
    if(c2 != '0') s1 += c2;
    reverse(s1.begin(), s1.end());
    //cout << s1 << endl;
    return s1;
}

int main() {
    int cnt;
    while(cin >> n >> k) {
        cnt = 0;
        if(is_palindromic(n)) {
            cout << n << endl << cnt << endl;
            continue;
        }
        while(cnt < k) {
            string s1 = n;
            reverse(s1.begin(), s1.end());
            n = _add(n, s1);
            cnt ++;
            if(is_palindromic(n)) break;
        }
        cout << n << endl << cnt << endl;
    }
    return 0;
}
