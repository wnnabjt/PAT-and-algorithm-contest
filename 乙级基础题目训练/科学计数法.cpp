#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;
    int pos;
    for(int i = s.length(); i > 0; i --) {
        if(s[i] == 'E') {
            pos = i;
            break;
        }
    }
    bool flag;
    if(s[pos + 1] == '+') flag = true;
    else flag = false;
    int pix = 0;
    for(int i = pos + 2; i < s.length(); i ++) pix = pix * 10 + s[i] - '0';
    if(flag) {
        for(int i = 0; i < pos; i ++) {
            if(s[i] == '+') continue;
            if(i != 2) {
                cout << s[i];
            }
            if(i == 2 + pix) cout << '.';
        }
        pix = pix - (pos - 3);
        while(pix -- > 0) cout << 0;
    } else {
        if(s[0] == '-') cout << s[0];
        cout << "0.";
        while(-- pix > 0) cout << 0;
        for(int i = 0; i < pos; i ++)
            if(isdigit(s[i])) cout << s[i];
    }
    cout << endl;
    return 0;
}
