#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace std;

map <string, vector <int> > mp;

const int max_len = 50 + 5;
char database[max_len], temp[max_len];
int len;
int lists;

int num[14] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int intervel[10] = {0, 1, 2, 4, 7, 15};//艾浩宾斯记忆法的记忆周期
const int maxn = 6;

int mouth, day;
char c;

int main() {
    FILE *fp;
    if((fp = fopen("data_in.txt", "r")) == NULL) {
        perror("fail to read");
        exit(1);
    }
    while(fgets(database, max_len, fp) != NULL) {
        stringstream ss, ss1;
        ss << database;
        ss1 << database;
        ss >> database;
        ss >> lists;
        ss.clear();
        ss1 >> mouth;
        ss1 >> c;
        ss1 >> day;
        ss1.clear();
        for(int i = 0; i < maxn; i ++) {
            int mouths = mouth, days = day;
            if(day + intervel[i] > num[mouth]) {
                days = day + intervel[i] - num[mouth];
                mouths ++;
                if(mouths > 12) mouths = 1;
            } else days = day + intervel[i];
            stringstream sstemp;
            if(mouths < 10) sstemp << 0;
            sstemp << mouths << c;
            if(days < 10) sstemp << 0;
            sstemp << days;
            sstemp.clear();
            sstemp >> temp;
            mp[temp].push_back(lists);
        }
    }
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    int now_mouth = 1 + p -> tm_mon, now_day = p -> tm_mday;
    stringstream sss;
    if(now_mouth < 10) sss << 0;
    sss << now_mouth << c;
    if(now_day < 10) sss << 0;
    sss << now_day;
    sss >> temp;
    sss.clear();
    cout << "Today is  " << temp << endl << "your job is :" << endl;
    for(int i = 0; i < mp[temp].size(); i ++) {
        cout << mp[temp][i] << " ";
    }
    cout << endl << "Then, i will print all of your job list" << endl;
    map <string, vector <int> > :: iterator i;
    for(i = mp.begin(); i != mp.end(); i ++) {
        // if(i -> first < temp) continue;
        cout << i -> first << ':' << endl;
        for(int j = 0; j < i -> second.size(); j ++) {
            cout << i -> second[j] << ' ';
        }
        cout << endl;
    }
    return 0;   
}