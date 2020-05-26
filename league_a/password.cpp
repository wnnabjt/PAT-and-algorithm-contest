#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int maxn = 1000 + 5;

struct Peo {
    string info, password;
    bool vis;
} peos[maxn];

map <char, char> mp;

bool vis[200];

int main() {
    mp['1'] = '@';
    mp['0'] = '%';
    mp['l'] = 'L';
    mp['O'] = 'o';
    vis['1'] = true;
    vis['0'] = true;
    vis['l'] = true;
    vis['O'] = true;
    int n, num = 0;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> peos[i].info >> peos[i].password;
        peos[i].vis = false;
    }
    bool flag;
    for(int i = 0; i < n; i ++) {
        flag = false;
        for(int j = 0; j < peos[i].password.size(); j ++) {
            if(vis[peos[i].password[j]]) {
                peos[i].password[j] = mp[peos[i].password[j]];
                peos[i].vis = true;
                flag = true;
            }
        }
        if(flag) num ++;
    }
    if(!num) {
        if(n == 1) cout << "There is 1 account and no account is modified" << endl;
        else cout << "There are " << n << " accounts and no account is modified" << endl;
    } else {
        cout << num << endl;
        for(int i = 0; i < n; i ++) {
            if(peos[i].vis) {
                cout << peos[i].info << ' ' << peos[i].password << endl;
            }
        }
    }
    return 0;
}