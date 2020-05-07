#include <iostream>
#include <cstdio>
using namespace std;

int a[3];

char ans[50] = "0123456789ABC";

void find_13_base(int num) {
    char c[3] = "::";
    int pos = 1;
    while(num) {
        c[pos --] = ans[num % 13];
        num /= 13;
    }
    if(c[0] == ':') c[0] = '0';
    cout << c;
}

int main() {
    for(int i = 0; i < 3; i ++) cin >> a[i];
    cout << '#';
    for(int i = 0; i < 3; i ++) {
        if(a[i])
            find_13_base(a[i]);
        else cout << "00";
    }
    cout << endl;
    return 0;
}