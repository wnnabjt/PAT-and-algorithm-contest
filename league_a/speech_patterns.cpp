#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

map <string, int> mp;

vector <string> ans;

int main() {
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i ++) {
        if(isdigit(s[i]) || isalpha(s[i])) {
            if(isupper(s[i])) s[i] = s[i] - 'A' + 'a';
            continue;
        }
        s[i] = ' ';
    }
    stringstream ss;
    ss << s;
    string temp;
    while(ss >> temp) {
        mp[temp] ++;
    }
    int Max = 0;
    for(auto i = mp.begin(); i != mp.end(); i ++) {
        if(i -> second > Max) Max = i -> second;
    }
    for(auto i = mp.begin(); i != mp.end(); i ++) {
        if(i -> second == Max) ans.push_back(i -> first);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << ' ' << Max << endl;
    return 0;
}