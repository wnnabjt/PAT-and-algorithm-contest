#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int sum[10];

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i ++) {
        sum[s[i] - '0'] ++;
    }
    for(int i = 0; i < 10; i ++) {
        if(sum[i]) printf("%d:%d\n", i, sum[i]);
    }
    return 0;
}
