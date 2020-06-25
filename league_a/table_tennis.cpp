#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct A {
    string arr, serve;
    int wait_time;
};

struct B {
    int arr_time, last_time;
};

map <string, B> mp, mp_vip;
vector <int> vec(100 + 5), num(100 + 5);
vector <bool> table_vip(100 + 5);
vector <A> ans;

int get_time(string time) {
    char c;
    int h, m, s;
    stringstream ss;
    ss << time;
    ss >> h >> c >> m >> c >> s;
    return h * 3600 + m * 60 + s;
}

string get_serve(int time) {
    string ss;
    int h, m, s;
    h = time / 3600;
    m = (time % 3600) / 60;
    s = (time % 3600) % 60;
    if(h < 10) ss += "0";
    ss += to_string(h);
    ss += ":";
    if(m < 10) ss += "0";
    ss += to_string(m);
    ss += ":";
    if(s < 10) ss += "0";
    ss += to_string(s);
    return ss;
}

int main() {
    string time;
    int n, k, m, last_time, is_vip, arr_time;
    cin >> n;
    while(n --) {
        cin >> time >> last_time >> is_vip;
        arr_time = get_time(time);
        if(last_time > 120) last_time = 120;
        mp[time] = B{arr_time, last_time};
        if(is_vip) {
            mp_vip[time] = B{arr_time, last_time};
        }
    }
    cin >> k >> m;
    for(int i = 1; i <= k; i ++) {
        vec[i] = 8 * 3600;
        table_vip[i] = false;
        num[i] = 0;
    }
    while(m --) {
        cin >> is_vip;
        table_vip[is_vip] = true;
    }
    map <string, B> :: iterator it;
    while(true) {
        if(mp.empty() || mp.begin() -> first >= "21:00:00") break;
        int min_time = *min_element(vec.begin() + 1, vec.begin() + k + 1), pos;
        for(int i = 1; i <= k; i ++) {
            if(vec[i] == min_time) {
                pos = i;
                break;
            }
        }
        if(vec[pos] >= 21 * 3600) break;
        string serve;
        if(table_vip[pos] && !mp_vip.empty() && mp_vip.begin() -> second.arr_time <= vec[pos]) {
            num[pos] ++;
            serve = get_serve(vec[pos]);
            ans.push_back(A{mp_vip.begin() -> first, serve, (vec[pos] - mp_vip.begin() -> second.arr_time + 30) / 60});
            vec[pos] += 60 * mp_vip.begin() -> second.last_time;
            it = mp.find(mp_vip.begin() -> first);
            if(it != mp.end()) {
                mp.erase(it);
            }
            it = mp_vip.find(mp_vip.begin() -> first);
            mp_vip.erase(it);
        } else {
            num[pos] ++;
            serve = get_serve(max(vec[pos], mp.begin() -> second.arr_time));
            ans.push_back(A{mp.begin() -> first, serve, vec[pos] > mp.begin() -> second.arr_time ? ((vec[pos] - mp.begin() -> second.arr_time) + 30) / 60 : 0 });
            vec[pos] = max(vec[pos], mp.begin() -> second.arr_time) + 60 * mp.begin() -> second.last_time;
            it = mp.find(mp.begin() -> first);
            mp.erase(it);
            it = mp_vip.find(mp.begin() -> first);
            if(it != mp_vip.end()) {
                mp_vip.erase(it);
            }
        }
    }
    for(int i = 0; i < ans.size(); i ++) {
        cout << ans[i].arr << ' ' << ans[i].serve << ' ' << ans[i].wait_time << endl;
    }
    for(int i = 1; i <= k; i ++) {
        if(i ^ 1) cout << ' ';
        cout << num[i];
    }
    cout << endl;
    return 0;
}