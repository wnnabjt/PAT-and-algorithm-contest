#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Stu {
    string id;
    int data;
};

typedef pair <int, char> pic;

map <string, pic> mp;

const int inf = 2000 + 5;

vector <Stu> a, c, m1, e;

bool cmp(Stu A, Stu B) {
    return A.data > B.data;
}

int main() {
    int n, m;
    cin >> n >> m;
    string id;
    int _a, _c, _m, _e;
    for (int i = 0; i < n; i ++) {
        cin >> id >> _c >> _m >> _e;
        mp[id].first = inf;
        _a = (_e + _c + _m) / 3;
        a.push_back(Stu{id, _a});
        c.push_back(Stu{id, _c});
        m1.push_back(Stu{id, _m});
        e.push_back(Stu{id, _e});
    }
    sort(a.begin(), a.end(), cmp);
    sort(c.begin(), c.end(), cmp);
    sort(m1.begin(), m1.end(), cmp);
    sort(e.begin(), e.end(), cmp);
    vector <Stu>::iterator i;
    bool flag;
    int cnt = 1;
    for (i = a.begin(); i != a.end(); i ++) {
        flag = false;
        if(i != a.begin()) {
            if(i -> data == (i - 1) -> data) {
                cnt --;
                flag = true;
            }
        }
        if(mp[i -> id].first > cnt) {
            mp[i -> id] = make_pair(cnt, 'A');
        }
        if(flag) cnt ++;
        cnt ++;
    }
    cnt = 1;
    for(i = c.begin(); i != c.end(); i ++) {
        flag = false;
        if(i != c.begin()) {
            if(i -> data == (i - 1) -> data) {
                cnt --;
                flag = true;
            }
        }
        if(mp[i -> id].first > cnt) {
            mp[i -> id] = make_pair(cnt, 'C');
        }
        if(flag) cnt ++;
        cnt ++;
    }
    cnt = 1;
    for(i = m1.begin(); i != m1.end(); i ++) {
        flag = false;
        if(i != m1.begin()) {
            if(i -> data == (i - 1) -> data) {
                cnt --;
                flag = true;
            }
        }
        if(mp[i -> id].first > cnt) {
            mp[i -> id] = make_pair(cnt, 'M');
        }
        if(flag) cnt ++;
        cnt ++;
    }
    cnt = 1;
    for(i = e.begin(); i != e.end(); i ++) {
        flag = false;
        if(i != e.begin()) {
            if(i -> data == (i - 1) -> data) {
                cnt --;
                flag = true;
            }
        }
        if(mp[i -> id].first > cnt) {
            mp[i -> id] = make_pair(cnt, 'E');
        }
        if(flag) cnt ++;
        cnt ++;
    }
    while(m --) {
        cin >> id;
        if(mp[id].first)
            cout << mp[id].first << ' ' << mp[id].second << endl;
        else cout << "N/A" << endl;
    }
   return 0;
}