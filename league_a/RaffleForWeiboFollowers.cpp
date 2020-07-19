#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, bool> mp;

vector <string> vec(1000 + 5);

int main() {
    int n, s, b;
    cin >> n >> s >> b;
    for(int i = 1; i <= n; i ++) {
        cin >> vec[i];
    }
    bool flag = false;
    while(b <= n) {
        if(!mp[vec[b]]) {
            flag = true;
            cout << vec[b] << endl;
            mp[vec[b]] = true;
            b += s;
        } else b ++;
    }
    if(!flag) {
        cout << "Keep going..." << endl;
    }
    return 0;
}