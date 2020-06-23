#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5;

struct Record {
    char plate[10];
    int time, flag;
} records[maxn];

bool cmp(Record a, Record b) {
    if(strcmp(a.plate, b.plate)) {
        return strcmp(a.plate, b.plate) < 0;
    } else {
        return a.time < b.time;
    }
}

bool cmp1(Record a, Record b) {
    return a.time < b.time;
}

map <string, int> mp;

vector <Record> vec;

int Max;

int main() {
    int n, k, h, m, s;
    char status[5];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i ++) {
        scanf("%s %d:%d:%d %s", records[i].plate, &h, &m, &s, status);
        records[i].flag = !strcmp(status, "in") ? 1 : -1;
        records[i].time = 3600 * h + 60 * m + s;
    }
    sort(records, records + n, cmp);
    for(int i = 0; i < n - 1; i ++) {
        if(!strcmp(records[i].plate, records[i + 1].plate) && records[i].flag == 1 && records[i + 1].flag == -1) {
            mp[records[i].plate] += records[i + 1].time - records[i].time;
            vec.push_back(records[i]);
            vec.push_back(records[i + 1]);
            Max = max(Max, mp[records[i].plate]);
        }
    }
    sort(vec.begin(), vec.end(), cmp1);
    vector <int> num(n);
    for(int i = 0; i < vec.size(); i ++) {
        if(i == 0) num[i] += vec[i].flag;
        else num[i] = num[i - 1] + vec[i].flag;
    }
    int idx = 0;
    for(int i = 0; i < k; i ++) {
        scanf("%d:%d:%d", &h, &m, &s);
        int time = h * 3600 + m * 60 + s;
        int j;
        for(j = idx; j < vec.size(); j ++) {
            if(vec[j].time > time) {
                printf("%d\n", num[j - 1]);
                break;
            } else if(j == vec.size() - 1) {
                printf("%d\n", num[j]);
            }
        }
        idx = j;
    }
    map <string, int> :: iterator i;
    for(i = mp.begin(); i != mp.end(); i ++) {
        if(i -> second == Max) {
            printf("%s ", i -> first.c_str());
        }
    }
    printf("%02d:%02d:%02d\n", Max / 3600, (Max % 3600) / 60,(Max % 3600) % 60);
    return 0;
}