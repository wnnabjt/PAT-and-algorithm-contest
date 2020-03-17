#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int cmp(char c1, char c2) {
    if(c1 == c2) {
        return 0;
    } else if(c1 == 'C') {
        if(c2 == 'B') return -1;
        else return 1;
    } else if(c1 == 'B') {
        if(c2 == 'J') return -1;
        else return 1;
    } else if(c1 == 'J') {
        if(c2 == 'C') return -1;
        else return 1;
    }
}

int J1[3], J2[3];//分别用来存放甲胜负情况和甲获胜的手势的次数
int Y1[3], Y2[3];//类似上述甲
map<char, int> mp;

int main() {
    int n, flag;
    char c1, c2;
    cin >> n;
    mp['B'] = 0;
    mp['C'] = 1;
    mp['J'] = 2;
    while(n --) {
        cin >> c1 >> c2;
        flag = cmp(c1, c2);
        if(flag == 0) {
            J1[1] ++, Y1[1] ++;
        } else if(flag == 1) {
            J1[0] ++;
            Y1[2] ++;
            J2[mp[c1]] ++;
        } else {
            J1[2] ++;
            Y1[0] ++;
            Y2[mp[c2]] ++;
        }
    }
    for(int i = 0; i < 3; i ++) {
        if(i) cout << ' ';
        cout << J1[i];
    }
    cout << endl;
    for(int i = 0; i < 3; i ++) {
        if(i) cout << ' ';
        cout << Y1[i];
    }
    cout << endl;
    if(J2[0] == *max_element(J2, J2 + 3)) cout << 'B';
    else if(J2[1] == *max_element(J2, J2 + 3)) cout << 'C';
    else cout << 'J';
    cout << ' ';
    if(Y2[0] == *max_element(Y2, Y2 + 3)) cout << 'B';
    else if(Y2[1] == *max_element(Y2, Y2 + 3)) cout << 'C';
    else cout << 'J';
    return 0;
}
