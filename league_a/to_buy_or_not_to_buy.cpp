#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int maxn = 200 + 5;

int num[maxn];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s2.size(); i ++) {
        num[s2[i]] --;
    }
    for(int i = 0; i < s1.size(); i ++) {
        num[s1[i]] ++;
    }
    int excessive = 0, lack = 0;
    bool flag = true;
    for(int i = 0; i < maxn; i ++) {
        if(num[i] < 0) {
            flag = false;
            lack += (-num[i]);
        }
        if(flag) excessive +=num[i];
    }
    if(flag) {
        printf("Yes %d\n", excessive);
    } else {
        printf("No %d\n", lack);
    }
    return 0;
}