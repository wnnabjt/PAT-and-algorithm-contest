#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <string> vec;

int main() {
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> s;
        s += s;
        vec.push_back(s);
    }
    sort(vec.begin(), vec.end());
    string ans = "";
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < vec[i].size() / 2; j ++) {
            ans += vec[i][j];
        }
    }
    while(ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if(ans.size()) cout << ans << endl;
    else cout << '0' << endl;
    return 0;
}