#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map <string, int> mp;

string base[15] = {
    "tret",
    "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};
string upper[15] = {
    "000",
    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};

vector <string> ans1;
vector <int> ans2;

int main() {
    int n;
    mp["tret"] = 0;
    for(int i = 1; i <= 12; i ++) {
        mp[base[i]] = i;
        mp[upper[i]] = i + 12;
    }
    string s, temp;
    cin >> n;
    getchar();
    while(n --) {
        getline(cin, s);
        if(isdigit(s[0])) {
            ans2.clear();
            int num = 0;
            for(int i = 0; i < s.size(); i ++) {
                num = num * 10 + s[i] - '0';
            }
            while(num) {
                ans2.push_back(num % 13);
                num /= 13;
            }
            if(stoi(s) > 12) {
                cout << upper[ans2[1]];
                if(ans2.size() > 1 && ans2[0] > 0)cout << ' ' << base[ans2[0]];
                cout << endl;
            } else if(stoi(s) >= 1){
                cout << base[ans2[0]] << endl;
            } else cout << "tret" << endl;
        } else {
            stringstream ss;
            ss << s;
            int num = 0;
            while(ss >> temp) {
                if(mp[temp] > 12) {
                    num += 13 * (mp[temp] - 12);
                } else num += mp[temp];
            }
            ss.clear();
            cout << num << endl;
        }
    }
    return 0;
}