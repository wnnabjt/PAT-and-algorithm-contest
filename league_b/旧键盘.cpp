#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

set <char> c1, c2;
map <char, bool> mp;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i ++) {
        if(s1[i] >= 'a' && s1[i] <= 'z') s1[i] += 'A' - 'a';
        c1.insert(s1[i]);
    }
    for(int i = 0; i < s2.size(); i ++) {
        if(s2[i] >= 'a' && s2[i] <= 'z') s2[i] += 'A' - 'a';
        c2.insert(s2[i]);
    }
    set <char> :: iterator j;
    for(int i = 0; i < s1.size(); i ++) {
        bool flag = true;
        for(j = c2.begin(); j != c2.end(); j ++) {
            if(s1[i] == *j) {
                flag = false;
                break;
            }
        }
        if(flag && !mp[s1[i]]) {
            cout << s1[i];
            mp[s1[i]] = true;
        }
    }
    cout << endl;
    return 0;
}
