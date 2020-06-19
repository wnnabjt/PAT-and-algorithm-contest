#include <iostream>
#include <string>
using namespace std;

const int maxn = 100000 + 5;

int p[maxn], t[maxn];

const int mod = 1000000007;

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == 'P') {
            if(i == 0) p[i] = 1;
            else p[i] = p[i - 1] + 1;
        } else p[i] = p[i - 1];
    }
    for(int i = s.size() - 1; i >= 0; i --) {
        if(s[i] == 'T') {
            if(i == s.size() - 1) t[i] = 1;
            else t[i] = t[i + 1] + 1;
        } else t[i] = t[i + 1];
    }
    int tot = 0;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == 'A') {
            tot = (tot + p[i] * t[i] % mod) % mod;
        }
    }
    printf("%d\n", tot);
    return 0;
}