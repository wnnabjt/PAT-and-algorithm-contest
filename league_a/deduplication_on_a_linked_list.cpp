#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

const int maxn = 1e4 + 5, maxm = 1e6 + 5;
bool vis[maxn];
int val[maxm];

map <string, string> mp, mp1;

int main() {
    string head;
    int n;
    cin >> head >> n;
    string u, v;
    int num;
    while(n --) {
        cin >> u >> num >> v; 
        mp[u] = v;
        mp1[v] = u;
        val[stoi(u)] = num;
    }
    string de = "-1", be, temp = head;
    while(head != "-1") {
        if(!vis[abs(val[stoi(head)])]) {
            vis[abs(val[stoi(head)])] = true;
            head = mp[head];
        } else {
            string temp1 = head;
            while(vis[abs(val[stoi(head)]) {

            }
            mp[mp1[head]] = mp[head];
            if(de != "-1") {
                mp[de] = head;
            } else {
                be = head;
            }
            de = head;
            head = mp[head];
        }
    }
    mp[de] = "-1";
    while(temp != "-1") {
        cout << temp << ' ' << val[stoi(temp)] << ' ' << mp[temp] << endl;
        temp = mp[temp];
    }
    while(be != "-1") {
        cout << be << ' ' << val[stoi(be)] << ' ' << mp[be] << endl;
        be = mp[be];
    }
    return 0;
}