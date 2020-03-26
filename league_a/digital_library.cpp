#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

map <string, set <string> > mp;

int main() {
    string n1;
    getline(cin, n1);
    int n = stoi(n1);
    string id, s;
    while(n --) {
        getline(cin, id);
        getline(cin, s); // name
        mp[s].insert(id);
        getline(cin, s); // author
        mp[s].insert(id);
        getline(cin, s); // key
        stringstream ss;
        ss << s;
        while(ss >> s) {
            mp[s].insert(id);
            //cout << s << endl;
        }
        getline(cin, s); // publisher
        mp[s].insert(id);
        getline(cin, s); // years
        mp[s].insert(id);
    }
    getline(cin, n1);
    int m = stoi(n1);
    string s1, s2;
    while(m --) {
        getline(cin, s1, ' ');
        getline(cin, s2);
        cout << s1 << ' ' << s2 << endl;
        set <string> :: iterator i;
        if(mp[s2].size() > 0)
            for(i = mp[s2].begin(); i != mp[s2].end(); i ++) cout << *i << endl;
        else cout << "Not Found" << endl;
    }
    return 0;
}
