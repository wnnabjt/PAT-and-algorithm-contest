#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

int _cost[30];

typedef pair <string, string> pss;

map <string, set <pss> > mp;


string on = "on-line", off = "off-line";

int get_num(char c1, char c2) {
    return (c1 - '0') * 10 + c2 - '0';
}

int last_time, total_amount, _val, _sum;

void get_time(string _on, string _off) {
    //Todo: 计算间隔时间，计算本次通话的费用
    int bd, bh, bm, ed, eh, em;
    bd = get_num(_on[3], _on[4]);
    bh = get_num(_on[6], _on[7]);
    bm = get_num(_on[9], _on[10]);
    ed = get_num(_off[3], _off[4]);
    eh = get_num(_off[6], _off[7]);
    em = get_num(_off[9], _off[10]);
    int n;
    last_time = (ed - bd) * 1440 + (eh - bh) * 60 + (em - bm);
    for(int i = 0; i < eh; i ++) _val += _cost[i] * 60;
    _val += _cost[eh] * em;
    for(int i = 0; i < bh; i ++) _val -= _cost[i] * 60;
    _val -= _cost[bh] * bm;
    if(ed > bd) {
        _val += (ed - bd) * _sum * 60;
    }
}

char *ans1, *ans2, *ans3;

int main() {
    for(int i = 0; i < 24; i ++) {
        cin >> _cost[i];
        _sum += _cost[i];
    }
    int k;
    cin >> k;
    string name, data, _status;
    while(k --) {
        cin >> name >> data >> _status;
        mp[name].insert(make_pair(data, _status));
    }
    bool flag, flag2;
    string _on, _off;
    map <string, set <pss> > :: iterator i;
    for(i = mp.begin(); i != mp.end(); i ++) {
        flag = false;
        flag2 = false;
        total_amount = 0;
        string s = (i -> second).begin() -> first;
        set <pss> :: iterator j;
        for(j = (i -> second).begin(); j != (i -> second).end(); j ++) {
            if(j -> second == on) {
                _on = j -> first;
                flag = true;
            } else if(j -> second == off && flag) {
                _val = 0;
                flag = false;
                _off = j -> first;
                get_time(_on, _off);
                total_amount += _val;
                ans1 = (char*)_on.data();
                ans2 = (char*)_off.data();
                ans3 = (char*)(i -> first).data();
                if(!flag2) printf("%s %c%c\n", ans3, s[0], s[1]);
                printf("%s %s %d $%.2f\n", ans1 + 3, ans2 + 3 , last_time, _val * 1.0 / 100);
                flag2 = true;
            }
        }
        if(flag2) printf("Total amount: $%.2f\n", total_amount * 1.0 / 100);
    }
    return 0;
}